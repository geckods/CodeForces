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

    int n;
    cin>>n;

    ll ans=0;

    ll arr[n][2];

    for(int i=0;i<n;i++){
    	cin>>arr[i][0]>>arr[i][1];
    	ans+=n*arr[i][1]-arr[i][0];
    }

    ll newarr[n];

    for(int i=0;i<n;i++){
    	newarr[i]=arr[i][1]-arr[i][0];
    }

    sort(newarr,newarr+n);

    for(int i=0;i<n;i++){
    	ans+=(-1)*(i+1)*newarr[i];
    }

    cout<<ans<<endl;
}