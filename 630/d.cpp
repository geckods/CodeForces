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

    ll k;
    cin>>k;

    cout<<3<<" "<<3<<endl;
    cout<<(k|(1<<17))<<" "<<k<<" "<<k<<endl;
    cout<<(1<<17)<<" "<<(1<<17)<<" "<<(k|(1<<17))<<endl;
    cout<<0<<" "<<0<<" "<<k<<endl;
}
