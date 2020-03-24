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

   	ll n,x;
   	cin>>n>>x;

   	int arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	ll ans=INT_MAX;

   	sort(arr,arr+n);

   	ll diffarr[n];
   	memset(diffarr,0,sizeof(diffarr));

   	diffarr[0]=1;
   	for(int i=1;i<n;i++){
   		if(arr[i]!=arr[i-1])
	   		diffarr[i]=1;
   	}

   	ll cumdifarr[n];
   	cumdifarr[0]=diffarr[0];
   	for(int i=1;i<n;i++){
   		cumdifarr[i]=cumdifarr[i-1]+diffarr[i];
   	}

   	ll permitted = pow((ll)2,(ll)floor(8*(double)x/n));
   	if((ll)floor(8*(double)x/n) > 30){
   		permitted=n;
   	}

   	int i=0;
   	while(i<n){
   		while(diffarr[i]==0)i++;
   		int maxind=lower_bound(cumdifarr,cumdifarr+n,cumdifarr[i]+permitted)-cumdifarr;
   		ans=min(ans,i+n-maxind);
   		i++;
   	}

   	cout<<ans<<endl;
}
