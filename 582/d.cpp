#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXSIZE 200001

ll getAns(ll cx[], ll g, ll k){
	ll themin=g;
	ll themax=g;
	ll ans=0;
	ll count=0;
	ll currcount;
	ll i=0;

	while(themin<MAXSIZE){
		if(themax<MAXSIZE){
			currcount=cx[themax];
		}
		else{
			currcount=cx[MAXSIZE-1];
		}
		currcount-=cx[themin-1];

		// cout<<themin<<" "<<themax<<" "<<count<<" "<<k<<" "<<currcount<<endl;


		if(currcount+count>=k){
			ans+=(k-count)*i;
			return ans;
		}
		else{
			ans+=currcount*i;
			count+=currcount;
		}
		// cout<<themin<<" "<<themax<<" "<<count<<" "<<k<<endl;

		i++;
		if(themin==0){
			themin=1;
			themax=1;
		}
		else{
			themin*=2;
			themax*=2;
			themax++;
		}
	}

	return INT_MAX;

}




int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
		freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    ll arr[n];
    ll xarr[MAXSIZE];
    ll cx[MAXSIZE];

    for(int i=0;i<MAXSIZE;i++){
    	xarr[i]=0;
    }

    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	xarr[arr[i]]++;
    }

    // for(int i=0;i<6;i++){
    // 	cout<<xarr[i]<<endl;
    // }

    cx[0]=xarr[0];
    for(int i=1;i<MAXSIZE;i++){
    	cx[i]=xarr[i]+cx[i-1];
    }

    // for(int i=0;i<6;i++){
    // 	cout<<cx[i]<<endl;
    // }


    ll ans=INT_MAX;
    for(int i=0;i<MAXSIZE;i++){
    	ans=min(ans,getAns(cx,i,k));
    	// cout<<i<<" "<<getAns(cx,i,k)<<endl;
    }
    cout<<ans<<endl;
}



