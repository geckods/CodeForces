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
   		int a,b,n;
   		cin>>a>>b>>n;
   		int c=a^b;

   		if(n%3==0){
   			cout<<a<<endl;
   		}
   		else if (n%3==1){
   			cout<<b<<endl;
   		}
   		else{
   			cout<<c<<endl;
   		}
   	}
}
