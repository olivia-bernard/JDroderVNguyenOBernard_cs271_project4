#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

// template <typename T1, typename T2>
// class BST;

// template<typename T1, typename T2>
// class Node;

#ifndef NODE_H
#define NODE_H

template<typename T1, typename T2>
class Node
{   
    template<class L1, class L2>
    friend class BST;

    public:
        Node(const T1& d, const T2& k) //constructor
        {
            data = d;
            key = k;
            left = NULL;
            right = NULL;
            p = NULL;
        };
        T1 get_data()
        {return data;};
        T2 get_key()
        {return key;};
        


    protected:
    // property members
        T1 data;
        T2 key;
        Node<T1, T2> * left;
        Node<T1, T2> * right;
        Node<T1, T2> * p;

};
// #endif


// #ifndef BST_H
// #define BST_H

// template<class T1, class T2>
// class BST;

template <typename T1, typename T2> //T1: data, T2: key
class BST
{
    public:
        BST(void)
        {root = NULL;}; //constructor
        ~BST()
        {delete root;}; //deconstructor

        bool empty();
        void insert(const T1& d, const T2& k);
        T1 get(T2 k);
        void remove(T2 k);
        T1 max_data();
        T2 max_key();
        T1 min_data();
        T2 min_key();
        T2 successor(T2 k);
        string in_order();
        string to_string();
        void trim(T2 low, T2 high);

    private:
        Node<T1, T2>* root;
        
        Node<T1, T2>* search(T2 k);
        void transplant(const Node<T1, T2>* &u, const Node<T1, T2>* &v);
        void in_order_helper(string s, Node<T1, T2>* x);
        T1 traverse_max_data(T1& data, Node<T1, T2>* x);
        T1 traverse_min_data(T1& data, Node<T1, T2>* x);
        void in_order_helper(ostream& s, Node<T1, T2>* x);
        void transplant(Node<T1, T2>* u, Node<T1, T2>* v);
        
};

#endif