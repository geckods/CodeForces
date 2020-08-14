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
    	ll x,y;
    	cin>>x>>y;
    	ll a,b;
    	cin>>a>>b;
    	if(b>2*a){
    		cout<<(x+y)*a<<endl;
    	}
    	else{
    		ll ans=min(x,y)*b+(max(x,y)-min(x,y))*a;
    		cout<<ans<<endl;
    	}
    }

}
