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

    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;

    ll first[n];
    for(int i=0;i<n;i++){
    	cin>>first[i];
    }

    ll second[m];
    for(int i=0;i<m;i++){
    	cin>>second[i];
    }

    ll c,d;
    ll ans = LLONG_MIN;

    for(int i=0;i<=k;i++){
    	c = i;
    	ll* timeind = lower_bound(second+d, second+m, first[c]+ta) + (k-i);
    	ll minians;

    	if(timeind>=second+m){
    		cout<<-1<<endl;
    		return 0;
    	}
    	else{
    		minians=(*timeind)+tb;
    	}

    	if(minians>ans) ans=minians;
    }

    cout<<ans<<endl;

}