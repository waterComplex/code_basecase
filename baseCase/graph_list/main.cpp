#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T1,typename T2>
class Graph{
    public:
    unordered_map<T1 , list<T2> > adj;

    //for <int,int>
    void addEdge(int u, int v, bool dir){
        //dir = 0 -> undirected
        //dir = 1 -> directed

        //creat edge from u to v
        adj[u].push_back(v);

        if(!dir){
            //if not directed 
            adj[v].push_back(u);
        }
    }
    
    void printAdjList (){
        for(auto p : adj){
            cout<<p.first<<"-> ";
            for(auto a : p.second){
                cout<<a<<", ";
            }
            cout<<endl;
        }
    }
};

int main (){

    int n{};
    cout<<"Enter the number of vertices: ";
    cin>>n;

    int m{};
    cout << "Enter the number of edges: ";
    cin>>m;

    Graph <int,int > g;
    
    //for <int, int >
    for(int i{};i < m;i++) {
        int u,v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    //printing the graph
    g.printAdjList();
}