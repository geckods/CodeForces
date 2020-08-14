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

    ll n;
    cin>>n;
    while(n--){
    	string s;
    	cin>>s;
    	
    	ll numDig = s.length()-4;
    	ll num = stoi(s.substr(4,20));

    	ll minBound = 1988;

    	for(ll i=1;i<=numDig;i++){
    		ll newNum = num%(ll)(pow(10ll,i));
    		// cerr<<i<<" "<<newNum<<" "<<minBound<<endl;
    		while(newNum<=minBound){
    			newNum+=(ll)pow(10ll,i);
    		}
    		minBound=newNum;
    		// cerr<<i<<" "<<newNum<<" "<<minBound<<endl;
    	}

    	cout<<minBound<<endl;
    }
}
