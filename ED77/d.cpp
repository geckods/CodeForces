#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool mysort(pair<ll,pair<ll,ll> > a, pair<ll,pair<ll,ll> > b){
	a.second.first=-a.second.first;
	b.second.first=-b.second.first;

	a.second.second=-a.second.second;
	b.second.second=-b.second.second;

	return a<b;
}

bool works(ll n,ll m,ll k,ll t, ll s[], vector<pair<ll,pair<ll,ll> > > traps, ll sc){
	ll minsold;
	if(sc>0){
		minsold=s[sc-1];
	}
	else{
		minsold=INT_MAX;
	}

	ll trapspointer=0;
	ll currtime=0;
	ll longestgone=0;

	for(int i=0;i<=m;i++){
		longestgone=max(longestgone,(ll)i);
		// cout<<i<<" "<<minsold<<" "<<currtime<<endl;
		while(trapspointer<k && traps[trapspointer].first==i+1){
			if(longestgone<traps[trapspointer].second.first && minsold<traps[trapspointer].second.second){
				currtime+=(traps[trapspointer].second.first-longestgone)*2;
				longestgone=max(longestgone,traps[trapspointer].second.first);
			}
			trapspointer++;
		}
		// cout<<i<<" "<<minsold<<" "<<currtime<<endl;
		currtime++;

		if(currtime>t){
			return false;
		}
	}
	return true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // binsearch the number of soldiers, act greedy for a soldier count

    ll n,m,k,t;
    cin>>n>>m>>k>>t;

    ll s[n];
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }
    sort(s,s+n);
    reverse(s,s+n);

    vector<pair<ll,pair<ll,ll> > > traps;
    for(int i=0;i<k;i++){
    	pair<ll,pair<ll,ll> > asdf;
    	cin>>asdf.first>>asdf.second.first>>asdf.second.second;
    	traps.push_back(asdf);
    }

    sort(traps.begin(),traps.end(),mysort);

    ll bmin=0;
    ll bmax=n;
    while(bmin<bmax){
    	ll bmid=ceil(((double)bmax+bmin)/2.0);
    	// cout<<bmin<<" "<<bmax<<" "<<bmid<<endl;
    	if(works(n,m,k,t,s,traps,bmid)){
    		bmin=bmid;
    	}
    	else{
    		bmax=bmid-1;
    	}
    }
    // cout<<bmin<<" "<<bmax<<endl;

    cout<<bmin<<endl;


}

