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

    ll n,m,k;
    cin>>n>>m>>k;

    ll arr[m];
    for(int i=0;i<m;i++){
    	cin>>arr[i];
    }

    ll dc=0;
    ll ans=0;

    while(dc<m){
    	ll firstcat = (arr[dc]-dc-1)/k;
    	ll bmin=dc;
    	ll bmax=m-1;
    	while(bmin<bmax){
    		ll bmid=(bmin+bmax)/2;
    		// cout<<firstcat<<" "<<bmin<<" "<<bmax<<" "<<bmid<<endl;
    		if((arr[bmid]-dc-1)/k == firstcat){
    			if((bmid<n-1 && (arr[bmid+1]-dc-1)/k==firstcat)){
	    			bmin=bmid+1;
    			}
	    		else{
	    			bmin=bmid;
	    			break;
	    		}
    		}
    		else{
    			bmax=bmid-1;
    		}
    	}

    	// cout<<dc<<" "<<bmin<<endl;
    	dc=bmin+1;
    	ans++;
    }
    cout<<ans<<endl;
}
