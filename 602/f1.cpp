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

#define MAXN 2000
#define MOD 998244353


ll ncr[MAXN+1][MAXN+1];
void nCr(){
	ncr[0][0]=1;

    for(ll i = 1; i <= MAXN; i++) {
        ncr[i][0] = 1; // C(i, 0) = 1
        for(ll j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            ncr[i][j]%=MOD;
        }
    }
}

ll power(ll x, ll y)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % MOD; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % MOD;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % MOD;  
    }  
    return res;  
}  


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    nCr();

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll eqCount=0;
    for(int i=0;i<n;i++){
    	if(arr[(i+1)%n]==arr[i])eqCount++;
    }
    ll neqCount=n-eqCount;
    cerr<<eqCount<<" "<<neqCount<<endl;

    ll mult = power(k,eqCount);
    ll ans=0;

    for(int i=0;i<=neqCount/2;i++){
    	// number of correct->incorrects
    	for(int j=i+1;j<=neqCount-i;j++){
    		// number of incorrects->corrects

    		if(k==2 && i+j<neqCount)continue;

    		ll rem=neqCount-i-j;
    		ll temp=ncr[neqCount][i];
    		temp*=ncr[neqCount-i][j];
    		temp%=MOD;
    		temp*=max(1ll,power(k-2,rem));
    		temp%=MOD;

    		// cerr<<i<<" "<<j<<" "<<temp<<endl;

    		ans+=temp;
    		ans%=MOD;
    	}
    }
    ans*=mult;
    ans%=MOD;
    cout<<ans<<endl;

}