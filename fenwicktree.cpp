#include<bits/stdc++.h>
using namespace std;

int a[10000];
int Bit[10000]={0};

//Range Sum Querry
void update(int i,int inc,int N){
	while(i<=N){
		Bit[i]+=inc;
		i+=(i&(-i));
	}
}

int querry(int i){
	int ans=0;
	while(i>=0){
		ans+=Bit[i];
		i-=(i&(-i));
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i])
	}
	// querry
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<querry(r)-querry(l-1)<<endl;
	}
	return 0;
}
