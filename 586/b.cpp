#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	ll arr[n][n];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cin>>arr[i][j];
   		}
   	}

   	ll ansarr[n];

   	for(int i=0;i<n;i++){
   		ll ans=0;
   		for(int j=0;j<n;j++){
   			if(i==j)continue;
   			if(ans==0)ans=arr[i][j];
   			else{
   				ans=gcd(ans,arr[i][j]);
   			}
   		}
   		ansarr[i]=ans;
   	}

   	for(int i=0;i<n;i++){
   		ll commonfac=0;
   		for(int j=0;j<n;j++){
   			if(i==j)continue;
   			if(commonfac==0){
   				commonfac=(ansarr[i]*ansarr[j])/arr[i][j];
   			}
   			else{
   				commonfac=gcd(commonfac,(ansarr[i]*ansarr[j])/arr[i][j]);
   			}
   		}
   		ansarr[i]/=commonfac;
   	}

   	for(int i=0;i<n;i++){
   		cout<<ansarr[i]<<" ";
   	}

   	cout<<endl;
}