#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,m,k;
   	cin>>n>>m>>k;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	priority_queue<pair<ll,ll> >myPQ;
   	for(int i=0;i<n;i++){
   		myPQ.push(make_pair(arr[i],i));
   	}

   	bool ismax[n];
   	for(int i=0;i<n;i++){
   		ismax[i]=false;
   	}

   	ll sum=0;
   	for(int i=0;i<m*k;i++){
   		pair<ll,ll> myPair = myPQ.top();
   		myPQ.pop();

   		ismax[myPair.second]=true;
   		sum+=myPair.first;
   	}

   	int ismaxcount=0;
   	int printcount=0;
   	cout<<sum<<endl;
   	for(int i=0;i<n;i++){
   		if(printcount==k-1)break;
   		if(ismax[i]){
   			ismaxcount++;
   		}
   		if(ismaxcount==m){
   			ismaxcount=0;
   			printcount++;
   			cout<<i+1<<" ";
   		}
   	}

}
