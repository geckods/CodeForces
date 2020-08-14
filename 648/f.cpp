#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

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
    	ll a[n];
    	ll b[n];
    	map<ll,ll> aMap;
    	map<ll,ll> bMap;

    	map<ll,ll> aLoc;
    	map<ll,ll> bLoc;

    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		aMap[a[i]]++;
    	}


    	for(int i=0;i<n;i++){
    		cin>>b[i];
    		bMap[b[i]]++;
    	}

    	bool works=true;
    	if(n%2==1 && a[n/2]!=b[n/2]){
    		works=false;
    	}

    	if(works){
	    	for(auto it:aMap){
	    		if(it.second!=bMap[it.first]){
	    			works=false;
	    			break;
	    		}
	    	}    		
    	}




    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    }
}