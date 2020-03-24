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

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll r,b,k;
    	cin>>r>>b>>k;

    	ll m=min(r,b);
    	ll n=max(r,b);

    	ll gcd = __gcd(m,n);
    	m/=gcd;
    	n/=gcd;

    	ll consec;

    	consec=1+(n-2)/m;
    	if(consec>=k){
    		cout<<"REBEL"<<endl;
    	}
    	else{
    		cout<<"OBEY"<<endl;
    	}
    }
}