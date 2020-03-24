#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 200000

int parent[MAXN];
int myrank[MAXN];


void make_set(int v) {
    parent[v] = v;
    myrank[v] = 0;
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (myrank[a] < myrank[b])
            swap(a, b);
        parent[b] = a;
        if (myrank[a] == myrank[b])
            myrank[a]++;
    }
}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	memset(parent,0,sizeof(parent));
   	memset(myrank,0,sizeof(myrank));

   	int n,m;
   	cin>>n>>m;

   	for(int i=0;i<n;i++){
   		make_set(i);
   	}

   	int x,y;
   	for(int i=0;i<m;i++){
   		cin>>x>>y;
   		x--;
   		y--;

   		union_sets(x,y);
   	}

   	int edgecount=0;

   	int i=0,j;

   	map<int,int> minOcc;
   	map<int,int> maxOcc;

   	for(int i=0;i<n;i++){
   		minOcc[find_set(i)]=-1;
   		maxOcc[find_set(i)]=i;
   	}

   	for(int i=0;i<n;i++){
   		if(minOcc[find_set(i)]==-1){
   			minOcc[find_set(i)]=i;
   		}
   	}

   	int curr,currmax;
   	while(i<n){
   		curr=find_set(i);
   		currmax=maxOcc[find_set(i)];

   		j=i+1;
   		while(j<=currmax){
   			if(find_set(j)!=find_set(i)){
   				currmax=max(currmax,maxOcc[find_set(j)]);
   				edgecount++;
   				union_sets(j,i);
   			}
   			j++;
   		}

   		i=currmax+1;
   	}

   	cout<<edgecount<<endl;
}