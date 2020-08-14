#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

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
    	ll n;
    	cin>>n;
    	ll j=4;
    	while(1){
    		if(n%(j-1)==0){
    			cout<<n/(j-1)<<endl;
    			break;
    		}
    		j*=2;
    	}
    }

}
