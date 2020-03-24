#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

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

    vector<intpair> myVec;
    ll hasascentcount=0;

    for(int i=0;i<n;i++){
    	int l;
    	cin>>l;

    	ll themin=INT_MAX;
    	ll themax=INT_MIN;

    	ll x;
    	ll prev;
    	bool hasascent=false;
    	for(int j=0;j<l;j++){
    		prev=x;
    		cin>>x;
    		themax=max(themax,x);
    		themin=min(themin,x);

    		if(j>0 && x>prev){
    			hasascent=true;
    		}
    	}

    	if(hasascent){
    		hasascentcount++;
    		continue;
    	}
    	myVec.push_back({themin,themax});
    }

    ll ans=2*hasascentcount*n-hasascentcount*hasascentcount;
    // cout<<ans<<endl;

    vector<ll> maxes;
    for(int i=0;i<myVec.size();i++){
    	maxes.push_back(myVec[i].second);
    }

    sort(myVec.begin(),myVec.end());
    sort(maxes.begin(),maxes.end());

    for(int i=0;i<myVec.size();i++){
    	ll upcount = maxes.size()-(upper_bound(maxes.begin(),maxes.end(),myVec[i].first)-maxes.begin());
    	// cout<<myVec[i].first<<" "<<upcount<<endl;
    	ans+=upcount;
    }

    cout<<ans<<endl;

}

