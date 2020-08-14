#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000007

#define MAXN 2000001

ll ans[MAXN];
// ll ans2[MAXN];

void precom(){
	ans[1]=0;
	ans[2]=0;
	ans[3]=1;
	ans[4]=1;

	// ans[4]=1;
	for(int i=5;i<MAXN;i++){
		// cerr<<" "<<i<<" "<<2*ans[i-2]+ans[i-1]<<" "<<1+4*(ans[i-3]+ans[i-4])+ans[i-2]<<endl;
		if(i%3==0){
			ans[i]=(1+4*(ans[i-3]+ans[i-4])+ans[i-2]);
		}
		else{
			ans[i]=2*ans[i-2]+ans[i-1];
		}
		// ans[i]=4+4*(ans[i-3]+ans[i-4])+ans[i-2];
		// ans[i]=2*ans[i-2]+ans[i-1];//max(/*2*ans[i-2]+ans[i-1]*/0ll,4*(ans[i-3]+ans[i-4])+ans[i-2]);
		// cerr<<2*ans[i-2]+ans[i-1]<<" "<<4*(ans[i-3]+ans[i-4])+ans[i-2]<<endl;
		// ans[i]*=4;
		ans[i]%=MOD;
		ans[i]%=MOD;
	}
}

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

    precom();

 	ll t;
 	cin>>t;
 	while(t--){
 		ll n;
 		cin>>n;
 		cout<<(ans[n]*4)%MOD<<"\n";
 	}
}
