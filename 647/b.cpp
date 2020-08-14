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

#define MOD 1000000007

ll power(ll x, ll y, ll p)  
{  
    ll res = 1ll;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0ll) return 0ll; // In case x is divisible by p; 
  
    while (y > 0ll)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1ll)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1ll; // y = y/2  
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

	ll t;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;


		ll arr[n];
		map<ll,ll> myMap;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			myMap[arr[i]]++;
		}

		if(p==1){
			if(n%2ll==0ll){
				cout<<0ll<<endl;
			}
			else{
				cout<<1ll<<endl;
			}
			continue;
		}

		

		vector<ll> keys;
		for (auto it:myMap){
			keys.push_back(it.first);
		}

		sort(keys.begin(),keys.end());
		reverse(keys.begin(),keys.end());

		ll i=0;

		bool done=false;

		bool seenX[keys.size()];
		memset(seenX, false, sizeof(seenX));

		while(i<keys.size()){
			// cerr<<"HI"<<" "<<i<<endl;

			ll ikey=keys[i];

			myMap[ikey]&=1ll;
			if(myMap[ikey]==0 || seenX[i]){
				i++;
				continue;
			}
			else{
				ll j=i+1;
				if(j==keys.size()){
					done=true;
					break;
				}
				ll jkey=keys[j];
				ll req=1;

				for(ll z=ikey;z>jkey;z--){
					req*=p;
					if(req>n){
						done=true;
						break;
					}
				}

				// cerr<<req<<endl;


				while(j<keys.size()){
					jkey=keys[j];
					// cerr<<j<<" "<<req<<endl;
					if(myMap[jkey]>=req){
						myMap[jkey]-=req;
						i=j;
						break;
					}
					else{
						if(req>n || j==keys.size()-1){
							done=true;
							break;
						}
						else{
							req-=myMap[jkey];
							// seenX[j]=true;
							for(ll z=jkey;z>keys[j+1];z--){
								req*=p;
								if(req>n){
									done=true;
									break;
								}
							}

							if(done)break;
							j++;
						}
					}
				}
				if(j==keys.size())break;
			}

			if(done)break;
		}

		// cerr<<i<<endl;

		if(i==keys.size()){
			cout<<0<<endl;
			continue;
		}

		ll ans=power(p,keys[i],MOD);
		// ans*=myMap[keys[i]];
		ans%=MOD;

		ll sub;

		for(ll j=i+1;j<keys.size();j++){
			sub=power(p,keys[j],MOD);
			sub*=myMap[keys[j]];
			sub%=MOD;
			ans-=sub;
			ans%=MOD;
		}
		if(ans<0)ans+=MOD;

		cout<<ans<<endl;
	}    
}
