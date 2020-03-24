#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	vector<intpair> pairVec;
    	int n;
    	cin>>n;

    	vector<set<ll> > myVec(n);

    	ll a,b;
    	for(int i=0;i<n;i++){
    		cin>>a>>b;
    		pairVec.push_back(make_pair(a,b));
    		myVec[a].insert(b);
    	}

    	vector<int> asdf;
    	for(int i=n-1;i>=0;i--){
    		
    	}

    }