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

#define MAXN 200001 
  
// stores smallest prime factor for every number 
ll spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
map<ll,ll> getFactorization(ll x) 
{ 
    map<ll,ll> ret; 
    while (x != 1) 
    { 
    	ret[spf[x]]++;
        // ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

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

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    map<ll,ll> myMapMin;
    map<ll,ll> myMapMax;
    map<ll,ll> countMap;

    for(int i=0;i<n;i++){
	    // cerr<<"HI"<<endl;
    	map<ll,ll> factors=getFactorization(arr[i]);

    	for(auto a:factors){
    		countMap[a.first]++;
    		// cerr<<arr[i]<<" "<<a.first<<" "<<a.second<<endl;
    		if(myMapMin[a.first]==0){
    			myMapMin[a.first]=a.second;
    		}
    		else{
    			if(a.second<myMapMin[a.first]){
    				myMapMax[a.first]=myMapMin[a.first];
    				myMapMin[a.first]=a.second;
    			}
    			else if (myMapMax[a.first]==0 || a.second<myMapMax[a.first]){
    				myMapMax[a.first]=a.second;    				
    				// cerr<<a.first<<" "<<a.second<<endl;
    			}
    		}
    	}
    }


    ll ans=1;
    for(auto a:myMapMin){
    	// cerr<<a.first<<" "<<a.second<<endl;
    	if(countMap[a.first]>n-2){
    		if(countMap[a.first]==n){
		    	ans*=power(a.first,myMapMax[a.first],INT_MAX);
    		}
    		else{
		    	ans*=power(a.first,a.second,INT_MAX);    			
    		}
    	}
    }
    cout<<ans<<endl;
}
