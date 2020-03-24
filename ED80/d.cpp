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

    ll n,m;
    cin>>n>>m;
    ll arr[n][m];

    ll thepow=pow(2,m);

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>arr[i][j];
    	}
    }
    // cerr<<"HI"<<endl;


    ll storearr[thepow+1][2];
    for(int i=0;i<thepow;i++){
    	storearr[i][0]=0;
    	storearr[i][1]=0;
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<thepow;j++){
    		ll currmin=INT_MAX;
    		ll newj=j;
    		for(int k=0;k<m;k++){
    			if(newj&1){
    				currmin=min(currmin,arr[i][k]);
    			}
    			newj/=2;
    		}

    		// cout<<i<<" "<<j<<" "<<currmin<<endl;

    		if(currmin>storearr[j][1]){
    			// cerr<<"HI"<<endl;
    			storearr[j][0]=i;
    			storearr[j][1]=currmin;
    		}
    	}
    }

    ll themax=0;
    ll thei=0,thej=0;
    for(int i=0;i<thepow;i++){
    	int j=(thepow-1)^i;
    	// cerr<<i<<" "<<j<<" "<<storearr<<endl;
    	cerr<<i<<" "<<storearr[i][0]<<" "<<storearr[i][1]<<endl;

    	if(min(storearr[i][1],storearr[j][1])>themax){
    		themax=min(storearr[i][1],storearr[j][1]);
    		thei=storearr[i][0];
    		thej=storearr[j][0];
	    	// cerr<<themax<<" "<<th
    	}
    }

    cout<<thei+1<<" "<<thej+1<<endl;

}