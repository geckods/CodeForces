#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,m,k;
   	cin>>n>>m>>k;

   	priority_queue<pair<ll,intpair>,vector<pair<ll,intpair> >,greater<pair<ll,intpair> > > myPQ;
   	map<intpair,ll> myMap;

   	for(ll i=0;i<m;i++){
   		ll x,y,w;
   		cin>>x>>y>>w;
   		x--;
   		y--;


   		intpair thepair;
   		if(x<y){
   			thepair=make_pair(x,y);
   		}
   		else{
   			thepair=make_pair(y,x);   			
   		}
		myMap[thepair]=w;
		myPQ.push(make_pair(w,thepair));
   	}

   	ll i=0;

   	while(i<k-1){
   		pair<ll,intpair> curr = myPQ.top();
   		myPQ.pop();
   		ll w = curr.first;

   		ll first=curr.second.first;
   		ll second=curr.second.second;

   		if(w<myMap[curr.second])continue;
   		// cout<<w<<" "<<first<<" "<<second<<" "<<myPQ.size()<<endl;

   		for(ll j=0;j<n;j++){
   			if(j==first || j==second)continue;
   			ll a = min(j,first);
   			ll b = max(j,first);

   			if(myMap[make_pair(a,b)] != 0){
   				if(w+myMap[make_pair(a,b)]<myMap[make_pair(min(j,second),max(j,second))] || myMap[make_pair(min(j,second),max(j,second))]==0){
					myMap[make_pair(min(j,second),max(j,second))] = w+myMap[make_pair(a,b)];
					myPQ.push(make_pair(w+myMap[make_pair(a,b)],make_pair(min(j,second),max(j,second))));
   				}
   			}
   		}

   		for(ll j=0;j<n;j++){
   			if(j==second || j==first)continue;
   			ll a = min(j,second);
   			ll b = max(j,second);

   			if(myMap[make_pair(a,b)] != 0){
   				if(w+myMap[make_pair(a,b)]<myMap[make_pair(min(j,first),max(j,first))] || myMap[make_pair(min(j,first),max(j,first))]==0){
					myMap[make_pair(min(j,first),max(j,first))] = w+myMap[make_pair(a,b)];
					myPQ.push(make_pair(w+myMap[make_pair(a,b)],make_pair(min(j,first),max(j,first))));
   				}
   			}
   		}
   		i++;
   	}

   	cout<<myPQ.top().first<<endl;
}