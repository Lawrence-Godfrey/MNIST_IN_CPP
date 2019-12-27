#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// constants 
const float pi {3.14};
#define pie 3.14; //legacy, don't use


int main()
{
    int favNum; 
    cout << "Enter your favourite number between 1 and 100" << endl;
    cin >> favNum;
    cout << "your favourite number is: " << favNum << endl;

    cout<< "Sizeof Info"<<endl
        << "--------------"<<endl
        << "char: "<< sizeof(char) << " bytes"<<endl
        << "int: " << sizeof(int) <<  " bytes"<<endl
        << "long long: " << sizeof(long long) << " bytes"<<endl;

    cout<< "Max and mins"<<endl
        << "--------------"<<endl
        << "Max int: " << INT_MAX <<endl
        << "Max char: "<< CHAR_MAX <<endl
        << "Min long long: " << LLONG_MIN << endl;

/*  escape characters:   
      \n newline   
      \r return
      \t tab
      \b backspace
      \' single quote   
      \" double quote
      \\ backslash
*/

//Arrays 
    int numbers [5] {1,2,3,4,5};
    int someNumbers [10] {3,4}; //the rest are initialized to 0

    const int setNum {5};
    double piLength [setNum] {0}; //init all to 0

    int anotherArray [] {2,5,67,3,56,3,56,43,3}; // size is set accordingly

    int enteredNumbers [5] {};
    // cin >> enteredNumbers[0];
    // cin >> enteredNumbers[1];
    // cin >> enteredNumbers[2];
    // cin >> enteredNumbers[3];
    // cin >> enteredNumbers[4];
    
    char vowels [] {'a','e','i','o','u'};

    //2D
    int twoDArray [][3] 
    {
        {1,43,53},
        {4,2,56},
        {1,465,2}
    };
   
   //Vectors

   vector <char> vowelsVect (5); 
   //OR
   vector <char> vowelsVect2 {'a','e','i','o','u'};

   vector <int> scores (10);

   vector <double> temperatures (365, 80.0); //(initial_size, initial_value_of_all_elements)
    

   cout<< temperatures.at(0)<<endl<< // at()  checks for out of bounds
          temperatures[0]<<endl;


    scores.push_back(85); // adds 85 to end of vector 
    scores.size(); //number of elements



    //2D VECTORS

    vector <vector<int>> movieRatings 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    cout<< movieRatings.at(0).at(1);

    movieRatings.push_back({13,14,15,16});


    return 0;
}