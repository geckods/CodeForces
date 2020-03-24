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

   	int t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		int n,k;
   		cin>>n>>k;
   		ll arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		ll mindiff = INT_MAX;
   		ll minind = -1;

   		for(int i=0;i<n-k;i++){
   			if(arr[i+k]-arr[i] < mindiff){
   				mindiff=arr[i+k]-arr[i];
   				minind=i;
   			}
   		}

   		// cout<<minind<<endl;

   		cout<<(arr[minind]+arr[minind+k])/2<<endl;
   	}
}