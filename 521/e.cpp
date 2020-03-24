#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minians(vector<int> counts, int start){
	if(start>counts[counts.size()-1]){
		return 0;
	}
	int minians=start;
	int startint = start;
	int currind=lower_bound(counts.begin(),counts.end(),start)-counts.begin()+1;
	ll multiplier=2;
    for(int j=0;1;j++){
    	ll thenow=multiplier*startint;
    	if(thenow>counts[counts.size()-1])break;
    	vector<int>::iterator newcurr = lower_bound(counts.begin()+currind,counts.end(),thenow);
    	if(newcurr==counts.end()){
    		break;
   		}
   		minians+=thenow;
   		currind=newcurr-counts.begin()+1;
   		multiplier*=2;
    }
    return minians;
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int x;
    map<int,int> count;

    for(int i=0;i<n;i++){
    	cin>>x;
    	count[x]++;
    }

    vector<int> counts;

    for(auto a : count){
    	counts.push_back(a.second);
    }

    sort(counts.begin(),counts.end()); 

 	ll ans=0;
    for(int i=1;i<=n;i++){
    	ll theans=minians(counts,i);
    	ans=max(ans,theans);
    	if(i>counts[counts.size()-1]) break;
    }

    cout<<ans<<endl;
}