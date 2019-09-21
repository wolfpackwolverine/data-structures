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
     void topologicalsort(){
          queue<T> q;
          map<T,bool > visited;
          map<T,int > indegree;
//init visited and indegree list
          for(auto i:adjList){
               T node = i.first;
               visited[node] = false;
               indegree[node] = 0;
          }
          //init the indegrees of all nodes
          for(auto i:adjList){
               T u = i.first;
               for(T v:adjList[u]){
                    indegree[v]++;
               }
          }
          //find out all the nodes with 0 indegree
          for(auto i:adjList){
               T node = i.first;
               if(indegree[node]==0)
                    q.push(node);
          }
          //algorithm
          while(!q.empty()){
                 T node = q.front();
                 q.pop();
                 cout<<node<<"-->";
                 for(T neighbour:adjList[node]){
                    indegree[neighbour]--;

                    if(indegree[neighbour]==0){
                         q.push(neighbour);
                    }
                 }
          }


}
    bool iscycleBfs(T src){
     map<T,bool> visited;
     map<T, T> parent;
     queue<T> q;

     q.push(src);
     visited[src]=true;
     parent[src] = src;

     while(!q.empty()){
          T node = q.front();
          q.pop();

          for(T neighbour:adjList[node]){
               if(visited[neighbour]==true && parent[node]!=neighbour){
                    return true;
               }
               else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
               }
          }
     }
     return false;
    }
      
    bool iscyclichelper(T node,map<T,bool> &visited,T parent){
     visited[node] = true;

     for(T neighbour:adjList[node]){
          if(!visited[neighbour]){
               bool cycleDetected = iscyclichelper(neighbour,visited,node);
               if(cycleDetected)return true;
          }
          else if(neighbour!=parent){
               return true;
          }
     }
     return false;
    }

    bool iscyclicDfs(){
     map<T,bool> visited;


     for(auto i:adjList){
          T node = i.first;
          if(!visited[node]){
               bool ans = iscyclichelper(node,visited,node);
               if(ans==true)return true;
          }
     }
     return false;
    }

     void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){
          visited[node]=true;

          for(T neighbour: adjList[node]){
               if(!visited[neighbour]){
                    dfsHelper(neighbour,visited);
               }
          }
          // after this children of current node is visited 
          //so we can add this to the list
          ordering.push_front(node);
     }
     void dfsTopologicalSort(){
          map<T,bool> visited;
          list<T> ordering;
          //for counting connected components in a grapf dfs app
          for(auto i:adjList){
               T city =i.first;
               if(!visited[city]){
                    dfsHelper(city,visited,ordering);
               }
          }
          for(auto i:ordering)cout<<i<<"->";
     }
     bool isBipartite(int s){
            
            queue<int> q;
            q.push(s);
            
            int *colors = new int[V];
            for(int i=0;i<V;i++){
                colors[i] = -1; //Not Visited
            }
            
            colors[s] = 0;
            
            while(!q.empty() ){
                
                int u = q.front();
                q.pop();
                
                for(auto v:l[u]){
                    
                    if(colors[v]==-1){
                        colors[v] = 1 - colors[u];
                        q.push(v);
                    }
                    else if(colors[v]==colors[u]){
                        return false;
                    }
                    
                }
                
            }
                
        return true;
        }
};

int main(){
     Graph<string> g;
     g.addEdge("English","programing logic",false);
     g.addEdge("maths","programing logic",false);
     g.addEdge("programing logic","html",false);
     g.addEdge("programing logic","python",false);
     g.addEdge("programing logic","java",false);
     g.addEdge("programing logic","js",false);
     g.addEdge("python","web dev",false);
     g.addEdge("html","css",false);
     g.addEdge("css","js",false);
     g.addEdge("js","web dev",false);
     g.addEdge("java","web dev",false);
     g.addEdge("python","web dev",false);
     g.dfsTopologicalSort();
     return 0;
}