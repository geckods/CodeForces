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

   	int q;
   	cin>>q;

   	for(int quer=0;quer<q;quer++){
   		int n;
   		cin>>n;

   		int arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		int greaterthancount=0;
   		for(int i=1;i<n;i++){
   			if(arr[i]>arr[i-1]) greaterthancount++;
   		}

   		if(arr[0]>arr[n-1])greaterthancount++;

   		if(greaterthancount==1 || greaterthancount==n-1){
   			cout<<"YES"<<endl;
   		}
   		else{
   			cout<<"NO"<<endl;
   		}

   	}
}
