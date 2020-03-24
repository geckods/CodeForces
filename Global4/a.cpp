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

   	int totsum=arr[0];
   	int sum=arr[0];
   	vector<int> sol;
   	sol.push_back(1);

   	// cout<<arr[0]/2<<endl;

   	for(int i=1;i<n;i++){
   		totsum+=arr[i];
   		if(arr[i]<=(arr[0]/2)){
   			sum+=arr[i];
   			sol.push_back(i+1);
   		}
   	}

   	// cout<<sum<<" "<<totsum<<endl;

   	if(sum>totsum/2){
   		cout<<sol.size()<<endl;
   		for(int i=0;i<sol.size();i++){
   			cout<<sol[i]<<" ";
   		}
   		cout<<endl;
   	}
   	else{
   		cout<<0<<endl;
   	}

}
