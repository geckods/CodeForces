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

    int n;
    cin>>n;

    bool pos[n];
    int x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	if(x>0)pos[i]=true;
    	else pos[i]=false;
    }

    // cout<<pos[0]<<" "<<pos[1]<<endl;

    bool status[n];
    status[0]=pos[0];
    for(int i=1;i<n;i++){
    	if(pos[i])
	    	status[i]=status[i-1];
	    else
	    	status[i]=!status[i-1];
    }

    // cout<<status[0]<<" "<<status[1]<<endl;

    ll statusup=1;
    ll statusdown=0;

    ll posans=0;
    ll negans=0;

    for(int i=0;i<n;i++){
    	if(status[i]){
    		posans+=statusup;
    		negans+=statusdown;
    		statusup++;
    	}
    	else{
    		posans+=statusdown;
    		negans+=statusup;
    		statusdown++;
    	}
    	// cout<<i<<" "<<status[i]<<" "<<statusup<<" "<<statusdown<<" "<<posans<<" "<<negans<<endl;
    }
    cout<<negans<<" "<<posans<<endl;
}