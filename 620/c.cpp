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

    int q;
    cin>>q;

    while(q--){
    	ll n,m;
    	cin>>n>>m;

    	vector<pair<ll,intpair> > myVec;

    	ll t,l,h;
    	for(int i=0;i<n;i++){
    		cin>>t>>l>>h;
    		myVec.push_back({t,{l,h}});
    	}

    	sort(myVec.begin(),myVec.end());
    	ll currTime=0;
    	ll currMin=m;
    	ll currMax=m;
    	bool works=true;

    	for(int i=0;i<n;i++){
    		currMin-=(myVec[i].first-currTime);
    		currMax+=(myVec[i].first-currTime);
    		currTime=myVec[i].first;

    		// cerr<<i<<" "<<currTime<<" "<<currMin<<" "<<currMax<<endl;

    		if(currMin>myVec[i].second.second || currMax<myVec[i].second.first){
    			works=false;
    			break;
    		}

    		currMin=max(currMin,myVec[i].second.first);
    		currMax=min(currMax,myVec[i].second.second);
    		// cerr<<i<<" "<<currTime<<" "<<currMin<<" "<<currMax<<endl;

    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    }
}