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

    	ll n = s.length();

    	ll prefixOnes[n];
    	if(s[0]=='1')prefixOnes[0]=1;
    	else prefixOnes[0]=0;

    	for(int i=1;i<n;i++){
    		prefixOnes[i]=prefixOnes[i-1];
    		if(s[i]=='1')prefixOnes[i]++;
    	}

    	ll prefixZeroes[n];

    	for(int i=0;i<n;i++){
    		prefixZeroes[i]=i+1-prefixOnes[i];
    	}

    	ll ans=INT_MAX;
    	for(int i=0;i<n;i++){
    		ans=min(ans,prefixOnes[i]+prefixZeroes[n-1]-prefixZeroes[i]);
    		ans=min(ans,prefixZeroes[i]+prefixOnes[n-1]-prefixOnes[i]);
    	}
    	cout<<ans<<endl;
    }
}