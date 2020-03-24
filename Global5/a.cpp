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
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	bool up=true;

   	for(int i=0;i<n;i++){
   		if(arr[i]%2==0){
   			cout<<arr[i]/2<<endl;
   		}
   		else{
   			if(up){
   				cout<<(arr[i]+1)/2<<endl;
   				up=false;
   			}
   			else{
   				cout<<(arr[i]-1)/2<<endl;
   				up=true;
   			}
   		}
   	}
}
