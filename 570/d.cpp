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
   		ll n;
   		cin>>n;
   		ll count[n];
   		memset(count,0,sizeof(count));
   		ll x;
   		for(int i=0;i<n;i++){
   			cin>>x;
   			x--;
   			count[x]++;
   		}

   		vector<ll> counts;

   		for(int i=0;i<n;i++){
   			counts.push_back(count[i]);
   		}

   		sort(counts.begin(),counts.end());

   		int cp=n-1;;
   		ll canadd=counts[cp]-1;
   		ll ans=counts[cp];

   		cp--;

   		while(cp>=0 && canadd>0){
   			// cout<<cp<<" "<<canadd<<endl;
   			if(counts[cp]>=canadd){
   				ans+=canadd;
   				cp--;
   			}
   			canadd--;
   		}

   		cout<<ans<<endl;

   	}
}