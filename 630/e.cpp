#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
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

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
    if (g != 1) 
    	return 0;
    else
    { 
		return power(a, m-2, m); 
    } 
} 
 















int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,L,R;
    cin>>n>>m>>L>>R;

    ll ans;

    if((n*m)%2==1){
	    // if n*m is odd -> anything goes, as either oddc or evenc must be even
    	ans=power((R-L+1),n*m,MOD);
    }
    else{
    	//if n*m is even, I need an even number of even numbers
    	if((R-L)%2==1){
    		ans=power((R-L+1),n*m,MOD);
    		ans*=modInverse(2,MOD);
    		ans%=MOD;
    	}
    	else{
    		// there's an extra even or odd
    		if(R==L){
    			ans=1;
    		}
    		else{
	    		ans=(power((R-L+1),n*m/2,MOD))%MOD;
	    		ans*=modInverse(2,MOD);
	    		ans%=MOD;
    		}
    	}
    }
    cout<<ans<<endl;
}
