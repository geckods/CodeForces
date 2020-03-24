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

   	vector<pair<ll,ll> > myVec;

   	ll x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		myVec.push_back(make_pair(x,i+1));
   	}
   	sort(myVec.begin(),myVec.end(),greater<pair<ll,ll> >());

   	ll ans=0;
   	for(int i=0;i<n;i++){
   		ans+=myVec[i].first*i +1;
   	}

   	cout<<ans<<endl;
   	for(int i=0;i<n;i++){
   		cout<<myVec[i].second<<" ";
   	}
   	cout<<endl;
}