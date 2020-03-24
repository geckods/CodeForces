#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
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
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    //there are n positions


    for(int i=1;i<=n;i++){
    	//there are 2 pos

    	//there are n-i+1 starting positions
    	//two of them have one fix, all others have two fixes
    	ll ans=0;

    	ans+=(n-i-1)*9*9*10*power(10,n-i-2,MOD);
    	ans%=MOD;
    	ans+=(2)*9*power(10,n-i-1,MOD)*10;
    	ans%=MOD;




    	if(i==n){
    		cout<<10<<endl;
    	}
    	else{
    		cout<<ans<<endl;
    	}
    }
}