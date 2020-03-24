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
    	ll s;
    	cin>>s;
    	ll ans=0;
    	while(s>0){
    		if(s<10){
    			ans+=s;
    			s=0;
    		}
    		ans+=(s/10)*10;
    		s=s/10+s%10;
    	}
    	cout<<ans<<endl;
    }
}