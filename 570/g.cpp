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

   	ll q;
   	cin>>q;

   	for(int quer=0;quer<q;quer++){
   		ll n;
   		cin>>n;
   		ll count[n];
         memset(count,0,sizeof(count));

         ll onecount[n];
         memset(onecount,0,sizeof(onecount));


   		ll x,y;

   		for(int i=0;i<n;i++){
   			cin>>x;
   			x--;
   			count[x]++;
            cin>>y;
            if(y==1){
               onecount[x]++;
            }
   		}

   		vector<intpair> counts;

   		for(int i=0;i<n;i++){
   			counts.push_back(make_pair(count[i],onecount[i]));
   		}

   		sort(counts.begin(),counts.end());


   		int cp=n-1;;
   		ll canadd=counts[cp].first-1;
         vector<ll> toBeAdded;
   		ll ans=counts[cp].first;
         toBeAdded.push_back(counts[cp].first);
         ll oneans=0;
   		cp--;

   		while(cp>=0 && canadd>0 && counts[cp].first>0){
   			if(counts[cp].first>=canadd){
   				ans+=canadd;
               toBeAdded.push_back(canadd);
   				cp--;
   			}
   			canadd--;
   		}

         // cerr<<quer<<" "<<toBeAdded.size()<<endl;

         int toBeAddedpointer=0;

         priority_queue<ll> oneext;

         for(int i=n-1;i>=0;i--){
            // cerr<<i<<" "<<counts[i]<<toBeAdded[toBeAddedpointer]<<endl;
            if(toBeAddedpointer>=toBeAdded.size()){
               break;
            }

            while(counts[i].first<toBeAdded[toBeAddedpointer] && toBeAddedpointer<toBeAdded.size()){
               oneans+=min(oneext.top(),toBeAdded[toBeAddedpointer]);
               oneext.pop();
               toBeAddedpointer++;
            }

            oneext.push(counts[i].second);
         }

         while(toBeAddedpointer<toBeAdded.size()&&!oneext.empty()){
            oneans+=min(toBeAdded[toBeAddedpointer],oneext.top());
            oneext.pop();
            toBeAddedpointer++;
         }

         cout<<ans<<" "<<oneans<<endl;
   	}
}