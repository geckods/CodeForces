#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll t;
    cin>>t;

    while(t--){
    	ll n,k;
    	cin>>n>>k;

    	ll nbyk=n/k;

    	string s;
    	cin>>s;

    	// cerr<<s<<endl;

    	// letter i must match letter k-i
    	ll ans=0;
    	for(int i=0;i<k/2;i++){
    		ll minians=INT_MAX;
    		for(char c='a';c<='z';c++){
    			ll accum=0;
    			for(int j=0;j<nbyk;j++){
    				if(s[j*k+i]!=c)accum++;
    				if(s[(j+1)*k-i-1]!=c)accum++;
    				// cerr<<c<<" "<<j*k+i<<" "<<s[j*k+i]<<" "<<(j+1)*k-i-1<<" "<<accum<<endl;
    			}
    			// cerr<<c<<" "<<accum<<endl;
    			minians=min(minians,accum);
    		}
    		ans+=minians;
    		// if k is 4, 0-3,1-2
    		// if k is 3, 0-2,1-1
    	}
    	// cerr<<t<<" "<<ans<<endl;

    	if(k%2==1){
    		ll minians=INT_MAX;
    		for(char c='a';c<='z';c++){
    			ll accum=0;
    			for(int j=0;j<nbyk;j++){
    				if(s[j*k+k/2]!=c)accum++;
    			}
    			minians=min(minians,accum);
    		}
    		ans+=minians;    		
    	}
    	// if k is odd, extra choice
    	cout<<ans<<endl;
    }
}