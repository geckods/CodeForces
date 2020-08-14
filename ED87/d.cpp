#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/detail/standard_policies.hpp>
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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;

    FenwickTree ft = FenwickTree(n+1);
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	ft.add(x,1);
    }

    for(int i=0;i<q;i++){
    	cin>>x;
    	if(x<0){
    		ll bmin=1;
    		ll bmax=n;
    		while(bmin<bmax){
    			ll bmid=(bmin+bmax)/2;
    			if(ft.sum(bmid)<abs(x)){
    				bmin=bmid+1;
    			}
    			else{
    				bmax=bmid;
    			}
    		}
    		ft.add(bmin,-1);
    	}
    	else{
    		ft.add(x,1);
    	}
    }

    if(ft.sum(n)==0){
    	cout<<0<<endl;
    }
    else{
    	for(int i=1;i<=n;i++){
    		if(ft.sum(i)>0){
    			cout<<i<<endl;
    			return 0;
    		}
    	}
    }
}