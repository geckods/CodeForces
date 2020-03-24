#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mykanade(vector<ll> arr, ll m, ll k){
	ll n = arr.size();
	int len = ceil(((double)(n))/m);

    ll marr[len];
    ll larr[len];

    memset(marr,0,sizeof(marr));
    memset(larr,0,sizeof(marr));


    // cout<<len<<endl;

    for(int i=0;i<len;i++){
    	ll sum=0;
    	for(int j=0;j<m;j++){
    		if(i*m+j>=arr.size())break;
    		sum+=arr[i*m+j];
    		// cout<<i<<" "<<j<<" "<<sum<<endl;
    		larr[i]=max(larr[i],sum);
    	}
    	marr[i]=sum;
    	// cout<<i<<" "<<marr[i]<<endl;
    }

    // for(int i=0;i<len;i++){
    // 	cout<<i<<" "<<marr[i]<<" "<<larr[i]<<endl;
    // }

    ll ans=0;

    for(int i=0;i<len;i++){
    	marr[i]-=k;
    	larr[i]-=k;

    	ans=max(ans,larr[i]);
    	ans=max(ans,marr[i]);
    }

    //kanade the marr and add larr

    // for(int i=0;i<len;i++){
    // 	cout<<i<<" "<<marr[i]<<" "<<larr[i]<<endl;
    // }

    ll max_ending_here=0;
    for(int i=0;i<len;i++){
    	max_ending_here=max_ending_here+marr[i];

    	// cout<<i<<

    	if(max_ending_here<0){
    		max_ending_here=0;
    	}


    	ll thething=max_ending_here;
    	if(i<len-1){
    		thething+=max(larr[i+1],0ll);
    	}
    	if(ans<thething) ans=thething;


    	// cout<<i<<" "<<ans<<endl;
    }

    return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> arr;
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	arr.push_back(x);
    }

    ll ans=0;

    for(int i=0;i<m;i++){
    	ans=max(ans,mykanade(arr,m,k));
    	if(arr.size()>0)
	    	arr.erase(arr.begin());
    }

	cout<<ans<<endl;    
}