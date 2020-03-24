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


   	ll q;
   	cin>>q;

   	for(int test=0;test<q;test++){
   		ll sum=0;
   		ll n;
   		cin>>n;
   		ll x;
   		for(int i=0;i<n;i++){
   			cin>>x;
   			sum+=x;
   		}

   		ll ans=sum/n;
   		if(n*ans<sum)ans++;
   		cout<<ans<<endl;
   	}

}
