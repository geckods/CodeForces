#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;


ll manhattandist(intpair a, intpair b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

ll timetaken(intpair minpoint, intpair maxpoint, intpair currpoint){
	return manhattandist(minpoint,maxpoint)+min(manhattandist(currpoint,minpoint),manhattandist(currpoint,maxpoint));
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x0,y0,ax,ay,bx,by;
    cin>>x0>>y0>>ax>>ay>>bx>>by;

    ll xs,ys,t;
    cin>>xs>>ys>>t;

    vector<intpair> pointVec;

    ll currx=x0,curry=y0;

    while(max(currx,curry)<=2*1e16){
	    pointVec.push_back({currx,curry});
	    currx=currx*ax+bx;
	    curry=curry*ay+by;
    }

    ll ans=0;

    for(int i=0;i<pointVec.size();i++){
    	for(int j=i;j<pointVec.size();j++){
    		if(timetaken(pointVec[i],pointVec[j], {xs,ys}) <= t){
    			ans=max(ans,(ll)j-i+1);
    		}
    	}
    }
    cout<<ans<<endl;

}