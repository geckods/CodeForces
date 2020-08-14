#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

#define endl '\n'


#define MAXN 500000
ll finArr[MAXN];
ll sumArr[MAXN];

int main(){
	
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
    	ll n,k;
    	cin>>n>>k;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	for(int i=0;i<=2*k;i++){
    		finArr[i]=0;
    		sumArr[i]=0;
    	}

    	for(int i=0;i<n/2;i++){
    		ll sum=arr[i]+arr[n-i-1];
    		ll lowRange=sum+1-max(arr[i],arr[n-i-1]);
    		ll highRange=sum-min(arr[i],arr[n-i-1])+k;

    		// cerr<<sum<<" "<<lowRange<<" "<<highRange<<endl;
    		sumArr[sum]++;
    		finArr[lowRange]++;
    		finArr[highRange+1]--;
    	}

    	ll ans=INT_MAX;
    	ll curr=0;
    	for(int i=0;i<=2*k;i++){
    		curr+=finArr[i];
    		// cerr<<curr<<" "<<sumArr[i]<<endl;
    		ans=min(ans,(curr-sumArr[i]) + 2*(n/2 - (curr)) );
    	}
    	cout<<ans<<endl;

    }
}