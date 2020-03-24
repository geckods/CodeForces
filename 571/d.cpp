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

   	double arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	int intsum=0;

   	for(int i=0;i<n;i++){
   		intsum+=(int)arr[i];
   	}

   	//if intsum>0, then some negatives need to be floored
   	//if intsum<0, then some positives need to be ceiled

   	for(int i=0;i<n;i++){
   		if(fmod(arr[i],1)==0){
   			cout<<(int)arr[i]<<endl;
   			continue;
   		}

   		if(intsum>0 && arr[i]<0){
   			cout<<floor(arr[i])<<endl;
   			intsum--;
   		}
   		else if (intsum<0 && arr[i]>0){
   			cout<<ceil(arr[i])<<endl;
   			intsum++;
   		}
   		else{
   			cout<<((int)arr[i])<<endl;
   		}
   	}
}