//============================================================================
// Name        : Algorithms_onGraphs_Week4_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW2_Week4
// Description : Detecting Anomalies in Currency Exchange Rates
/*
  Task. Given an directed graph with possibly negative edge weights and with n vertices and m edges, check whether it contains a cycle of negative weight.

  Input Format. A graph is given in the standard format.

  Constraints. 1 <= n <= 1e3, 0 <= m <= 1e4, edge weights are integers of absolute value at most 1e3.

  Output Format. Output 1 if the graph contains a cycle of negative weight and 0 otherwise.*/
//============================================================================

#include <iostream>
#include <vector>
#include <climits>
#include <list>

#define INF INT_MAX/2

using namespace std;
using std::vector;

class Edge{
  public:
    int source;
    int destiny;
    int weight;
};


class Graph{
  int V;  //# of vertices
  int E;  //# of edges
  Edge* edge;
  public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w, int m);
    void printEdges(int m);
    int bellman_ford(int n);
};

Graph::Graph(int V, int E){
   this->V=V;
   this->E=E;
   edge= new Edge[E];
}

void Graph::addEdge(int u, int v, int w, int m){
   edge[m].source=u;
   edge[m].destiny=v;
   edge[m].weight=w;
}

int Graph::bellman_ford(int n){
   vector<int> dist(n,INF);
   vector<int> prev (n,-1);
   bool N_cycle=false;
   int u;int V; int E;int w;int v;
   V=this->V; E=this->E;
   dist[0]=0;

   for(int i=0;i<V;i++){
       for(int j=0;j<E;j++){
            u=edge[j].source;
            v=edge[j].destiny;
            w=edge[j].weight;
            if(dist[v]> dist[u]+w){
               dist[v]=dist[u]+w;
               prev[v]=u;
            }
       }
   }

   for(int j=0;j<E;j++){
        u=edge[j].source;
        v=edge[j].destiny;
        w=edge[j].weight;

        if(dist[v]> dist[u]+w){
            N_cycle=true;
        }
   }

   if(N_cycle) return 1;
   return 0;
}

void Graph::printEdges(int m){
   for(int i=0;i<m;i++)
     cout<<"i= "<<i<<" source="<<edge[i].source<<" destiny="<<edge[i].destiny<<" weight="<<edge[i].weight<<endl;
}


int main(){
  int n,m;
  cin >> n >> m;
  Graph *g=new Graph(n,m);
  if( (n>=1 && n<=1e3) && (m>=0 && m<=1e4)){
    for (int i = 0; i < m; i++) {
      int x,y,w;
      cin>>x>>y>>w;
      g->addEdge(--x,--y,w,i);
    }
    cout<<g->bellman_ford(n)<<endl;
  }
  return 0;
}
