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
        ll n,m;
        cin>>n>>m;

        ll arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        ll oc[n+m];
        memset(oc,0,sizeof(oc));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll cd = i+j;
                if(cd==n+m-2-i-j)continue;
                cd=min(cd,n+m-2-i-j);
                // cerr<<i<<" "<<j<<" "<<cd<<endl;
                oc[cd]+=arr[i][j];
            }
        }

        ll ans=0;
        for(int i=0;i<n+m-2;i++){
            ll toAdd = oc[i];
            toAdd=min(toAdd,min((i+1)*2ll,min(n,m)*2)-oc[i]);
            // cerr<<t<<" "<<i<<" "<<toAdd<<endl;
            ans+=toAdd;
        }
        cout<<ans<<endl;

    }
}