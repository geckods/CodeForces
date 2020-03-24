#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll rcount=0;
    ll acount=0;
    ll hcount=0;
    ll dcount=0;

    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll ddp[n+1];
    ll rdp[n+1];
    ll adp[n+1];
    ll hdp[n+1];

    for(int i=0;i<n+1;i++){
    	hdp[i]=adp[i]=rdp[i]=ddp[i]=0;
    }

    int lasth=n;
    int lasta=n;
    int lastr=n;
    int lastd=n;

    for(int i=n-1;i>=0;i--){
    	if(s[i]=='d'){
    		dcount+=arr[i];
    		lastd=i;
	    	ddp[i]=dcount;
    	}
    	if(s[i]=='r'){
    		rcount+=arr[i];    		
	    	rdp[i]=min(arr[i]+rdp[lastr],ddp[lastd]);
    		lastr=i;
    	}
    	if(s[i]=='a'){
    		acount+=arr[i];    		
	    	adp[i]=min(arr[i]+adp[lasta],rdp[lastr]);
    		lasta=i;
    	}
    	if(s[i]=='h'){
    		hcount+=arr[i];    		
	    	hdp[i]=min(arr[i]+hdp[lasth],adp[lasta]);
    		lasth=i;
    	}
    	// adp[i]=min(acount,rdp[i]);
    	// hdp[i]=min(hcount,adp[i]);
    }

    for(int i=0;i<n;i++){
    	if(s[i]=='h'){
    		cout<<hdp[i]<<endl;
    		return 0;
    	}
    }
    cout<<0<<endl;



}