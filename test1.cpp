#include <iostream>
#include <climits>

using namespace std;

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

    return 0;
}