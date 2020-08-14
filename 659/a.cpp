#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	string a,b;
    	cin>>a;
    	cin>>b;

    	set<ll> goesTo[20];
    	set<ll> comesTo[20];


    	bool works=true;
    	for(int i=0;i<n;i++){
    		if(a[i]>b[i]){
    			works=false;
    			break;
    		}
    		else if (a[i]<b[i]){
    			comesTo[b[i]-'a'].insert(a[i]-'a');
    			goesTo[a[i]-'a'].insert(b[i]-'a');
    		}
    	}

    	if(!works){
    		cout<<-1<<endl;
    		continue;
    	}

    	ll ans=0;

    	bool removed[20];
    	memset(removed,false,sizeof(removed));

    	for(int i=0;i<20;i++){
    		if(goesTo[i].size()==1){
    			removed[i]=true;
    			ans++;
    			ll target = *goesTo[i].begin();
    			goesTo[i].clear();
    			comesTo[target].erase(i);
    		}
    	}

    	ll remaining=0;
    	for(int i=0;i<20;i++){
    		remaining+=goesTo[i].size()>0;
    		remaining+=comesTo[i].size()>0;
    		if(removed[i] && comesTo[i].size()>0)ans--;
    	}



    	ans+=max(remaining-1,0ll);

		cout<<ans<<endl;
	}
}