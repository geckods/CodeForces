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
		ll n;
		cin>>n;
		ll arr[n];
		ll barr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i]>>barr[i];
		}

		bool works=true;
		for(int i=0;i<n;i++){
			if(barr[i]>arr[i]){
				works=false;
				break;
			}
			if(i>0){
				if(barr[i]-barr[i-1]>arr[i]-arr[i-1]){
					works=false;
					break;
				}
				if(barr[i]<barr[i-1]||arr[i]<arr[i-1]){
					works=false;
					break;
				}
			}
		}

		if(works){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}    

}
