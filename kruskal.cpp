#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src;
	int dest;
	int weight;
};

class Set {
public:
	int rank;
	int parent;
};

int find(Set *set, int i){
	if(set[i].parent != i){
		set[i].parent = find(set,set[i].parent);
	}
	return set[i].parent;
}

void Union(Set *set, int v1, int v2){
	int v1_root = find(set, v1);
	int v2_root = find(set, v2);
	if(set[v1_root].rank < set[v2_root].rank){
		set[v1_root].parent = v2_root;
	}else if (set[v1_root].rank > set[v2_root].rank){
		set[v2_root].parent = v1_root;
	}else {
		set[v2_root].parent = v1_root;
		set[v1_root].rank++;
	}
}

bool cmp(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}

void Kruskals(Edge *input, int n, int e) {
	sort(input,input+e,cmp); // it will sort the input array on the basis of the weights
	Edge *output = new Edge[n-1]; // Initialised an output array
	Set *set = new Set[n]; // Initialised different set for all vertices
	for(int i=0;i<n;i++){  // set rank and parent of each vertices for union rank algo
		set[i].rank = 0;
		set[i].parent = i;
	}
	int counter = 0,i = 0; //counter will tell how many edges are added in MST and i will take sorted edges from input
	while(counter<n-1) {
		Edge currentEdge = input[i];//input is already sorted by weight
		int sourceParent = find(set, currentEdge.src);
		int destinationParent = find(set, currentEdge.dest);
		if(sourceParent != destinationParent) {//if parent of src and dest is not equal that mean they lie in diffenrent set and donot form a cycle 
			output[counter] = currentEdge;
			Union(set, sourceParent, destinationParent);
			counter++;
		}
		i++;
	}
	//weight adding you can cout src to dest edges also
    int total_weight=0;
	for(int i=0;i<n-1;i++){
        total_weight+=output[i].weight;
    	}
        cout<<total_weight<<endl;
}

int main(int argc, char const *argv[]){
	int n, e;
	cin>>n>>e;
	Edge *input = new Edge[e];
	for(int i=0;i<e;i++){
		int s, d, w;
		cin>>s>>d>>w;
		input[i].src=s;
		input[i].dest=d;
		input[i].weight=w;
	}
    Kruskals(input,n,e);
}