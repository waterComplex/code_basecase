#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Edge{
    public:
        int src;
        int nbr;
        int wt ;

        Edge(int src, int nbr,int wt){
            this->src = src;
            this->nbr = nbr;
            this->wt = wt;
        }
};

template<typename T>
bool allTrue(std::vector<T> const &v) {
    for(int i{} ; i<v.size();i++){
        if(v[i] == false){
            return false;
        }
    }
    return true;
}

void printHamiltonianPathAndCycle( vector<Edge>graph[] ,int src, int u,vector<bool> &visited, string path){
    if(allTrue(visited)){ 
        bool for_cycle = false;
        for(Edge e : graph[src]){
            if(e.nbr == u){
                for_cycle = true;
                break;
            }
        }
        if(for_cycle){
            cout<<path<<"*"<<endl;
        }else{
            cout<<path<<"."<<endl;
        }
    }
    cout<<u<<".  n"<<endl;
    visited[u] = true;
    for(Edge e : graph[u]){
        if(visited[e.nbr] == false){
            
            path += to_string(e.nbr);
            printHamiltonianPathAndCycle(graph,src,e.nbr,visited,path);\

        }
    }
    visited[u] = false;
}
int main(){

    int vtces;
    cin>>vtces;
    vector<Edge>graph[vtces];

    int edges;
    cin>>edges;
    for(int i = 0; i < edges; i++){
        int v1 ;
        int v2 ;
        int wt ;
        cin>>v1>>v2>>wt;
        graph[v1].push_back( Edge(v1, v2, wt));
        graph[v2].push_back( Edge(v2, v1, wt));
    }

    vector<bool> visited(vtces, false);
    printHamiltonianPathAndCycle(graph,0,0,visited,"0");
    



    return 0;
}