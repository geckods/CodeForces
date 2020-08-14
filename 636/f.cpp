#include <bits/stdc++.h>
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


    ll t;
    cin>>t;
    while(t--){

    	ll n;
    	cin>>n;
    	vector<vector<ll>> myVec;
    	ll k,x;

    	ll count[n];
    	memset(count,0,sizeof(count));

    	for(int i=0;i<n-1;i++){
    		cin>>k;
    		myVec.push_back(vector<ll>());
    		for(int j=0;j<k;j++){
    			cin>>x;
    			myVec[i].push_back(x);
    			count[x]++;
    		}
    	}