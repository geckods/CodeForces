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

   	int q;
   	cin>>q;

   	for(int i=0;i<q;i++){
   		ll a,b,c;
   		cin>>a>>b>>c;
   	
   		cout<<(a+b+c)/2<<endl;

   	}

}
