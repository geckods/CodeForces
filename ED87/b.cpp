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
    	string s;
    	cin>>s;

    	ll n=s.length();
    	ll curr1,curr2,curr3;
    	curr1=curr2=curr3=n;
    	ll ans=INT_MAX;
    	for(int i=n-1;i>=0;i--){
    		if(s[i]=='1')curr1=i;
    		else if (s[i]=='2')curr2=i;
    		else curr3=i;

    		if(curr1==n||curr2==n||curr3==n)continue;
    		ans=min(ans,max(max(curr1,curr2),curr3)-i+1);
    	}
    	if(ans==INT_MAX)ans=0;
    	cout<<ans<<"\n";
    }
}