#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		int n;
   		cin>>n;

   		int arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		sort(arr,arr+n);
   		reverse(arr,arr+n);

   		int ans=0;
   		for(int i=0;i<n;i++){
   			ans=max(ans,min(i+1,arr[i]));
   		}
   		cout<<ans<<endl;
   	}

}
