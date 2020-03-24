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

    ll a,b,c;

    cin>>a>>b>>c;
    ll ans=2*c+min(a,b)*2;
    if(a!=b) ans++;
    cout<<ans<<endl;

}
