#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	unordered_map<T, list<pair<T,int>> > m;

public:
	void addEdge(T u,T v,int dist,bool bidir=true){
		m[u].push_back(make_pair(v,dist));
		if(bidir){
			m[v].push_back(make_pair(u,dist));
		}
	}

	void printAdj(){

		for(auto j:m){

			cout<<j.first<<"->";

			for(auto l:j.second){
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void dijkstraSSSP(T src){

		unordered_map<T,int> dist;
		//set all distance to infinity
		for(auto j:m){
			dist[j.first] = INT_MAX;
		}

		//Make a set to find out a node with the minimum distance
		set<pair<int, T> > s; // sort according to first parameter thatis distance

		dist[src] = 0;
		s.insert(make_pair(0,src));

		while(!s.empty()){

			//Find the pair at the front.
			auto p =  *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());

			//Iterate over neighbour of the current node
			for(auto childPair: m[node]){
				if(nodeDist + childPair.second < dist[childPair.first]){

					//In the set updation is not possible so remove and insert 
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
					}

					//Insert the new pair
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest],dest));



				}
			}
		}

		//lets print the dist
		for(auto d:dist){
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
		}
	}
	
};
int main(){
	Graph<int> g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.printAdj();
	g.dijkstraSSSP(1);
}