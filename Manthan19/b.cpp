#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	int arr[n];

   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	set<int> mySet;

   	int ans=INT_MAX;
   	for(int start=0;start<n;start++){
   		// cout<<start<<" "<<ans<<endl;
   		mySet.clear();
   		bool done=false;
   		for(int i=0;i<start;i++){
   			if(mySet.find(arr[i])!=mySet.end()){
   				ans=min(ans,n-i);
   				done=true;
   				break;
   			}
   			mySet.insert(arr[i]);
   		}
   		if(done)continue;

   		for(int j=n-1;j>=start;j--){
   			if(mySet.find(arr[j])!=mySet.end()){
   				ans=min(ans,j-start+1);
   				done=true;
   				break;
   			}
   			mySet.insert(arr[j]);
   		}
   		if(done)continue;
   		if(!done)ans=0;
   	}

   	cout<<ans<<endl;

}