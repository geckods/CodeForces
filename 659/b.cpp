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
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll bitc[32];
    	memset(bitc,0,sizeof(bitc));

    	for(int i=0;i<n;i++){
    		ll x = arr[i];
    		ll z = 0;
    		// cerr<<i<<" "<<x<<endl;
    		while(x){
    			bitc[z]+=x&1;
    			x=x>>1;
    			z++;
    		}
    		// cerr<<i<<" "<<bitc[0]<<" "<<bitc[1]<<endl;
    	}

    	bool done=false;
    	for(int i=31;i>=0;i--){
    		// cerr<<i<<" "<<bitc[i]<<endl;
    		if(bitc[i]%2==0)continue;
    		done=true;
    		if(bitc[i]%4==1){
				cout<<"WIN"<<endl;
    		}
    		else{
    			if((n-bitc[i])%2==0){
    				cout<<"LOSE"<<endl;
    			}
    			else{
    				cout<<"WIN"<<endl;
    			}
    		}
    		break;
    	}
    	if(!done){
    		cout<<"DRAW"<<endl;
    	}

    }
}