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
   	int arr[2*n];

   	for(int i=0;i<2*n;i++){
   		cin>>arr[i];
   	}

   	sort(arr,arr+2*n);

   	int sum1=0;

   	for(int i=0;i<n;i++){
   		sum1+=arr[i];
   	}

   	int sum2=0;

   	for(int i=n;i<2*n;i++){
   		sum2+=arr[i];	
   	}


   	if(sum1==sum2){
   		cout<<-1<<endl;
   		return 0;
   	}
   	else{
   		for(int i=0;i<2*n;i++){
   			cout<<arr[i]<<" ";
   		}
   		cout<<endl;
   	}

}
