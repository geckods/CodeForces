#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int main(){

	// =
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	ll n,x;
    	cin>>n>>x;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);

    	ll sum=0;
    	ll ans=-1;
    	for(int i=n-1;i>=0;i--){
    		sum+=arr[i];
    		if(sum>=(n-i)*x){
    		}
    		else{
    			ans=n-i-1;
    			break;
    		}
    	}
    	if(ans==-1)ans=n;
    	cout<<ans<<endl;
    }
}