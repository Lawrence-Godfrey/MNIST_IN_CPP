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

    // converting types
    int total_amount {100};
    int total_number {8};
    double average {0.0};
    average = total_amount/total_number;  //12.5 becomes 12

    average = static_cast<double>(total_amount)/total_number; // average is 12.5.    static_cast better than (double), does more checks. 

    // initializing multiple vars
    int num1 {}, num2 {}, num3 {};


    //Equality and Bool
    bool check {false};

    cout<<boolalpha; //booleans will be diplayed as true/false, not 1/0

    check = (10==10);

    //switch statement 
    int selection {0};
    
    switch (selection)  
    {   
        case '0':                             // case 0 and 1 go to same statement
        case '1': selection =2; break;        // cases must be literals/constants 
        case '2': selection =3; break;
        case '3': 
        {
            int new_select {};                // since we're declaring a variable, need {}
            new_select = 3;
        }
        default: selection = 4;               //default is optional

    }

    //Conditional Operator 
    //(conditional_expression) ? expression_1 : expression_2 
    int a {1}, b {2};
    
    int result = (a<b) ? a:b;   //result = a

    cout << endl << ( (result>1) ? "More than 1" : "Less than 1") << endl; //prints "less than 1"

    //Loops 
    //For loop
    // for (initialization ; condition ; increment)

    for(int i {5}, j {5} ; i<=5 ; ++i, ++j)
    {
        j*=i;
    }



    return 0;
}