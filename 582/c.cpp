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

    ll q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll n,m;
    	cin>>n>>m;

    	ll cyclelen=0;
    	ll cyclesum=0;

    	bool seen[10];
    	for(int i=0;i<10;i++){
    		seen[i]=false;
    	}

    	ll mcopy=m;
    	while(1){
    		if(seen[mcopy%10]){
    			break;
    		}
    		else{
    			cyclesum+=mcopy%10;
    			seen[mcopy%10]=true;
    			cyclelen+=m;
    			mcopy+=m;
    		}
    	}

    	ll ans;
    	ans=(n/cyclelen)*cyclesum;
    	n%=cyclelen;

    	mcopy=0;
    	while(mcopy<=n){
    		ans+=mcopy%10;
    		mcopy+=m;
    	}

    	cout<<ans<<endl;
    }
}