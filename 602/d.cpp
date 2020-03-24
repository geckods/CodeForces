#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
	// reverse(arr.begin(),arr.end());

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i].second<<endl;
	// }

	// cout<<arr.size()<<endl;
// 
	for(int i=0;i<m;i++){
		// tempVec.clear()
		vector<pair<ll,ll> > tempVec;
		for(int j=0;j<req[i].first;j++){
			tempVec.push_back({arr[j].second,arr[j].first});
		}
		sort(tempVec.begin(),tempVec.end());
		// cout<<tempVec.size()<<endl;
		cout<<tempVec[req[i].second-1].second<<endl;
	}
}