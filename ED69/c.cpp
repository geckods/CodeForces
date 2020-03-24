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

    ll k,n;
    cin>>n>>k;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll barr[n-1];

    for(int i=0;i<n-1;i++){
    	barr[i]=arr[i]-arr[i+1];
    }

    sort(barr,barr+n-1);

    // for(int i=0;i<n;i++){
    // 	cout<<i<<" "<<arr[i]<<" "<<barr[i]<<endl;
    // }

    ll ans=0;
    ans-=arr[0];
    ans+=arr[n-1];

    for(int i=0;i<k-1;i++){
    	ans+=barr[i];
    }

    cout<<ans<<endl;
}