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
    	int a,b,c,r;
    	cin>>a>>b>>c>>r;

    	if(b<a){
    		swap(a,b);
    	}

    	int rangemin=c-r;
    	int rangemax=c+r;

    	int ans=b-a;

    	if(rangemin>=b){
    		cout<<ans<<endl;
    		continue;
    	}
    	if(rangemax<=a){
    		cout<<ans<<endl;
    		continue;    		
    	}

    	int inrange=min(b,rangemax)-max(a,rangemin);

    	// cout<<ans<<" "<<inrange<<endl;
    	cout<<ans-inrange<<endl;

    }

}
