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

   	ll n;
   	cin>>n;

   	if(n==1){
   		cout<<4<<endl;
   		return 0;
   	}
   	else if (n==0){
   		cout<<1<<endl;
   		return 0;
   	}

   	ll ans=0;

   	ll x=n;
   	ll y=0;

   	ll nsq = n*n;
   	ll nmsq = (n-1)*(n-1);

   	bool flag=false;

   	while(x>=y){
   		ll sq=x*x+y*y;
   		if(sq>nmsq && sq<=nsq){

   			if(x==y)flag=true;
   			ans++;
   			y++;
   		}
   		else{
   			x--;
   		}
   	}


   	ans*=2;
   	if(flag) ans--;
   	ans--;
   	ans*=4;

   	cout<<ans<<endl;
}