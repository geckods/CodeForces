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

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		ll currmax=INT_MIN;
		ll currmin=INT_MAX;

		ll m=INT_MIN;

		for(int i=0;i<n;i++){
			if(arr[i]!=-1 && i<n-1 && arr[i+1]!=-1){
				m=max(m,abs(arr[i+1]-arr[i]));
			}

			if(arr[i]==-1){
				if(i>0){
					if(arr[i-1]!=-1){
						currmax=max(currmax,arr[i-1]);
						currmin=min(currmin,arr[i-1]);						
					}
				}
				if(i<n-1){
					if(arr[i+1]!=-1){
						currmax=max(currmax,arr[i+1]);
						currmin=min(currmin,arr[i+1]);						
					}
				}
			}

		}

		if(currmax==INT_MIN){
			currmax=currmin=0;
		}

		ll k=(currmin+currmax)/2;
		cout<<max(m,max(abs(currmax-k),abs(currmax-k)))<<" "<<k<<endl;
	}
}
