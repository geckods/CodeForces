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

set<ll> primeFactors(ll n)  
{  
	set<ll> ans;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
    	ans.insert(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i*i <= n; i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
        	ans.insert(i);
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        ans.insert(n);
    return ans;
}  

ll calcForDiff(ll m, ll d, ll diff){
	return max(0ll,min(m,d)-diff);
}

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
    	ll m,d,w;
    	cin>>m>>d>>w;

    	set<ll> pf = primeFactors(w);
    	ll ans=0;
    	ans+=calcForDiff(m,d,w);
    	// cerr<<ans<<endl;

    	for (auto p: pf){
    		if((d)%(w/p)==1){
    			ans+=calcForDiff(m,d,p);
    			// cerr<<t<<" "<<p<<" "<<ans<<endl;
    		}
    	}
    	cout<<ans<<endl;
    }
}