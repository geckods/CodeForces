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
		ll x,y,a,b;
		cin>>x>>y>>a>>b;

		if((y-x)%(a+b)==0){
			ll t=(y-x)/(a+b);
			cout<<t<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}    
}
