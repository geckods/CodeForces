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

    int t;
    cin>>t;

    while(t--){
    	ll n,x;
    	cin>>n>>x;

    	ll arr[n];
    	ll themax=INT_MIN;
    	set<ll> mySet;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		themax=max(themax,arr[i]);
    		mySet.insert(arr[i]);
    	}

    	ll ans=ceil(((double)x)/themax);

    	if(ans==1 && mySet.find(x)==mySet.end())ans++;
    	cout<<ans<<endl;

    }
}