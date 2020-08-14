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
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;

    	if(b>=a){
    		cout<<b<<endl;
    		continue;
    	}
    	a-=b;
    	if(c<=d){
    		cout<<-1<<endl;
    		continue;
    	}

    	ll sleepTime=c-d;

    	cout<<b+(ll)ceil(((double)(a))/sleepTime)*c<<endl;

    }

}
