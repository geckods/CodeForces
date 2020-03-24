#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int arr[150002];
int seen[150002];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	// memset(arr,0,sizeof(arr));
   	memset(seen,0,sizeof(seen));

   	int x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		seen[x]++;
   	}

   	int ans=0;
   	for(int i=1;i<150002;i++){
		if (seen[i-1]>0 && i>1){
   			seen[i-1]--;
   			ans++;
   		}
   		else if(seen[i]>0){
   			// cout<<i<<endl;
   			seen[i]--;
   			ans++;
   		}
   		else if (seen[i+1]>0 && i<150001){
   			seen[i+1]--;
   			ans++;
   		}
   		// cout<<i<<ans<<endl;
   	}

   	cout<<ans<<endl;
}