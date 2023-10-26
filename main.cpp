#include <iostream>
#include "usecase.cpp"
#include "bst.cpp"
using namespace std;

int main()
{
    // BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
    // string bin1 = "111010100101";
    // string expected_hex1 = "EA5";

    // string hex1 = convert<string,string>(bst1, bin1);
    // delete bst1;

    // if(hex1!=expected_hex1) {
    //     cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
    // }

    // BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
    // string bin2 = "110101";
    // string expected_hex2 = "35";

    // string hex2 = convert<string,string>(bst2, bin2);
    // delete bst2;

    // if(hex2!=expected_hex2) {
    //     cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
    // }

    //main.cpp file edit
    string input_bin;
    cout << "Enter binary representation for conversion: " <<endl;
    cin >> input_bin;

    // read in file name and create the tree
    BST<string,string>* bst = create_bst<string,string>("binhex.txt");
    string res = convert<string, string>(bst, input_bin);
    cout << "exidecimal representation of " << input_bin << " is " << res << endl;

    return 0;
}