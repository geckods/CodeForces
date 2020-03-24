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

    int t;
    cin>>t;

    while(t--){
        ll n,g,b;
        cin>>n>>g>>b;

        ll reqg=(n+1)/2;
        ll mincycles=(reqg-1)/g;

        ll remg=reqg-(mincycles*g);
        cout<<max(mincycles*(g+b)+remg,n)<<endl;

    }
}