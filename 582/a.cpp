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

    ll n;
    cin>>n;

    ll arr[n];
    ll evencount=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]%2==0)evencount++;
    }

    cout<<min(evencount,n-evencount)<<endl;
}
