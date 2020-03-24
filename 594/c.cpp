#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007


ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll m;
    cin>>m;

    ll a = min(n,m);
    ll b = max(n,m);


	ll odp[b][2];
	odp[b-1][0]=1;
	odp[b-1][1]=0;

	for(int i=b-2;i>=0;i--){
		odp[i][0]=odp[i+1][0]+odp[i+1][1];
		odp[i][1]=odp[i+1][0];
		odp[i][0]%=MOD;
		odp[i][1]%=MOD;
	}


    cout<<(2*(odp[0][0]+odp[0][1]+odp[b-a][0]+odp[b-a][1]-1))%MOD<<endl;
}