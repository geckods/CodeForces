#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update



using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

bool mycompare(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first>b.first){
		return true;
	}
	else if (a.first<b.first){
		return false;
	}
	else{
		return(a.second<b.second);
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
	cin>>n;

	vector<pair<ll,ll> > arr;
	
	ll x,y;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back({x,i});
	}

	ll m;
	cin>>m;

	vector<pair<ll,ll> > req;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		req.push_back({x,y});
	}


	sort(arr.begin(),arr.end(),mycompare);

	map<ll,vector<pair<ll,ll> > > querMap;

	for(int i=0;i<m;i++){
		querMap[req[i].first].push_back({req[i].second-1,i});
	}

	map<ll,vector<ll> > ansMap;

	ordered_set mySet; 


	ll ans[m];

	for(int i=0;i<n;i++){
		mySet.insert({arr[i].second,arr[i].first});

		// if(i==1){
		// 	for(auto it = mySet.begin();it!=mySet.end();it++){
		// 		cout<<(*it).first<<" "<<(*it).second<<endl;
		// 	}
		// }

		for(int j=0;j<querMap[i+1].size();j++){
			// cout<<i<<" "<<" "<<querMap[i+1][j].first<<" "<<querMap[i+1][j].second<<endl;
			ans[querMap[i+1][j].second]=(*mySet.find_by_order(querMap[i+1][j].first)).second;
		}
	}

	for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
	}

}