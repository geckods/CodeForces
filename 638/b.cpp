#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

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
    	ll n,k;
    	cin>>n>>k;
    	vector<ll> myVec;
    	ll x;

    	bool seen[n+1];
    	memset(seen,false,sizeof(seen));

    	ll uc=0;

    	for(int i=0;i<n;i++){
    		cin>>x;
    		myVec.push_back(x);
    		if(!seen[x]){
    			seen[x]=true;
    			uc++;
    		}
    	}

    	if(uc>k){
    		cout<<-1<<endl;
    		continue;
    	}

    	vector<ll> ans;
    	vector<ll> pattern;
    	for(int i=1;i<=n;i++){
    		if(seen[i]){
    			pattern.push_back(i);
    			// cerr<<i<<endl;
    		}
    	}

    	while(pattern.size()<k){
    		pattern.push_back(myVec[0]);
    	}

    	ll mainPointer=0;
    	ll patPointer=0;

    	while(mainPointer<n){
    		if(myVec[mainPointer]==pattern[patPointer]){
    			mainPointer++;
    		}
    		ans.push_back(pattern[patPointer]);
    		patPointer++;
    		patPointer%=pattern.size();
    	}

    	cout<<ans.size()<<endl;
    	for(int i=0;i<ans.size();i++){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
}