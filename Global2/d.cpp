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

    ll tuning[n];
    for(int i=0;i<n;i++){
    	cin>>tuning[i];
    }

    sort(tuning,tuning+n);

    vector<ll> gaps;

    for(int i=0;i<n-1;i++){
    	gaps.push_back(tuning[i+1]-tuning[i]);
    }

    sort(gaps.begin(),gaps.end());

    vector<ll> gapscum;

    ll cum=0;
    for(int i=0;i<n-1;i++){
    	cum+=gaps[i];
    	gapscum.push_back(cum);
    }

    ll q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll l,r;
    	cin>>l>>r;

    	int lowbound = lower_bound(gaps.begin(),gaps.end(),r-l+1)-gaps.begin();
    	ll ans = (n-lowbound)*(r-l+1);
    	if(lowbound>0){
    		ans+=gapscum[lowbound-1];
    	}

    	cout<<ans<<" ";

    }
}