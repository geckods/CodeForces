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


	ll q;
	cin>>q;

	for(int quer=0;quer<q;quer++){
		ll n,k;
		cin>>n>>k;

		ll arr[n];

		ll smallest=INT_MAX;
		ll largest=INT_MIN;

		ll x;

		for(int i=0;i<n;i++){
			cin>>x;
			smallest=min(smallest,x);
			largest=max(largest,x);
		}

		ll poss=smallest+k;
		//
		if(abs(largest-poss) > k){
			cout<<-1<<endl;
		}
		else{
			cout<<poss<<endl;
		}

	}   	

}
