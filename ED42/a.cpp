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

    ll sum=0;
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	sum+=arr[i];
    }

    ll newsum=0;
    for(int i=0;i<n;i++){
    	newsum+=arr[i];
    	if(newsum>=ceil((double)sum/2.0)){
    		cout<<i+1<<endl;
    		return 0;
    	}
    }
}
