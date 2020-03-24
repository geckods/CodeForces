#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ispartof(ll a, ll b){
	string as = to_string(a);
	string bs = to_string(b);

	int bpointer=0;
	int apointer=0;

	while(apointer<as.size() && bpointer < bs.size()){
		while(as[apointer]!=bs[bpointer]){
			apointer++;
			if(apointer==as.size()){
				return false;
			}	
		}
		apointer++;
		bpointer++;
	}

	if(bpointer==bs.size()){
		return true;
	}
	else{
		return false;
	}
}

ll lendiff(ll a, ll b){
	return to_string(a).size()-to_string(b).size();
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll ans=INT_MAX;
    for(ll i=1;i*i<=n;i++){
    	if(ispartof(n,i*i)){
    		ans=min(ans,lendiff(n,i*i));
    	}
    }

    if(ans==INT_MAX){
    	cout<<-1<<endl;
    }
    else{
    	cout<<ans<<endl;
    }
}