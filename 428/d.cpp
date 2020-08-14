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

#define MAXVAL 1000001
#define MOD 1000000007
ll countArr[MAXVAL];
ll parSeen[MAXVAL];
ll spf[MAXVAL]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXVAL; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXVAL; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXVAL; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXVAL; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j]=i; 
        } 
    } 
} 


unordered_set<ll> getFactorization(ll x) 
{ 
    unordered_set<ll> ret; 
    while (x != 1) 
    { 
        ret.insert(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

ll factorCount(ll x){
	ll ans=0;
    while (x != 1) 
    { 
        ans++; 
        x = x / spf[x]; 
    } 
    return ans;
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

ll myFunc(ll x){
	return (x*power(2,x-1,MOD) + power(2,x,MOD) - 1)%MOD;
}

ll recurseDown(ll x){

	if(x==1)return 0;

	ll ans=0;

	countArr[x]++;
	ans+=x;
	ans+=x*max(myFunc(countArr[x]-1),0ll);
	ans%=MOD;
	parSeen[x]=countArr[x];		

	// ans+=x*myFunc(countArr[x]-1);


	queue<ll> myQ;
	ll fc = factorCount(x);
	set<ll> toProcess;
	set<ll> newToProcess;
	toProcess.insert(x);

	bool firstIter=true;

	while(*toProcess.begin()>1){
		for(auto j:toProcess){
			if(!firstIter)
				countArr[j]++;

			// cerr<<j<<" "<<countArr[j]<<" "<<parSeen[j]<<" "<<x<<" "<<j*myFunc(countArr[j]-parSeen[j])<<endl;

			ans+=j*max(power(2,parSeen[j]-1,MOD)*myFunc(countArr[j]-parSeen[j]),0ll);
			ans%=MOD;

			unordered_set<ll> fact = getFactorization(j);

			for(auto k:fact){
				parSeen[j/k]+=countArr[j];
				newToProcess.insert(j/k);
			}

			parSeen[j]=0;
		}
		firstIter=false;

		toProcess=newToProcess;
		newToProcess.clear();
	}

	return ans;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(countArr,0,sizeof(countArr));
    memset(parSeen,0,sizeof(parSeen));
    sieve();

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll ans=0;

    for(int i=0;i<n;i++){
    	// if(arr[i]==1)continue;
    	ans+=recurseDown(arr[i]);
    	ans%=MOD;
    	// cerr<<i<<" "<<arr[i]<<" "<<ans<<endl;
    }
    cout<<ans<<endl;

}
