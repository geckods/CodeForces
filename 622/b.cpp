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
    	ll n,x,y;
    	cin>>n>>x>>y;
    	ll a,b;
    	// a=min(x,y);
    	// b=max(x,y);
    	// at least x+y-n people must be less than him
    	cout<<min(max(x+y-n+1,1ll),n)<<" "<<max(min(x+y-1,n),1ll)<<endl;
    }
}