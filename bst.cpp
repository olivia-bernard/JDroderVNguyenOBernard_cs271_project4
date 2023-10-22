#include bst.h
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//=================================================
// Node class
// =================================================
template <class T1, class T2>
Node<T1, T2>::Node(T1 d, T2 k) {
    data = d;
    key = k;
    left = NULL;
    right = NULL;
    p = NULL;
}

T1 Node<T1, T2>::get_data(){
    return data;
}

T2 Node<T1, T2>::get_key(){
    return key;
}

//=================================================
// BST class
//=================================================

template <class T1, class T2>
BST<T1, T2>::BST(){
    root = NULL;
}

template <class T1, class T2>
BST<T1, T2>::~BST(){
    delete root;
}

template <class T1, class T2>
void BST<T1, T2>::empty(){
    if (root == NULL){
        return true;
    }
    return false
}



template <class T1, class T2>
void insert(T1 d, T2 k){
    Node<T1, T2> node = new Node<T1, T2>(d, k);

    if (root == NULL){
        root = node;
        return;
    }

    Node<T1, T2>* x = root; // node to compare with the new element
    Node<T1, T2>* y = NULL; // parent node
    
    while(x != NULL){
        y = x;
        if (x.key > node.key){
            x = x.left;
        }
        else {
            x = x.right
        }
    }
    node.p = y;
    if (y.key > node.key){
        y.left = node;
    }
    else{
        y.right = node;
    }
    return;
}

template <class T1, class T2>
T1 BST<T1, T2>::get(T2 k){
    if (root == NULL){
        throw std::exception("Error: Binary search tree is empty");
    }
    else{
        Node<T1, T2> x = search(T2, k);
        return x.data;
    }
}



void BST<T1, T2>::remove(T2 k){
    Node<T1, T2> x = search(T2, k); // if the bst is empty, error thrown here
    // put in if x is null
    if (x == NULL){
        throw std::exception("Error: not found key")
    }
    if (x.p == NULL){ // when x is the root of the tree
        root = NULL;
        return;
    }
    
    // case 1: x has1 or no child
    if (x.left == NULL){ // when the only child is x.left
        transplant(x, x.left)
    }
    if (x.right == NULL){ // when the only child is x.right
        transplant(x, x.right)
    }
    
    // case 2: x has 2 child
    // find x successor
    Node<T1, T2>* y = x.right;
    while (y.left != NULL){
        y = y.left; //find the left most node on the right subtree of x
    }
    if (y.right != NULL){
        transplant(y, y.right)
        y.right = x.right;
        y.right.p = y;
        transplant(y, x);
        y.left = x.left;
        y.left.p = y;
    }

}

void BST<T1, T2>::transplant(Node<T1, T2> u, Node<T1, T2> v){ // replace subtree rooted at u with subtree rooted at v
    if (u.p == NULL){
        root = v;
        return;
    }
    if (u == u.p.right){
        u.p.right = v;
        return;
    }
    else if(u == u.p.left){
        u.p.left = v;
    }
    if (v != NULL){
        v.p = u.p;
    }

    return;
}


template <class T1, class T2>
BST BST<T1, T2>::search(T2 k){
    if (root == NULL){
        throw std::exception("Error: Binary search tree is empty");
    }
    else{
        Node<T1, T2>* x = root;
        while (x != NULL && x.key != key){
            if(k > x.key){
                x = x.right;
            }
            else{
                x = x.left;
            }
        }
    }
    return x;
}

//=================================================
// Min/max data
// =================================================
template <class T1, class T2>
T1 BST<T1, T2>::max_data(){
    T1 res = root->data; // (**)
    // search on the left subtree
    traverse_max_data(res, root);
    return res;
}

template <class T1, class T2>
void BST<T1, T2>::traverse_max_data(T1 data, Node<T1, T2>* x){
    if (x == NULL){
        return;
    }
    if (x->data > data){
        data = x->data;
    }
    traverse_max_data(data, x.left); // put while loop in -> instead of calling recursion on x.right 
                                    // -> use while loop and change x=x.right after the first recursion on x.left
    traverse_max_data(data, x.right);
}

template <class T1, class T2>
T2 BST<T1, T2>::min_data(){
    T1 res = root->data;
    traverse_min_data(res, root);
    return res;
}

template <class T1, class T2>
void BST<T1, T2>::traverse_min_data(T1 data, Node<T1, T2>* x){
    if (x == NULL){
        return;
    }
    if (x->data < data){
        data = x->data;
    }
    traverse_max_data(data, x.left);
    traverse_max_data(data, x.right);
}

//=================================================
// Min/max key
// =================================================
template <class T1, class T2>
T2 BST<T1, T2>::max_key(){
    Node<T1, T2>* temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    return temp->key;
}

template <class T1, class T2>
T2 BST<T1, T2>::min_key(){
    Node<T1, T2>* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

template <class T1, class T2>
T2 BST<T1, T2>::successor(T2 k){
    Node<T1, T2>* x = search(T2 k);
    if (x == NULL){
        throw std::exception("Error: key not found");
    }

    else{
        else if (x->right != NULL){
            x = x->right;
            while(x->left != NULL){
                x = x->left;
            }
            return x;
        }
        else{
            Node<T1, T2>* y = x->p;
            while (y != NULL && x != y->right){
                x = y;
                y = y->p;
            }
            return y;
        }
    }
}

template <class T1, class T2>
string BST<T1, T2>::in_order(){
    stringstream s;
    Node<T1, T2>* x = root;
    in_order_helper(s, x);
    return s.str();
}

template <class T1, class T2>
//pass in a bst rooted at x
void BST<T1, T2>::in_order_helper(ostream& s, Node<T1, T2>* x){
    if (x == NULL){
        return;
    }
    in_order_helper(s, x.left);
    s << x->data;
    in_order_helper(x, x.right)
}

template <class T1, class T2>
void BST<T1, T2>::traverse(Node<T1, T2>* root, ostream& s){
    if (root == NULL){
        return;
    }
    if(root.left != NULL || root.right == NULL){
        s << root->key;
    }
    else {s << root->key << " ";
    }
    traverse(root.left);
    traverse(root.right);
}


template <class T1, class T2>
string BST<T1, T2>::to_string(){
    // Node<T1, T2>* temp = root;
    stringstream s;
    traverse(root, s);
    return s.str();
}


