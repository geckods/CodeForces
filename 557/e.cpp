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

   	int arr[n];
   	int mymin=INT_MAX;

   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		mymin=min(mymin,arr[i]);
   	}

   	// cout<<mymin<<endl;

   	int mincount=0;
   	for(int i=0;i<n;i++){
   		if(arr[i]==mymin)mincount++;
   	}

   	if(mincount>n/2){
   		cout<<"Bob"<<endl;
   	}
   	else{
   		cout<<"Alice"<<endl;
   	}

}

