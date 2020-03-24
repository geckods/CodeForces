#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n,s,t;
    	cin>>n>>s>>t;

    	ll both=(s+t)-n;

    	ll onlys = s-both;
    	ll onlyt = t-both;

    	ll ans=max(onlys,onlyt)+1;
    	cout<<ans<<endl;
    }

}
