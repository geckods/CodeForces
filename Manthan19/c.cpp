#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	set<int> mySet;
   	int n;
   	cin>>n;


   	int arr[n][n];
   	int prev=0;

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			arr[i][j]=i*n+j;
   		}
   	}

   	// for(int i=1;i<n;i++){
   	// 	arr[0][i]=arr[0][i-1]^i*i;
   	// }

   	// for(int i=1;i<n;i++){
   	// 	arr[i][0]=arr[i-1][0]^(n-i)*(n-i);
   	// }

   	// for(int i=1;i<n;i++){
   	// 	for(int j=1;j<n;j++){
   	// 		int thexor = pow((n-i+j)%n,2);
   	// 		// if(thexor==0)thexor=2;
   	// 		arr[i][j]=arr[i][j-1]^thexor;
   	// 	}
   	// }

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cout<<arr[i][j]<<" ";
   		}
   		cout<<endl;
   	}
}

