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
    	int n,d;
    	cin>>n>>d;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	int ans=0;
    	for(int i=0;i<n;i++){
    		if(arr[i]*i<=d){
    			ans+=arr[i];
    			d-=arr[i]*i;
    		}
    		else{
    			ans+=d/i;
    			break;
    		}
    	}
    	cout<<ans<<endl;

    }

}
