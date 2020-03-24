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

    ll t;
    cin>>t;


   	for(int test=0;test<t;test++){
   		ll x,y;
   		cin>>x>>y;


   		if(x>=4){
   			cout<<"YES"<<endl;
   		}
   		else{
   			if(y<4 && x > 1){
   				cout<<"YES"<<endl;
   			}
   			else{
   				if(x==y && y==1){
   					cout<<"YES"<<endl;
   				}
   				else{
	   				cout<<"NO"<<endl;
   				}
   			}
   		}

   	}
}