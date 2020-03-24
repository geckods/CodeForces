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

   	int t;
   	cin>>t;
   	for(int test=0;test<t;test++){
   		ll n,k;
   		cin>>n>>k;
   		ll ans=0;
   		while(n>0){
   			if(n%k!=0){
   				ans+=n%k;
   				n-=(n%k);
   			}
   			else{
   				ans++;
   				n/=k;
   			}
   		}
   		cout<<ans<<endl;
   	}
}
