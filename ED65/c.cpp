#include <bits/stdc++.h>
using namespace std;

int getParent(int arr[], int x){
	if(arr[x]==x){
		return x;
	}
	else{
		arr[x]=getParent(arr,arr[x]);
		return arr[x];
	}
}

void setParent(int x, int y, int arr[]){
	if(arr[y]==y){
		arr[getParent(arr,x)]=y;
	}
	else{
		arr[getParent(arr,x)]=getParent(arr,y);
	}
	getParent(arr,x);
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,m;
   	cin>>n>>m;

   	int groupcount=0;

   	int parent[n];
   	for(int i=0;i<n;i++){
   		parent[i]=i;
   	}

   	for(int i=0;i<m;i++){

   		// for(int i=0;i<n;i++){
   		// 	cerr<<parent[i]<<" ";
   		// }
   		// cerr<<endl;



   		int z;
   		cin>>z;

   		if(z==0)continue;

   		int arrx[z];
   		for(int j=0;j<z;j++){
   			cin>>arrx[j];
   			arrx[j]--;
   		}

   		int par=-1;

   		for(int j=0;j<z;j++){
   			if(par==-1){
   				par=getParent(parent,arrx[j]);
   			}
   			else{
   				setParent(arrx[j],par,parent);
   			}
   		}


   	}

   	for(int i=0;i<n;i++){
   		getParent(parent,i);
   	}


   	map<int,int> countMap;

   	for(int i=0;i<n;i++){
   		countMap[parent[i]]++;
   	}

   	for(int i=0;i<n;i++){
   		cout<<countMap[parent[i]]<<" ";
   	}
   	cout<<endl;

}
