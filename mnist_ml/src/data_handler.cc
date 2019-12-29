#include "data_handler.hpp"
#include <iostream>


data_handler::data_handler()
{
    data_array = new std::vector<data *>;
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;
}

data_handler::~data_handler()
{

}

void data_handler::read_feature_vector(std::string path)
{
    uint32_t header [4];   // |Magic | Num Images | Rowsize | Colsize | 
    unsigned char bytes [4]; 
    FILE *f = fopen(path.c_str(),"r");
    if(f)
    {
        for(int i = 0; i < 4; i++)
        {
            if(fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        std::cout << "Done getting input file header.\n";

        int image_size = header[2]*header[3];

        for(int i = 0; i < header[1]; i++)
        {
            data *d = new data();
            uint8_t element[1];

            for(int j = 0; j< image_size; j++)
            {
                if (fread(element, sizeof(element), 1, f))
                {
                    d->data::append_to_feature_vector(element[0]);
                }
                else
                {
                    std::cout << "Error reading from File." << std::endl;
                    exit(1);
                }        
            }
            data_array -> push_back(d);
        }

        std::cout << "Successfully read and stored %lu feature vectors." << std::endl << data_array -> size();

    }
    else
    {
        std::cout << "could not find file" << std::endl;
        exit(1);
    }
}

void data_handler::read_feature_labels(std::string path)
{
    uint32_t header [2];   // |Magic | Num Images | Rowsize | Colsize | 
    unsigned char bytes [4]; 
    FILE *f = fopen(path.c_str(),"r");
    if(f)
    {
        for(int i = 0; i < 2; i++)
        {
            if(fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        std::cout << "Done getting label file header.\n";

        for(int i = 0; i < header[1]; i++)
        {
            uint8_t element[1];
            
            if (fread(element, sizeof(element), 1, f))
            {
                data_array->at(i)->data::set_label(element[0]);
            }
            else
            {
                std::cout << "Error reading from File." << std::endl;
                exit(1);
            }        
        }

        std::cout << "Successfully read and stored label." << std::endl << data_array -> size();

    }
    else
    {
        std::cout << "could not find file" << std::endl;
        exit(1);
    }
}

void data_handler::split_data()
{
    std::unordered_set<int> used_indexes;
    int train_size = data_array->size() * TRAIN_SET_PERCENT;
    int test_size = data_array->size() * TEST_SET_PERCENT;
    int valid_size = data_array->size() * VALIDATION_PERCENT;
    
    // Training data

    int count = 0; 
    while(count < train_size)
    {
        int rand_index = rand() % data_array -> size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            training_data -> push_back(data_array -> at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }

    }

     // Test data

    count = 0; 
    while(count < test_size)
    {
        int rand_index = rand() % data_array -> size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            test_data -> push_back(data_array -> at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }

    }

     // Validation data

    count = 0; 
    while(count < valid_size)
    {
        int rand_index = rand() % data_array -> size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            validation_data -> push_back(data_array -> at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }

    }

    std::cout << "Training Data Size: %lu " <<std::endl <<training_data->size() << 
                 "Test Data Size: %lu " <<std::endl << test_data->size() << 
                 "Validation Data Size %lu " << std::endl << validation_data->size();

}

void data_handler::count_classes()
{
    int count = 0;
    for(unsigned i = 0; i<data_array->size();i++)
    {
        if(class_map.find(data_array->at(i)->get_label()) == class_map.end())
        {
            class_map[data_array->at(i)->get_label()] = count;
            data_array -> at(i) -> set_enumeratured_label(count);
            count++;
        }
    }

    num_classes = count;
    std::cout << "Successfully Extracted %d Unique Classes. " << num_classes;
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes)
{
    return static_cast<uint32_t>((bytes[0] << 24) | 
                                 (bytes[1] << 16) | 
                                 (bytes[2] << 8) |
                                 (bytes[3]));
}

std::vector<data *> * data_handler::get_training_data()
{
    return training_data;
};
std::vector<data *> * data_handler::get_test_data()
{
    return test_data;
}
std::vector<data *> * data_handler::get_validation_data()
{
    return validation_data;
}


int main()
{
    data_handler *dh = new data_handler();
    dh -> read_feature_vector("./train-images-idx3-ubyte");
    dh -> read_feature_labels("./train-labels-idx1-ubyte");
    dh -> split_data();

}