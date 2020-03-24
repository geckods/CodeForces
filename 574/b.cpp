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

    ll n,k;
    cin>>n>>k;

    ll mymin=0;
    ll mymax=n;
    ll mymid=-1;
    ll prevmid=-2;

    while(mymid!=prevmid){
    	prevmid=mymid;
    	mymid=(mymin+mymax)/2;

    	ll minians = (mymid*(mymid+1))/2 - (n-mymid);

    	if(minians==k){
    		cout<<n-mymid<<endl;
    		return 0;
    	}
    	else if (minians<k){
    		mymin=mymid+1;
    	}
    	else{
    		mymax=mymid-1;
    	}
    }
}
