#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//=]+

    int t;
    cin>>t;
    for(int test=0;test<t;test++){
	    ll arr[3];
	    cin>>arr[0]>>arr[1]>>arr[2];
	    sort(arr,arr+3);

	    ll ans=0;

	    ll secdiff=arr[2]-arr[1];

	    if(arr[0]<secdiff){
	    	ans=arr[0]+min(arr[1],arr[2]-arr[0]);
	    }
	    else{
	    	ans=secdiff;
	    	arr[0]-=secdiff;
	    	arr[2]=arr[1];
	    	ans+=arr[0];
	    	ans+=arr[1]-(arr[0]+1)/2;
	    }
	    cout<<ans<<endl;

    }


}
