#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    //get range of in_firsts for which i is in the wrong set

    ll arr[n];
    int pos[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	arr[i]--;
    	pos[arr[i]]=i;
    }

    ll cost[n];
    for(int i=0;i<n;i++){
    	cin>>cost[i];
    }

    ll iswrong[n+1];
    //when i is the last element in final first set
    memset(iswrong,0,sizeof(iswrong));

    for(int i=0;i<n;i++){
    	//if pos[i]>i, is rrong for all i<=j<pos[i]
    	//if pos[i]<i, is rong for pos[i]<=j<i
    	// cout<<i<<" "<<pos[i]<<endl;
		iswrong[min(i,pos[i])]+=cost[pos[i]];
		iswrong[max(i,pos[i])]-=cost[pos[i]];

    	//for all j<max(i,pos[i])
    }

    // ll themin=INT_MAX;

    ll prefcost[n];
    ll suffcost[n];
    prefcost[0]=cost[0];
    for(int i=1;i<n;i++){
    	prefcost[i]=cost[i]+prefcost[i-1];
    }

    suffcost[n-1]=cost[n-1];
    for(int i=n-2;i>=0;i--){
    	suffcost[i]=cost[i]+suffcost[i+1];
    }


    ll ans=INT_MAX;
    ll curr=0;
    for(int i=0;i<n-1;i++){
    	curr+=iswrong[i];
    	ans=min(ans,prefcost[i]);
    	ans=min(ans,suffcost[i]);
    	// cout<<i<<" "<<curr<<endl;
    	ans=min(ans,curr);
    }

    // ll minansfirst=INT_MAX;
    // for(int i=0;i<n-1;i++){
    // 	minansfirst=min(minansfirst,cost[i]);
    // }

    ans=min(ans,cost[n-1]);
    ans=min(ans,cost[0]);

    cout<<ans<<endl;
}
