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
        return true;
    }
    return false;
}

// insert - function to insert a new node into a BST
// preconditions: d and k are valid values
// postconditions: insert a new node with data 'd' and key 'k' into the tree
template <typename T1, typename T2>
void BST<T1, T2>::insert(const T1& d, const T2& k){
    Node<T1, T2>* node = new Node<T1, T2>(d, k);

    if (root == NULL){ //empty tree
        root = node;
        return;
    }

    Node<T1, T2>* x = root; // node to compare with the new element
    Node<T1, T2>* y = NULL; // parent node
    
    while(x != NULL){
        y = x;
        if (x->key > node->key){
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    node->p = y;
    if (y->key > node->key){
        y->left = node;
    }
    else{
        y->right = node;
    }
    return;
}

// get - function to get data associated with a given key
// preconditions: k is valid
// postconditions: if tree is empty or key doesn't exist, return default value of type T1,
// otherwise, returns data associated with given key
template <typename T1, typename T2>
T1 BST<T1, T2>::get(T2 k){
        if (root == NULL){
            return T1();
        }
    
    Node<T1, T2>* x = search(k);
    if (x ==NULL){
        return T1();
    }
    return x->data;
}


// remove - function to remove a node with a given key from BST
// preconditions: k is valid
// postconditions: if tree is empty, or key doesn't exist, nothing is done,
// otherwise, node w/ the given key is removed from the tree
template <typename T1, typename T2>
void BST<T1, T2>::remove(T2 k){
    Node<T1, T2>* x = search(k); // if the bst is empty, error thrown here
    // put in if x is null
    if (x == NULL){
        cout << "to here " <<endl;
        return;
    }
    else if (x->p == NULL){ // when x is the root of the tree
        root = NULL;
        return;
    }
    
    // case 1: x has1 or no child
    else if (x->left == NULL){ // when the only child is x.left
        transplant(x, x->right);
        //cout << x->right->key <<endl;
        return;
    }
    else if (x->right == NULL){ // when the only child is x.right
        transplant(x, x->left);
        //cout << x->right->key <<endl;
        return;
    }
    
    // case 2: x has 2 child
    // find x successor
    else if (x->left != NULL && x->right != NULL){
        Node<T1, T2>* y = x->right;
        while (y->left != NULL){
            y = y->left; //find the left most node on the right subtree of x
        }
        if (y != x->right){
            transplant(y, y->right);
            y->right = x->right;
            y->right->p = y;
        }
        transplant(x, y);
        y->left = x->left;
        y->left->p = y;
    }
    return;

}

// transplant - function to replace subtree rooted at 'u' w/ subtree rooted at 'v'
// preconditions: none
// postconditions: replaces subtree rooted at 'u' w/ subtree rooted at 'v' in the tree
template <typename T1, typename T2>
void BST<T1, T2>::transplant(Node<T1, T2>* u, Node<T1, T2>* v){ // replace subtree rooted at u with subtree rooted at v
    if (u->p == NULL){
        root = v;
        return;
    }
    if (u == u->p->right){
        u->p->right = v;
    }

    else if (u == u->p->left){
        u->p->left = v;
    }

    if (v != NULL){
        v->p = u->p;
    }

    return;
}


// search - function to search for a node w/ a given key in the BST
// preconditions: none
// postconditions: if tree is empty, return NIL
// if key exists, returns node w/ given key, otherwise return NIL
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::search(T2 k){
    // try{
    if (root == NULL){
        return root;
    }
    else{
        Node<T1, T2>* x = root;
        while (x != NULL && x->key != k){
            if(k > x->key){
                x = x->right;
            }
            else{
                x = x->left;
            }
        }
        //cout <<x->key<<endl;
        return x;
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
         return T1();
    }

    T1 res = root->data;
    // cout <<root->data <<endl;
    res = traverse_max_data(res, root);
    // if (res < max_tree){
    //     return max_tree;
    // }
    return res;
}


// traverse_max_data -- helper function to recursively find the max data in a subtree rooted at 'x'
// preconditions: data is valid
// postcondition: recursively returns the max data node, or NIL otherwise
template <typename T1, typename T2>
T1 BST<T1, T2>::traverse_max_data(T1& data, Node<T1, T2>* x){
    if (x == NULL){
        // cout << data << endl;
        // cout << "run 1 time"<<endl;
        return data;
    }
    else{
        T1 max_left = traverse_max_data(data, x->left);
        if (x->data > max_left){
            return traverse_max_data(x->data, x->right);
        }   
        else{
            return traverse_max_data(max_left, x->right);
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
         return T1();
    }
    T1 res = root->data;
    // cout <<root->data <<endl;
    res = traverse_min_data(res, root);
    // if (res < max_tree){
    //     return max_tree;
    // }
    return res;
}

// traverse_min_data - helper function to recursively find the min data in a subtree rooted at 'x'
// preconditions: data is valid
// postconditions: recursively returns the min data node, or NIL otherwise.
template <typename T1, typename T2>
T1 BST<T1, T2>::traverse_min_data(T1& data, Node<T1, T2>* x){
    if (x == NULL){
        // cout << data << endl;
        // cout << "run 1 time"<<endl;
        return data;
    }
    else{
        T1 min_left = traverse_min_data(data, x->left);
        //cout << "x data " << x->data <<endl;
        //cout << "data returned " << min_left << endl;
        if (x->data < min_left){
            return traverse_min_data(x->data, x->right);
        }   
        else{
            return traverse_min_data(min_left, x->right);
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
        return T2();
    }
    Node<T1, T2>* temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    return temp->key;
}

// min_key - function to find the minimum key in the BST
// preconditions: none
// postconditions: if tree is empty, return default value of T2,
// otherwise, return min key in the tree
template <typename T1, typename T2>
T2 BST<T1, T2>::min_key(){
    if (root == NULL){
        return T2();
    }
    Node<T1, T2>* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp->key;
}

// successor - function to find the successor of a given key in a BST
// preconditions: none
// postconditions: if the tree is empty or the key doesn't exist, return a default value of T2,
// otherwise, return the key of the successor of the given key
template <typename T1, typename T2>
T2 BST<T1, T2>::successor(T2 k){
    Node<T1, T2>* x = search(k);
    if (x == NULL){
         return T2();
    }
    if (x->right != NULL){
        x = x->right;
        while(x->left != NULL){
            x = x->left;
        }
        return x->key;
    }

    Node<T1, T2>* y = x->p;
    while (y != NULL && x == y->right){
        x = y;
        y = y->p;
    }
    if (y==NULL){
         return T2();
    }
    return y->key;

}

// in_order - function to perform an in-order traversal of the BST
// preconditions: none
// postconditions: return a space-separated string of keys in-order traversal.
template <typename T1, typename T2>
string BST<T1, T2>::in_order(){
    stringstream s;
    Node<T1, T2>* x = root;
    in_order_helper(s, x);
    string res = s.str();
    res = res.substr(0, res.length()-1);
    return res;
}

// in_order_helper - helper function to perform an in-order traversal of a subtree rooted at 'x'
template <typename T1, typename T2>
//pass in a bst rooted at x
void BST<T1, T2>::in_order_helper(ostream& s, Node<T1, T2>* x){
    if (x == NULL){
        return;
    }
    in_order_helper(s, x->left);
    s << x->key << ' ';
    in_order_helper(s, x->right);
}

// to_string - function to convert the BST to a string
// preconditions: none
// postconditions: return a space-separated string representation of the keys in level-order traversal
template <typename T1, typename T2>
string BST<T1, T2>::to_string() {
    stringstream s;
    queue<Node<T1, T2>*> q;
    Node<T1, T2>* x = root;

    q.push(x);
    while (!q.empty() && x!=NULL) {
        x = q.front();
        s << x->key << ' '; // Add a space after each key
        if (x->left != NULL) {
            q.push(x->left);
        }
        if (x->right != NULL) {
            q.push(x->right);
        }
        q.pop();
    }

    string result = s.str();
    if (!result.empty()) {
        result.pop_back(); // remove the evil space
    }

    return result;
}



