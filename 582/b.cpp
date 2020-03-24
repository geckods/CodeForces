#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
		freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n;
    	cin>>n;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll currmin=INT_MAX;
    	ll count=0;
    	for(int i=n-1;i>=0;i--){
    		if(arr[i]<=currmin){
    			currmin=arr[i];
    		}
    		else{
    			count++;
    		}
    	}
    	cout<<count<<endl;
    }
}