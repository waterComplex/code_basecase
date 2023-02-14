#include <iostream>
#include <string>
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

class Pair {
    public:
    Node * node;
    int state ;
    Pair (Node * node, int state){
        this ->node = node ; 
        this-> state = state;
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

int main(){
    int arr[] = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    // stack<pair<Node*,int>> st = new stack <> () ;
    stack<Pair> st;
    Node * root = new Node(arr[0],NULL,NULL);
    Pair rp (root , 1);
    st.push(rp);
    int i = 0;
    /*
    stete == 1 -> make element at next index its left child
    stete == 2 -> make element at next index its right child
    stete == 3 -> pop from stack*/
    while(st.empty() == false){
        // Pair top = st.top();
        if(st.top().state == 1){
            i++;
            if(arr[i] != -1){
                Node * ln = new Node(arr[i],NULL,NULL);
                st.top().node->left = ln;

                st.top().state += 1;
                
                Pair newp (ln,1);
                st.push(newp);
                
            }else{
                st.top().node->left = NULL;
                st.top().state += 1;
            }
        }else if(st.top().state == 2 ){
            i++;
            if(arr[i] != -1){
                Node * rn = new Node(arr[i],NULL,NULL);
                st.top().node->right = rn;

                st.top().state += 1;
                
                Pair newp (rn,1);
                st.push(newp);
                
            }else{
                st.top().node->right = NULL;
                st.top().state += 1;
            }
        }else {
            //st.top().state == 3
            st.pop();
        }

    } 
    display(root);

}