#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int main(){

	// =
	
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
    	ll n;
    	cin>>n;
    	ll a[n];
    	ll b[n];
    	for(int i=0;i<n;i++){
    		cin>>a[i]>>b[i];
    	}

    	ll c[n];
    	ll csum=0;
    	for(int i=0;i<n;i++){
    		if(i==0){
    			c[i]=a[i]-b[n-1];
    		}
    		else{
    			c[i]=a[i]-b[i-1];
    		}
    		c[i]=max(c[i],0ll);
    		csum+=c[i];
    	}

    	ll ans=LLONG_MAX;

    	for(int i=0;i<n;i++){
    		ans=min(ans,csum-c[i]+a[i]);
    	}
    	cout<<ans<<endl;
    }
}
