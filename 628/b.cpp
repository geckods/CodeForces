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

    //=
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        set<ll> mySet;
        for(int i=0;i<n;i++){
            mySet.insert(arr[i]);
        }
        cout<<mySet.size()<<endl;
    }

}
