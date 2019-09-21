#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

//Adj List Implementation for generic Nodes
template<typename T>
class Graph{
          

      //Array of Linked Lists of size V, V LL's are there
     map<T,list<T> > adjList;
public:
     Graph(){
          
     }
     void addEdge(T u,T v,bool bidir=true){
          adjList[u].push_back(v);
          if(bidir){
               adjList[v].push_back(u);
          }
     }
     void printAdjList(){
          for(auto row : adjList){
               T key = row.first;
               cout<<key<<"->";
               for(auto element:row.second){
                    cout<<element<<",";
               }
               cout<<endl;
          }
               
     }
     void dfsHelper(T node,map<T,bool> &visited){
          visited[node]=true;
          cout<<node<<" ";

          for(T neighbour: adjList[node]){
               if(!visited[neighbour]){
                    dfsHelper(neighbour,visited);
               }
          }
     }
     void dfs(T src){
          map<T,bool> visited;
          dfsHelper(src,visited);
     }

};

int main(){
     Graph<int> g;
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(0,4);
     g.addEdge(2,4);
     g.addEdge(3,2);
     g.addEdge(2,3);
     g.addEdge(3,5);
     g.addEdge(3,4);
     g.dfs(0);
     return 0;
}