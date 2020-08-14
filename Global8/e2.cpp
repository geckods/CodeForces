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

#define endl '\n'

typedef pair<ll,ll> intpair;

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

        ll arr[n];
        memset(arr,0,sizeof(arr));

        vector<intpair> myVec;

        ll x,y;
        vector<ll> outwards[n];
        vector<ll> inwards[n];

        for(int i=0;i<m;i++){
            cin>>x>>y;
            x--;
            y--;
            outwards[x].push_back(y);
            inwards[y].push_back(x);

            myVec.push_back({x,y});
        }

        

        cout<<endl;
    }
}

