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

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll a=0,b=0;

    sort(arr,arr+n);

    for(int i=0;i<n/2;i++){
    	b+=arr[i];
    	a+=arr[n-i-1];
    }

    if(n%2==1){
    	a+=arr[n/2];
    }

    cout<<a*a+b*b<<endl;
}