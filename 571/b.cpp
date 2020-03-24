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

   	ll a,b;
   	cin>>a>>b;

   	ll ans;

   	ll n=max(a,b);
   	ll m=min(a,b);

   	if (m==1||m==2){
	   	ans=(n-1)/3;
	   	if((n-1)%3!=0)ans++;
   	}
   	else{
   		ans=(2*(n+m)-4)/3;
   		ans+=min((n-2)/4,(m-2)/3);
   	}
   	cout<<ans<<endl;
}