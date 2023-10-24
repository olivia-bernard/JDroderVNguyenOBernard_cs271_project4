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
// Node class
// =================================================

template <typename T1, typename T2>
Node<T1, T2>::Node(const T1& d, const T2& k) {
    data = d;
    key = k;
    left = NULL;
    right = NULL;
    p = NULL;
}

template <typename T1, typename T2>
T1 Node<T1, T2>::get_data(){
    return data;
}

template <typename T1, typename T2>
T2 Node<T1, T2>::get_key(){
    return key;
}

//=================================================
// BST class
//=================================================

template <typename T1, typename T2>
BST<T1, T2>::BST(void){
    root = NULL;
}

template <typename T1, typename T2>
BST<T1, T2>::~BST(){
    // root = NULL;
    delete root;
}

template <typename T1, typename T2>
bool BST<T1, T2>::empty(){
    if (root == NULL){
        return true;
    }
    return false;
}



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


template <typename T1, typename T2>
void BST<T1, T2>::remove(T2 k){
    Node<T1, T2>* x = search(k); // if the bst is empty, error thrown here
    // put in if x is null
    if (x == NULL){
        throw std::runtime_error("Error");
    }
    if (x->p == NULL){ // when x is the root of the tree
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
    else{
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


template <typename T1, typename T2>
string BST<T1, T2>::in_order(){
    stringstream s;
    Node<T1, T2>* x = root;
    in_order_helper(s, x);
    string res = s.str();
    res = res.substr(0, res.length()-1);
    return res;
}

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


template <typename T1, typename T2>
string BST<T1, T2>::to_string() {
    stringstream s;
    queue<Node<T1, T2>*> q;
    Node<T1, T2>* x = NULL;

    q.push(root);
    while (!q.empty()) {
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



