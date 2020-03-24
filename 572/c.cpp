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

   	int q;
   	cin>>q;

   	int cum[n];
   	cum[0]=arr[0];
   	for(int i=1;i<n;i++){
   		cum[i]=arr[i]+cum[i-1];
   	}

   	for(int quer=0;quer<q;quer++){
	   	int l,r;
	   	cin>>l>>r;
	   	l--;
	   	r--;

	   	int sum=cum[r];
	   	if(l>0){
	   		sum-=cum[l-1];
	   	}

	   	cout<<sum/10<<endl;
   	}
}
