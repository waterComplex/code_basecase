#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}



class GenericTree {
    Node * root;
    public:
    GenericTree(Node * r){
        this->root = r; 
    }
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    /*
    we want to make range based for loop work 
    for generic tree 

    GenricTree gt(root);
    for(int value_of_nodes : gt) {
        
    }
    order that we are using here is "preorder"
    we want to provide this function 
    */
    

}