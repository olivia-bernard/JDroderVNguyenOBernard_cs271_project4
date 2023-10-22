#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T1, class T2>
class Node
{   
    template<class L1, class L2>
    friend class BTS;

    public:
    Node(T1 d, T2 k); //constructor
    T1 get_data();
    T2 get_key();


    private:
    T1 data;
    T2 key;
    Node<T1, T2>* left;
    Node<T1, T2>* right;
    Node<T1, T2>* p;

}

template <class T1, class T2> //T1: data, T2: key
class BTS
{
    public:
    BST(); //constructor
    ~BST(); //deconstructor
    void empty();
    void insert(T1 d, T2 k);
    T2 get(T2 k);
    void remove(T2 k);
    T1 max_data(BST<T1, T2> bst);
    T2 max_key(BST<T1, T2> bst);
    T1 min_data(BST<T1, T2> bst);
    T2 min_key(BST<T1, T2> bst);
    T2 successor(BST<T1, T2> bst);
    string in_order();

    private:
    Node<T1, T2>* root;
    BTS search(T2 k);
    void transplant(const Node* &u, const Node* &v);
    void in_order_helper(string s, Node* x);
    void traverse_max_data(T1 data, Node<T1, T2>* x);
    void traverse_min_data(T1 data, Node<T1, T2>* x);
    
}

