#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

bool inRange(ll t1, ll t2, ll t3){
	if(t2>t1){
		return (t3>t1 && t3<t2);
	}
	else {
		return (t3>t1 || t3<t2);
	}
}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,h,m,k;
    cin>>n>>h>>m>>k;

    vector<intpair> departM;

    ll hi,mi;
    for(int i=0;i<n;i++){
    	cin>>hi>>mi;
    	departM.push_back({mi%(m/2),i});
    }

    ll minCancel = INT_MAX;
    ll bestBoardingTimeStart = -1;

    sort(departM.begin(),departM.end());

    for(int i=0;i<n;i++){
    	// let departM[mi] be a train that is allowed to depart
    	if(i<n && departM[i+1]==departM[i])continue;

    	auto lbi = lower_bound(departM.begin(), departM.end(), make_pair(((departM[i].first+k)%(m/2)),-1ll));
    	ll lb = lbi-departM.begin();
    	lb--;
    	if(lb<i)lb+=n;

    	// count is lb-i
    	if(lb-i <= minCancel){
    		minCancel = lb-i;
    		bestBoardingTimeStart = departM[i].first;
    	}
    }

    cout<<minCancel<<" "<<(bestBoardingTimeStart+k)%(m/2)<<endl;
    for(int i=0;i<n;i++){
    	if(inRange(bestBoardingTimeStart,(bestBoardingTimeStart+k)%(m/2),departM[i].first)){
    		cout<<departM[i].second+1<<" ";
    	}
    }
    cout<<endl;
}