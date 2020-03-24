#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

// typedef pair<ll,ll> llpair;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll a[n];
    ll b[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<n;i++){
    	cin>>b[i];
    }

    for(int i=0;i<n;i++){
    	a[i]*=((i+1)*(n-i));
    }

    // for(int i=0;i<n;i++){
    // 	cout<<a[i]<<" ";
    // }
    // cout<<endl;

    sort(a,a+n);
    sort(b,b+n);

    ll ans = 0;
    for(int i=0;i<n;i++){
    	a[i]%=MOD;
    	b[i]%=MOD;
    	ans+=(a[i]*b[n-i-1]+MOD)%MOD;
    	ans=(ans+MOD)%MOD;
    	// cout<<i<<" "<<a[i]<<" "<<b[n-i-1]<<" "<<ans<<endl;
    }

    if(ans<0){
    	ans+=MOD;
    }

    cout<<ans%MOD<<endl;

}