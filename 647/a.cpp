#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

#define MAXN 500001
vector<ll> adj[MAXN];

typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    vector<intpair> edgeVec;

    ll a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
        edgeVec.push_back({a,b});
    }

    ll t[n];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }

    vector<intpair> newVec;

    for(int i=0;i<m;i++){
        if(t[edgeVec[i].first]==t[edgeVec[i].second]){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll getsc[n];
    for(int i=0;i<n;i++){
        getsc[i]=1;
    }

    for(int i=0;i<n;i++){
        newVec.push_back({t[i],i});
    }

    sort(newVec.begin(),newVec.end());

    vector<ll> ans;
    for(int i=0;i<n;i++){

        ll k = newVec[i].second;

        if(getsc[k]!=t[k]){
            // cerr<<i<<" "<<getsc[i]<<" "<<t[i]<<endl;
            cout<<-1<<endl;
            return 0;
        }

        for(auto j:adj[k]){
            if(getsc[j]==t[k])
                getsc[j]=t[k]+1;
        }

        ans.push_back(k+1);
    }

    for(auto j:ans){
        cout<<j<<" ";
    }
    cout<<endl;

}