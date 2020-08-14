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

    while(t--){
        ll n;
        cin>>n;

        set<ll> mySet;
        map<ll,ll> myMap;
        ll x;
        ll maxRep=0;
        for(int i=0;i<n;i++){
            cin>>x;
            mySet.insert(x);
            myMap[x]++;
            maxRep=max(maxRep,myMap[x]);
        }

        ll ans=INT_MAX;
        ans=min(ans,(ll)mySet.size());
        ans=min(ans,maxRep);
        if(maxRep==mySet.size())ans--;
        ans=min(ans,n/2);
        cout<<ans<<endl;

        // cout<<min(min((ll)mySet.size(),maxRep),n/2)<<endl;
    }
}