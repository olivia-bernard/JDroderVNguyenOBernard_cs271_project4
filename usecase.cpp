// Names: Olivia, Vuong, John
// usecase.cpp: specific use case file to demonstrate functionality of BST
// Date: Oct 2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bst.h"

using namespace std;

// Function to create BST from CSV file
template <typename D, typename K>
BST<D, K>* create_bst(const string& fname) 
{
    BST<string, string>* bst = new BST<string, string>(); // Create new instance of a BST for binary-to-hex mapping
    ifstream file(fname); // open csv file

    if (!file.is_open())  // check if file was opened successfully (defensive programming!!)
    {
        cerr << "Error: Could not open the CSV file." << endl;
        return nullptr; // return nullptr in case of failure
    }

    string line;
    while (getline(file, line)) 
    {
        istringstream iss(line); // create string stream to parse each line from csv file
        string bin, hex; // variables for binary and hex values
        if (getline(iss, bin, ',') && getline(iss, hex, ',')) // get binary and hex values from csv line
        {
            bst->insert(bin, hex); // reverse order for binary-to-hex mapping
        }
    }

    file.close(); // close csv file
    return bst; // return populated bst
}

// Function to convert binary -> hexadecimal
template <typename D, typename K>
string convert(BST<D, K>* bst, string bin) 
{
    // pad binary string with leading zeros if length is not a multiple of 4
    int padding = 4 - (bin.length() % 4);
    if (padding < 4) 
    {
        bin = string(padding, '0') + bin;
    }

    string hex = "";
    for (size_t i = 0; i < bin.length(); i += 4) 
    {
        string sub_bin = bin.substr(i, 4); // extract 4 bit binary substring
        string sub_hex = bst->get(sub_bin); // get hex value from bst
        hex += sub_hex; // concatenate hex values
    }

    return hex; // return hex val
}

int main() 
{
    // Create a BST from the txt (csv) file
    BST<string, string>* bst = create_bst("binhex.txt");

    if (bst == nullptr) // check if bst creation worked (defensive programming!!)
    {
        return 1; // exit w/ error code
    }

    // Ask user for binary input
    string bin;
    cout << "Enter binary representation for conversion: ";
    cin >> bin;

    // convert binary to hexadecimal using BST
    string hex = convert(bst, bin);

    // Display result
    cout << "Hexadecimal representation of " << bin << " is " << hex << endl;

    delete bst;  // Clean up BST

    return 0;
}
