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
        ll A,B;
        cin>>A>>B;

        ll z=10;
        ll c=0;
        while(z-1<=B){
            c++;
            z*=10;
        }

        cout<<A*c<<endl;
    }
}