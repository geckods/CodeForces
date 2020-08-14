#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	ll n,x;
    	cin>>n>>x;
    	ll ec=0;
    	ll y;
    	for(int i=0;i<n;i++){
    		cin>>y;
    		y%=2;
    		if(y==0)ec++;
    	}

    	ll oc=n-ec;

    	bool works=false;
    	if(x==n){
    		works = (oc%2)==1;
    	}
    	else{
    		if(ec==n){
    			works=false;
    		}
    		else if (oc==n){
    			works = (x%2)==1;
    		}
    		else{
    			works=true;
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
