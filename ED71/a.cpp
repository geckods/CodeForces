#include <bits/stdc++.h>
using namespace std;

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
   		int b,p,f;
   		cin>>b>>p>>f;

   		int h,c;
   		cin>>h>>c;

   		int ham;
   		int che;
   		if(h>c){
   			ham=min(b/2,p);
   			b-=ham*2;
   			che=min(b/2,f);
   			cout<<h*ham+c*che<<endl; 
   		}
   		else{
   			che=min(b/2,f);
   			b-=che*2;
   			ham=min(b/2,p);
   			cout<<h*ham+c*che<<endl; 
   		}
   	}
}
