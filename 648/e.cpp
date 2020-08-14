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

bool ithBitSet(ll x, ll i){
	return (x&(1ll<<i))!=0;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> arr;
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	arr.push_back(x);
    }

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());

    ll ans=0;

    // cerr<<(1ll<<62)<<endl;

    for(ll theBit=62;theBit>=0;theBit--){
    	ll countSetBit=0;
    	ll i;
    	for(i=0;i<arr.size();i++){
    		// cerr<<arr[i]<<endl;
    		if(ithBitSet(arr[i],theBit)){
    			// cerr<<arr[i]<<" "<<theBit<<" "<<(arr[i]&(1ll<<theBit))<<endl;
    			countSetBit++;
    		}
    		else{
    			break;
    		}
    	}

    	// cerr<<theBit<<" "<<countSetBit<<endl;
    	// for(int j=0;j<arr.size();j++){
    	// 	cerr<<j<<" "<<arr[j]<<endl;
    	// }
    	// cerr<<endl;

    	if(countSetBit==0){
    		continue;
    	}
    	else{
    		while(arr.size()>=countSetBit+2){
    			arr.pop_back();
    		}
    		ans+=(1ll<<theBit);

    		for(ll i=0;i<countSetBit;i++){
				arr[i]^=(1ll<<theBit);
    		}

    		sort(arr.begin(),arr.end());
    		reverse(arr.begin(),arr.end());
    	}
    }
    cout<<ans<<endl;

}