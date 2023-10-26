#include "bst.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include<queue>
#include<exception>

using namespace std;

//=================================================
// BST class
//=================================================

// empty - function to check if BST is empty
// preconditions: none
// postconditions: returns true if tree is empty, otherwise false
template <typename T1, typename T2>
bool BST<T1, T2>::empty(){
    if (root == NULL){
        return true; // return true if root is NIL, meaning tree is empty
    }
    return false; // return false if root is not NIL, meaning tree is non-empty
}

// insert - function to insert a new node into a BST
// preconditions: d and k are valid values
// postconditions: insert a new node with data 'd' and key 'k' into the tree
template <typename T1, typename T2>
void BST<T1, T2>::insert(const T1& d, const T2& k){
    Node<T1, T2>* node = new Node<T1, T2>(d, k); // create a new node w/ data 'd' and key 'k'

    if (root == NULL){ //empty tree
        root = node; // if tree is empty, set new node as the root
        return; // exit
    }

    Node<T1, T2>* x = root; // node to compare with the new element
    Node<T1, T2>* y = NULL; // parent node
    
    while(x != NULL){
        y = x; // update 'y' to current node 'x'.
        if (x->key > node->key){ 
            x = x->left; // move to left child if new node's key is smaller
        }
        else {
            x = x->right; // move to right child if new node's key is larger
        }
    }
    node->p = y; // set parent of new node as 'y'
    if (y->key > node->key){
        y->left = node; // set new node as left child of 'y'
    }
    else{
        y->right = node; // set new node as right child of 'y'
    }
    return; // exit
}

// get - function to get data associated with a given key
// preconditions: k is valid
// postconditions: if tree is empty or key doesn't exist, return default value of type T1,
// otherwise, returns data associated with given key
template <typename T1, typename T2>
T1 BST<T1, T2>::get(T2 k){
        if (root == NULL){
            return T1(); // if tree is empty, return default val of T1
        }
    
    Node<T1, T2>* x = search(k); // search for node w/ given key
    if (x ==NULL){
        return T1(); // if key doesn't exist, return default val of T1
    }
    return x->data; // return data associated w/ given key
}


// remove - function to remove a node with a given key from BST
// preconditions: k is valid
// postconditions: if tree is empty, or key doesn't exist, nothing is done,
// otherwise, node w/ the given key is removed from the tree
template <typename T1, typename T2>
void BST<T1, T2>::remove(T2 k){
    Node<T1, T2>* x = search(k); // if the bst is empty, an error is thrown here
    // put in if x is null
    if (x == NULL){
        return; // exit the function if node w/ given key doesn't exist
    }
    
    // case 1: x has1 or no child
    else if (x->left == NULL){ // when the only child is x.left
        transplant(x, x->right); // replace x with its right child
        return; // exit
    }
    else if (x->right == NULL){ // when the only child is x.right
        transplant(x, x->left); // replace x with its left child
        return; // exit
    }
    
    // case 2: x has 2 child
    // find x successor
    else if (x->left != NULL && x->right != NULL){
        Node<T1, T2>* y = x->right;
        while (y->left != NULL){
            y = y->left; //find the left most node on the right subtree of x
        }
        if (y != x->right){
            transplant(y, y->right); // replace y with its right child
            y->right = x->right;
            y->right->p = y;
        }
        transplant(x, y); // replace x with y
        y->left = x->left;
        y->left->p = y;
    }
}

// transplant - function to replace subtree rooted at 'u' w/ subtree rooted at 'v'
// preconditions: none
// postconditions: replaces subtree rooted at 'u' w/ subtree rooted at 'v' in the tree
template <typename T1, typename T2>
void BST<T1, T2>::transplant(Node<T1, T2>* u, Node<T1, T2>* v){ // replace subtree rooted at u with subtree rooted at v
    if (u->p == NULL){
        root = v; // if u is the root, set v as the new root// exit
    
    }
    else if (u == u->p->right){ 
        u->p->right = v; // set v as right child of u's parent
    }

    else if (u == u->p->left){
        u->p->left = v; // set v as left child of u's parent
    }

    if (v != NULL){
        v->p = u->p; // set u's parent as v's parent
    }

    return; // exit
}


// search - function to search for a node w/ a given key in the BST
// preconditions: none
// postconditions: if tree is empty, return NIL
// if key exists, returns node w/ given key, otherwise return NIL
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::search(T2 k){
    if (root == NULL){
        return root; // if tree is empty, return NIL
    }
    else{
        Node<T1, T2>* x = root; // initialize a node 'x' as the root
        while (x != NULL && x->key != k){
            if(k > x->key){
                x = x->right; // move to the right child if k is greater than x's key
            }
            else{
                x = x->left; // move to the left child if k is smaller than x's key
            }
        }
        return x; // return node w/ given key or NIL if not found
    }
}


// //=================================================
// // Min/max data
// // =================================================

// max_data - function to find the max data in the BST
// preconditions: none
// postconditions: if the tree is empty, return default value of T1
// otherwise, return max data in the tree
template <typename T1, typename T2>
T1 BST<T1, T2>::max_data(){
    if (root == NULL){
        return T1(); // if tree is empty, return default val of T2
    }
    Node<T1, T2>* temp = root;
    while (temp->right != NULL){
        temp = temp->right; // traverse to leftmost node to find min key
    }
    return temp->data;
}


// traverse_max_data -- helper function to recursively find the max data in a subtree rooted at 'x'
// preconditions: data is valid
// postcondition: recursively returns the max data node, or NIL otherwise
template <typename T1, typename T2>
T1 BST<T1, T2>::traverse_max_data(T1& data, Node<T1, T2>* x){
    if (x == NULL){
        return data; // return data if node is NIL
    }
    else{
        T1 max_left = traverse_max_data(data, x->left); // recursively find the max data in the left subtree.
        if (x->data > max_left){
            return traverse_max_data(x->data, x->right); // recursively find the max data in the right subtree.
        }   
        else{
            return traverse_max_data(max_left, x->right); // recursively find the max data in the right subtree
        }
        }
}

// min_data - function to find the minimum data in the BST
// preconditions: none
// postconditions: if tree is empty, returns default value of T1, 
// otherwise, returns minimum data in the tree
template <typename T1, typename T2>
T1 BST<T1, T2>::min_data(){
    if (root == NULL){
        return T1(); // if tree is empty, return default val of T2
    }
    Node<T1, T2>* temp = root;
    while (temp->left != NULL){
        temp = temp->left; // traverse to leftmost node to find min key
    }
    return temp->data;
}

// traverse_min_data - helper function to recursively find the min data in a subtree rooted at 'x'
// preconditions: data is valid
// postconditions: recursively returns the min data node, or NIL otherwise.
template <typename T1, typename T2>
T1 BST<T1, T2>::traverse_min_data(T1& data, Node<T1, T2>* x){
    if (x == NULL){
        return data; // return data if node is NIL
    }
    else{
        T1 min_left = traverse_min_data(data, x->left); // recursively find the min data in the left subtree.
        if (x->data < min_left){
            return traverse_min_data(x->data, x->right); // recursively find the min data in the right subtree.
        }   
        else{
            return traverse_min_data(min_left, x->right); // recursively find the min data in the right subtree.
        }
        }
}

// //=================================================
// // Min/max key
// // =================================================

// max_key - function to find the max key in the BST
// preconditions: none
// postconditions: if tree is empty, return a default value of T2,
// otherwise, return the max key in the tree
template <typename T1, typename T2>
T2 BST<T1, T2>::max_key(){
    if (root == NULL){
        return T2(); // if tree is empty, return default value of T2
    }
    Node<T1, T2>* temp = root;
    while (temp->right != NULL){
        temp = temp->right; // traverse to rightmost node to find max key
    }
    return temp->key; // return max key
}

// min_key - function to find the minimum key in the BST
// preconditions: none
// postconditions: if tree is empty, return default value of T2,
// otherwise, return min key in the tree
template <typename T1, typename T2>
T2 BST<T1, T2>::min_key(){
    if (root == NULL){
        return T2(); // if tree is empty, return default val of T2
    }
    Node<T1, T2>* temp = root;
    while (temp->left != NULL){
        temp = temp->left; // traverse to leftmost node to find min key
    }
    return temp->key; // return min key
}

// successor - function to find the successor of a given key in a BST
// preconditions: none
// postconditions: if the tree is empty or the key doesn't exist, return a default value of T2,
// otherwise, return the key of the successor of the given key
template <typename T1, typename T2>
T2 BST<T1, T2>::successor(T2 k){
    Node<T1, T2>* x = search(k); // search for node w/ given key
    if (x == NULL){
         return T2(); // if key doesn't exist, return default val of T2
    }
    if (x->right != NULL){
        x = x->right;
        while(x->left != NULL){
            x = x->left; // traverse to leftmost node in right subtree to find successor
        }
        return x->key; // return key of successor
    }

    Node<T1, T2>* y = x->p;
    while (y != NULL && x == y->right){
        x = y;
        y = y->p; // move up the tree until a node w/ a greater key is found
    }
    if (y==NULL){
         return T2(); // if no successor found, return default val of T2
    }
    return y->key; // return key of successor

}

// in_order - function to perform an in-order traversal of the BST
// preconditions: none
// postconditions: return a space-separated string of keys in-order traversal.
template <typename T1, typename T2>
string BST<T1, T2>::in_order(){
    stringstream s;
    Node<T1, T2>* x = root;
    in_order_helper(s, x); // perform an in-order traversal and add keys to stringstream
    string res = s.str();
    res = res.substr(0, res.length()-1); // remove trailing space
    return res; // return the in-order traversal as a string
}

// in_order_helper - helper function to perform an in-order traversal of a subtree rooted at 'x'
template <typename T1, typename T2>
//pass in a bst rooted at x
void BST<T1, T2>::in_order_helper(ostream& s, Node<T1, T2>* x){
    if (x == NULL){
        return; // return if the node is NIL
    }
    in_order_helper(s, x->left); // recursively traverse the left subtree
    s << x->key << ' '; // add key to stringstream
    in_order_helper(s, x->right); // recursively traverse the right subtree
}

// to_string - function to convert the BST to a string
// preconditions: none
// postconditions: return a space-separated string representation of the keys in level-order traversal
template <typename T1, typename T2>
string BST<T1, T2>::to_string() {

    stringstream s;
    queue<Node<T1, T2>*> q;
    Node<T1, T2>* x = root;

    q.push(root);

    while (!q.empty() && x!= NULL) {
        x = q.front();
        s << x->key << ' ';
        if (x->left != NULL) {
            q.push(x->left);
        }
        if (x->right != NULL) {
            q.push(x->right);
        }
        q.pop();
    }
   
    string result = s.str();
    if (result.length() != 0) {
        return result.substr(0, result.length()-1); // remove the evil space
    }
    return result; // return the level-order traversal as a string
}


// trim - function to BST to contain only keys in a specific range [low: high]
// preconditions: 'low' and 'high' are valid values, 'low' <= 'high'
// postconditions: BST is modified to only contain keys with the specified range
template <typename T1, typename T2>
void BST<T1, T2>::trim(T2 low, T2 high){
    if (root == NULL){
        return; // if tree is empty, nothing to trim, exit
    }
    while(root != NULL && (root->key > high || root->key < low)){
        if (root->key < low){
            root = root->right;
            root->p = NULL;
        }
        else if (root->key > high){
            root = root->left;
            root->p = NULL;
        }
    }
    if (root != NULL){
        // search for the node x that has key smaller than low
        Node<T1, T2>* x = root;
        while(x != NULL && x->key >= low){
            x = x->left;
        }
        if (x!= NULL){
            // cut off x
            transplant(x, x->right);
        }

        //search for the node y that has key greater than high
        x = root;
        while(x != NULL && x->key <= high){
            x = x->right;
        }
        if (x!=NULL){
            transplant(x, x->left);
        }
    }
}



