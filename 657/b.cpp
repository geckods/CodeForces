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
    while(t--){
    	ll l,r,m;
    	cin>>l>>r>>m;

    	ll biggestDiff = abs(l-r);

    	for(ll a=l;a<=r;a++){
    		ll n1 = m/a;
    		if(m-n1*a <= biggestDiff && n1 > 0){
    			// this works
    			// cout<<n1<<endl;
    			cout<<a<<" "<<l+m-n1*a<<" "<<l<<endl;
    			break;
    		} 

    		ll n2 = m/a;
    		n2++;

    		if(n2*a-m <= biggestDiff && n2 > 0){
    			// this works
    			cout<<a<<" "<<l<<" "<<l+n2*a-m<<endl;
    			break;
    		} 
    	}
    }
}