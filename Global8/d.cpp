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

    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll bitarr[20];
    memset(bitarr,0,sizeof(bitarr));
    for(int i=0;i<n;i++){
        ll temp=arr[i];
        int theBit=0;
        while(temp>0){
            bitarr[theBit]+=(temp&1);
            theBit++;
            temp=temp>>1;
        }
    }

    ll ans=0;

    while(1){
        ll temp=0;
        for(int i=0;i<20;i++){
            if(bitarr[i]>0){
                bitarr[i]--;
                temp|=(1<<i);
            }
        }

        if(temp==0)break;
        ans+=temp*temp;

    }
    cout<<ans<<endl;
}