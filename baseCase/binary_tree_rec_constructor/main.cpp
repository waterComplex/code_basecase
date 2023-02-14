#include<iostream>
#include<queue>
#include<climits>
#include<string.h>
#include<vector>

using namespace std;

// structure of node
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair {
    public:
    Node * node = nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}
void preorder_trevesal(Node * root){
    if(root == NULL ){
        return ;
    }
    cout<<root->data<<" ";
    preorder_trevesal(root->left);
    preorder_trevesal(root->right);
    
}
void inorder_trevesal(Node * root){
    if(root == NULL ){
        return ;
    }
    preorder_trevesal(root->left);
    cout<<root->data<<" ";
    preorder_trevesal(root->right);
    
}
void postorder_trevesal(Node * root){
    if(root == NULL ){
        return ;
    }
    preorder_trevesal(root->left);
    preorder_trevesal(root->right);
    cout<<root->data<<" ";
    
}
// void traversal(Node * root){
//     if(root == NULL ){
//         return ;
//     }
//     cout<<root->data<<" pre"<<endl;
//     traversal(root->left);
//     cout<<root->data<<" in"<<endl;
//     traversal(root->right);
//     cout<<root->data<<" post"<<endl;
    
// }


void levelorder(Node * root){
    if(root == NULL ){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    queue<Node*> cq;
    while (q.empty() == false){
        /* code */
        Node* top = q.front();q.pop();
        if(root->left != NULL){
            cq.push(root->left);
        }
        if(root->right != NULL){
            cq.push(root->right);
        }
        if(q.empty() == true){
            q = cq;
            queue<Node*> temp;
            cq = temp;
            cout<<endl;
        }
    }
}


int size(Node *node)
{
   //write your code here
   if (node == NULL){
       return 0;
   }

   int s {};
   s += size(node->left);
   s += size(node->right);

   return s+1;
}

int height(Node *node)
{
    //write your code here
    //write your code here
//    if (node == NULL){
//        return 0;
//    }

//     if (node->left == NULL && node->right == NULL){
//        return 0;
//    }
   if (node == NULL){
       return -1;//for edge 
   }
   int h1  = height(node->left);
   int h2  = height(node->right);

    int ch = h1 > h2 ? h1 : h2;
    // cout<<node->data<<" "<<ch+1<<endl;
   return ch+1;
}

int maximum(Node *node)
{
    //write your code here
    if (node == NULL){
       return INT_MIN;
   }

   int a = maximum (node->left);
   int b = maximum (node->right);
    int c = a>b ? a : b;
    int ans = node->data > c ? node->data : c; 

   return ans;
}

int sum(Node *root)
{
    //write your code here
    if (root == NULL){
       return 0;
   }

   int sm  {};
   sm += sum(root->left);
   sm += sum(root->right);

   return sm + root->data;

}

int main()
{
 
  int n;
  cin>>n;
  
  vector<int> arr(n,0);
  for(int i = 0; i < n; i++){
      string temp;
      cin>>temp;
      
      if(temp=="n")
      {
        arr[i] = -1;  
      }
      else
      {
        arr[i] = stoi(temp); 
      }
  }
  
   Node *root = constructTree(arr);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout<<sz<<endl;
    cout<<sm<<endl;
    cout<<max<<endl;
    cout<<ht<<endl;
    /*
    preorder -> node ,left,right = nlr
                eular left of node 
                node is first 
    inorder -> left,node,right = lnr
                eular between the left and right node
                node is in between the left and right node 
    postorder -> left,right,node = lrn
                eular right of node
                node is last
    */
    cout<<"preorder -> ";
    preorder_trevesal(root);
    cout<<endl;
    cout<<"inorder -> ";
    inorder_trevesal(root);
    cout<<endl;
    cout<<"postorder -> ";
    postorder_trevesal(root);
    cout<<endl;


    // traversal(root);//all three at a time
  }