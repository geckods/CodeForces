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

   	ll x,y,z;
   	cin>>x>>y>>z;



   	cout<<(x+y)/z<<" ";
   	if((x+y)/z == x/z + y/z){
   		cout<<0<<endl;
   	}
   	else{
   		cout<<min(z-x%z,z-y%z)<<endl;
   	}

}
