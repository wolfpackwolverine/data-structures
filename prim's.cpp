#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	int v;
	list<pair<int,int> > *adj;

	Graph(int v){
		this->v = v;
		adj = new list<pair<int,int> >[v];
	}

	void addEdge(int u, int v,int w){
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}

	int findMinVertex(int *weight,bool *visited,int v){
		int minVertex = -1;

		for(int i=0;i<v;i++) {
			if(!visited[i] and (minvertex == -1 or weight[i] < weight[minvertex])){
				minvertex = i;
			}
		}

		return minVertex;
	}

	void Prims(){
		bool *visited = new bool[v];
		int *parent = new int[v];
		int *weight = new int[v];
		for(int i=0;i<v;i++){
			visited[i] = false;
			weight[i] = INT_MAX;
		}
		parent[0] = -1;
		weight[0] = 0;
		for(int i=0;i<v;i++) {
			int minVertex = findMinVertex(weight,visited,v);
			visited[minvertex] = true;
			for(auto neighbour: adj[minvertex]){
				if(!visited[neighbour.first]){
					if(weight[neighbour.first] > neighbour.second){// if the  weight for a vertex in our maping is greater then the weight at a particular edge or not
						parent[neighbour.first] = minvertex;
						weight[neighbour.first] = neighbour.second;
					}
				}
			}
		}
		for(int i=1;i<v;i++){
			cout<<i<<"--"<<parent[i]<<"with weight "<<weight[i]<<endl;
		}
	}
};
int main(){
	
}