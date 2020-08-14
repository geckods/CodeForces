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

typedef pair<ll,ll> intpair;

ll getCurrentIntersection(ll l1,ll r1,ll l2, ll r2){
    if(r1<=l2 || r2<=l1){
        return 0;
    }

    ll lb = max(l1,l2);
    ll rb = min(r1,r2);
    // cerr<<lb<<" "<<rb<<" "<<rb-lb<<endl;
    return rb-lb;
}

intpair getProfitableRange(ll l1,ll r1,ll l2, ll r2){
    ll gap=0;

    ll a1,b1,a2,b2;
    if(r1<r2 || (r1==r2 && l1<l2)){
        a1=l1;
        b1=r1;
        a2=l2;
        b2=r2;
    }
    else{
        a1=l2;
        b1=r2;
        a2=l1;
        b2=r1;        
    }

    gap=max(gap,a2-b1);
    ll profRange = max(r1,r2)-min(l1,l2)-getCurrentIntersection(l1,r1,l2,r2);
    return make_pair(gap,profRange);

}

ll getNumberRequired(ll toConv, intpair range, ll k){
    ll ans = range.first*toConv;
    if(range.second*toConv>=k){
        ans+=k;
        return ans;
    }
    k-=range.second*toConv;
    ans+=range.second*toConv;
    ans+=k*2;
    return ans;
}

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

        ll l1,r1,l2,r2;
        cin>>l1>>r1;
        cin>>l2>>r2;

        intpair profRange = getProfitableRange(l1,r1,l2,r2);
        ll currIntersection = getCurrentIntersection(l1,r1,l2,r2)*n;
        // cerr<<t<<" "<<currIntersection<<" "<<profRange.first<<" "<<profRange.second<<endl;
        if(currIntersection>=k){
            cout<<0<<endl;
            continue;
        }

        k-=currIntersection;

        ll ans=LLONG_MAX;

        if(profRange.first==0){
            ans=min(ans,k*2);
        }

        for(int i=1;i<=n;i++){
            ans=min(ans,getNumberRequired(i, profRange, k));
        }


        cout<<ans<<endl;
    }
}