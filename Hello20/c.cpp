#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 250010

ll fact[MAXN];
ll squares[MAXN];

void factorial(ll mod){
	ll i=1;
	fact[0]=fact[i]=1;
	for(ll i=2;i<=MAXN;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
	}
}


void getsquares(ll mod){
	for(ll i=1;i<=MAXN;i++){
		squares[i]=(i*i)%mod;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	// cerr<<"HI"<<endl;
	ll n,m;
	cin>>n>>m;

	factorial(m);
	getsquares(m);

	ll ans=0;
	for(ll i=1;i<n;i++){
		// cerr<<i<<" "<<fact[n-i+1]<<" "<<squares[i]<<" "<<fact[i]<<endl;
		ans+=((fact[n-i+1]*squares[i])%m*fact[i-1])%m;
		ans%=m;
	}
	ans+=(n*fact[n])%m;
	ans%=m;

	cout<<ans<<endl;
}