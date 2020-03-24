#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

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

    ll w,h;
    cin>>w>>h;

    cout<<(((4*power(2,w-1,MOD))%MOD)*power(2,h-1,MOD))%MOD<<endl;
}


