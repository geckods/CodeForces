#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,k;
   	cin>>n>>k;
   	k--;

   	int ans=6;

   	if(k==0||k==n-1){
   		ans+=(n-2)*3;
   		cout<<ans<<endl;
   		return 0;
   	}
   	else{
   		if(k<n/2){
   			//go left
   			//you're already at k-1
   			ans+=(k-1)*3;
   			ans+=(k);
   			ans+=(n-k-1)*3;
   		}
   		else{
   			ans+=(n-k-2)*3;
   			ans+=(n-k-1);
   			ans+=(k)*3;
   		}
   		cout<<ans<<endl;
   	}
}