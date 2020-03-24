#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll ans=0;

    for(int i=0;i<n;i++){
	    ll partone=0;
	    ll j=1;
	    while(arr[i]/j > 0) j*=10;
	    j/=10;

	    while(j>0){
	    	// cout<<arr[i]<<" "<<j<<" "<<arr[i]/j<<endl;
	    	ll mult = (j%MOD*j%MOD)%MOD;
	    	// if(mult<0) mult+=MOD;

	    	partone+=(((arr[i]/j)%10)*mult)%MOD;
	    	partone%=MOD;
	    	// if(j>1)
		    	// partone*=100;
	    	partone%=MOD;
	    	j/=10;
	    }

	    // partone/=100;

	    cout<<partone<<endl;

	    ans+=((n)*partone)%MOD;
	    ans%=MOD;
	    partone*=10;
	    partone%=MOD;
	    ans+=((n)*partone)%MOD;
	    ans%=MOD;
    }

    // if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}