#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
    ll arr[n];    
    ll sum=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	sum+=arr[i];
    }

    sort(arr,arr+n);

    ll m,k;
    cin>>m;

    for(int i=0;i<m;i++){
    	cin>>k;
    	cout<<sum-arr[n-k]<<endl;
    }
}