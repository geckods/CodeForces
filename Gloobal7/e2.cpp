#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll p[n];
    map<ll,ll> myMap;
    for(int i=0;i<n;i++){
    	cin>>p[i];
    	myMap[p[i]]=i;
    }

    ll q[n];
    for(int i=0;i<n;i++){
    	cin>>q[i];
    	q[i]--;
    }

    vector<ll> ans;

    for(int i=n-1;i>=0;i--){
        ans.push_back(p[q[i]]);
        cerr<<ans[ans.size()-1]<<endl;
    }



    ll miniAns=0;
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    //i need prefix maximums with index in quick time

}    