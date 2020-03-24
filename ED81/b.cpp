#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
    	ll n,x;
    	cin>>n>>x;

    	string s;
    	cin>>s;

    	map<ll,ll> balencecount;
    	ll overallbal=0;
    	for(int i=0;i<n;i++){
    		balencecount[overallbal]++;
    		if(s[i]=='0')overallbal++;
    		else overallbal--;
    	}

    	if(overallbal==0){
    		if(balencecount[x]>0){
    			cout<<-1<<endl;
    		}
    		else{
    			cout<<0<<endl;
    		}
    	}
    	else{
    		ll ans=0;
    		for(auto i = balencecount.begin();i!=balencecount.end();i++){
    			if(overallbal>0 && x>=i->first && abs(x-i->first)%overallbal==0){
    				ans+=i->second;
    			}
    			else if (overallbal<0 && x<=i->first && abs(x-i->first)%overallbal==0){
    				ans+=i->second;    				
    			}
    		}
    		cout<<ans<<endl;
    	}

    }
}