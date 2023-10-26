// Names: Olivia, Vuong, John
// main.cpp: case study of usecase
// Date: Oct 2023

#include <iostream>
#include "usecase.cpp"
#include "bst.cpp"
using namespace std;

int main()
{
    //main.cpp file edit
    string input_bin;
    cout << "Enter binary representation for conversion: " <<endl;
    cin >> input_bin;

    // read in file name and create the tree
    BST<string,string>* bst = create_bst<string,string>("binhex.txt");
    string res = convert<string, string>(bst, input_bin);
    cout << "hexidecimal representation of " << input_bin << " is " << res << endl;

    return 0;
}