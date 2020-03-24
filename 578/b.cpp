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
   		ll n,m,k;
   		cin>>n>>m>>k;

   		ll arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		bool can=true;
   		for(int i=0;i<n-1;i++){
   			m+=arr[i];
   			// arr[i]=0;
   			if(m<arr[i+1]-k){
   				can = false;
   				break;
   			}
   			else{
   				m-=max(0ll,arr[i+1]-k);
   			}
   		}

   		if(can){
   			cout<<"YES"<<endl;
   		}
   		else{
   			cout<<"NO"<<endl;
   		}
   	}
}