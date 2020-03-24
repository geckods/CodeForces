#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,m,k;
   	cin>>n>>m>>k;

   	if(min(m,k)>=n){
   		cout<<"YES"<<endl;
   	}
   	else{
   		cout<<"NO"<<endl;
   	}


}
