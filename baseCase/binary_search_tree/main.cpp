#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

class Node{
    public:
    int data ;
    Node* left;
    Node* right;

    Node(int data,Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


void display (Node * node){
    if(node == NULL){
        return ;
    }
    // cout<<node->data<<" ";
    string str ;
    str += node->left == NULL ? "--" : to_string(node->left->data);
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == NULL ? "--" : to_string(node->right->data);

    cout<<str<<endl;

    display(node->left);
    display(node->right);
}

Node * constructor(vector<int> vec,int lo ,int hi){

    // if(lo == hi){        //wrong single child case
    //     Node * root = new Node (vec[lo],NULL,NULL);
    //     return root; 
    // }
    if(lo > hi ){
        return NULL;
    }
    int mid = (hi + lo ) / 2;
    Node * root = new Node(vec[mid],NULL,NULL);
    root -> left = constructor(vec,lo,mid-1);
    root -> right = constructor(vec,mid + 1,hi);
    return root;
}

int main(){
    int size ;
    cin >> size;
    vector<int> vec(size);
    for(int i{} ; i < size ; i++ ) {
        cin >>vec[i];
    }
    Node * root = constructor(vec, 0, vec.size() - 1);
    display(root);

}