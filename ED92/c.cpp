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
        // periodic with period of 2
        ll ans=INT_MAX;

        // bool done=true;
        // for(int i=0;i<n-1;i++){
        //     if(s[i]!=s[i+1]){
        //         done=false;
        //         break;
        //     }
        // }

        // if(done){
        //     cout<<0<<endl;
        //     continue;
        // }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                bool onI=true;
                ll del=0;
                for(int k=0;k<n;k++){
                    if(((onI) && s[k]-'0'==i)||((!onI) && s[k]-'0'==j)){
                        // if(i==1 && j==0)cerr<<k<<endl;
                        onI=!onI;
                    }
                    else{
                        del++;
                    }
                }
                // cerr<<i<<" "<<j<<" "<<del<<endl;
                if(!onI && i!=j)del++;
                ans=min(ans,del);
            }
        }
        cout<<ans<<endl;
    }
}