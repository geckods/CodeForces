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

    // =

    ll t;
    cin>>t;

    while(t--){
    	ll n;
    	cin>>n;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	ll color[n];
    	memset(color,-1,sizeof(color));

    	ll num=2;
    	ll cc=1;
    	while(1){
    		bool done=true;
    		bool toUpdate=false;
    		for(int i=0;i<n;i++){
    			if(color[i]!=-1)continue;
    			if(arr[i]%num==0){
    				color[i]=cc;
    				toUpdate=true;
    			}
    			else{
    				done=false;
    			}
    		}

    		num++;
    		if(done)break;
    		if(toUpdate)
	    		cc++;
    	}

    	cout<<cc<<endl;
    	for(int i=0;i<n;i++){
    		cout<<color[i]<<" ";
    	}
    	cout<<endl;

    }
}