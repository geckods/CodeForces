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


#define MAXN 10000001

typedef pair<ll,ll> intpair;
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
        x = x / spf[x]; 
    } 
    return ret; 
} 

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
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
    vector<intpair>ans;

    // if odd, sum of two smallest pfs
    // if only one pf, not possible

    for(int i=0;i<n;i++){

    	map<ll,ll> pf = getFactorization(arr[i]);
    	if(arr[i]%2==1){
    		if(pf.size()==1){
    			ans.push_back({-1,-1});
    		}
    		else{
    			auto it = pf.begin();
    			intpair temp;
    			temp.first=it->first;
    			it++;
    			temp.second=it->first;
    			ans.push_back({temp});
    		}
    	}
    	else{
			ll tc=pf[2];
			vector<ll> temp;
			temp.push_back(1);
			for(auto it:pf){
				if(it.first==2)continue;
				temp.push_back(it.first);
			}
			bool done=false;
			for(ll a=0;a<temp.size();a++){
				for(ll b=0;b<temp.size();b++){
					if(a==b)continue;
					for(ll c=1;c<=tc;c++){
						ll tempk = pow(2ll,c)*temp[a]+temp[b];
						if(gcd(tempk,arr[i])==1){
							ans.push_back({pow(2ll,c)*temp[a],temp[b]});
							done=true;
							break;
						}
					}
					if(done)break;
				}
				if(done)break;	
			}
	    	if(!done){
	    		ans.push_back({-1,-1});
	    	}
    	}

    	// // cerr<<i<<" "<<m<<endl;
    	// ll m = pf.size();
    	// bool done=false;
    	// for(int a=0;a<m;a++){
    	// 	for(int b=a+1;b<m;b++){
    	// 		// cerr<<pf[a]<<" "<<pf[b]<<endl;
    	// 		if(gcd(pf[a]+pf[b],arr[i])==1){
    	// 			done=true;
    	// 			ans.push_back({pf[a],pf[b]});
    	// 			break;
    	// 		}
    	// 	}
    	// 	if(done)break;
    	// }
    }

    for(int i=0;i<n;i++){
    	cout<<ans[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
    	cout<<ans[i].second<<" ";
    }
    cout<<endl;

}