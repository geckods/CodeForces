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

        vector<pair<ll,ll> > myVec;

        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            myVec.push_back({a[i],0});
        }
        ll b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
            myVec.push_back({b[i],1});
        }

        sort(myVec.begin(),myVec.end());
        reverse(myVec.begin(),myVec.end());

        int i=0;
        int j=0;
        int c=0;
        int ans=0;
        while(i<2*n && c<n){
            if(myVec[i].second && j==k){
                i++;
                continue;
            }
            ans+=myVec[i].first;
            j+=myVec[i].second;
            c++;
            i++;
            // cerr<<i<<" "<<ans<<endl;
        }
        cout<<ans<<endl;


    }
}