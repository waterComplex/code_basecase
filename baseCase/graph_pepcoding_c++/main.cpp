#include<iostream>
#include<vector>
using namespace std;


class Edge {
    public:
        int v= 0;
        int w = 0;
        Edge(int v, int w){
            this-> v = v;
            this-> w = w;
        }
};

//MaKING GRAPH GLOBAL
int const N = 7; // we are taking const number of edges here
vector<vector<Edge>> graph(N);

void addEdge(int u , int v ,int w){
    //bidirectional graph
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));
}

void display(){
    for(int i{};i < N;i++){
        cout<<i<<" ";
        for(Edge e : graph[i]){
            cout<<"("<< e.v<<" "<<e.w<<") ";
        }
        cout<<endl;
    }
}

void solve(){
    //Adding manually ,can take input also 
    // while(m-- > 0){
        // number of edges
    //     int u;
    //     int v;
    //     int w;

    //     cin >> u >> v >> w ;
    //      addEdge(u,v,w);
    // }
    addEdge (0, 1, 10);
    addEdge (0, 3, 10);

    addEdge (1,2, 10);

    addEdge (2, 3, 40) ;

    addEdge (3,4,2);

    addEdge (4, 5, 2) ;
    addEdge (4, 6, 3) ;

    addEdge (5, 6, 81) ;

    display();

}

int main(){
    solve();
    return 0;
}


///USED IN HAS PATH QUESTION ON PEP CODING
/*
#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};


int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here

}

*/