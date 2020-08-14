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
        ll n;
        cin>>n;
        ll arr[n];
        priority_queue<pair<ll,ll> > myQ;
        myQ.push({n-1,0});
        ll i=1;
        ll r,l;
        ll assign;
        while(!myQ.empty()){
            pair<ll,ll> myPair=myQ.top();
            l=-myPair.second;
            r=l+myPair.first;

            // cerr<<l<<" "<<r<<endl;

            myQ.pop();
            ll assign=(l+r)/2;
            arr[assign]=i++;

            if(l<=assign-1){
                myQ.push({assign-1-l,-l});
            }

            if(r>=assign+1){
                myQ.push({r-(assign+1),-assign-1});
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }
}