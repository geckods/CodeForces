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

   	ll n;
   	cin>>n;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	ll q;

   	cin>>q;

   	vector<ll> payouts;

   	ll lastpay[n];
   	for(int i=0;i<n;i++){
   		lastpay[i]=0;
   	}

   	for(int i=0;i<q;i++){
   		ll a,b,c;
   		cin>>a;
   		if(a==1){
   			cin>>b>>c;
   			arr[b-1]=c;
   			lastpay[b-1]=payouts.size();
   		}
   		else{
   			cin>>b;
   			payouts.push_back(b);
   		}
   	}

   	if(payouts.size()>0){
	   	ll backmax[payouts.size()];

	   	// for(int i=0;i<payouts.size();i++){
	   	// 	cout<<payouts[i]<<" ";
	   	// }
	   	// cout<<endl;

	   	backmax[payouts.size()-1]=payouts[payouts.size()-1];
	   	for(int i=payouts.size()-2;i>=0;i--){
	   		backmax[i]=max(payouts[i],backmax[i+1]);
	   	}

	   	// for(int i=0;i<payouts.size();i++){
	   	// 	cout<<backmax[i]<<" ";
	   	// }
	   	// cout<<endl;

	   	for(int i=0;i<n;i++){
	   		if(lastpay[i]<payouts.size())
		   		arr[i]=max(arr[i],backmax[lastpay[i]]);
	   		cout<<arr[i]<<" ";
	   	}
	   	cout<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}


}


