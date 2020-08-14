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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        ll prefix[n];
        prefix[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1];
            prefix[i]+=s[i]-'0';
        }

        ll dp[n]; //minimum number of moves to make it periodic from here till the end in k
        ll miniDP=0;
        bool seenOne=false;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')seenOne=true;
            if(!seenOne){
                dp[i]=0;
                continue;
            }

            miniDP=0;
            if(i+k<n){
                miniDP=dp[i+k];
            }

            miniDP+=prefix[min(n-1,i+k-1)];
            miniDP-=prefix[i];

            ll oa=prefix[n-1];
            oa-=prefix[i];


            if(s[i]=='0')miniDP++;
            miniDP=min(miniDP,oa);
            dp[i]=miniDP;
            // cerr<<i<<" "<<dp[i]<<endl;
        }

        ll ans=dp[0];
        for(int i=0;i<n-1;i++){
            ans=min(ans,prefix[i]+dp[i+1]);
        }
        cout<<ans<<'\n';

    }
}