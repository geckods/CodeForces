#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    bool haszero=false;;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]==0) haszero=true;
    }

    set<int> ans;
    set<int> megaans;

    for(int i=0;i<n;i++){
    	set<int> newans;
    	set<int>::iterator j;
    	for(j = ans.begin();j!=ans.end();j++){
    		newans.insert(*j|arr[i]);
    	}
    	newans.insert(arr[i]);
    	megaans.insert(newans.begin(),newans.end());
    	ans=newans;
//    	cout<<ans.size()<<endl;
    }

    cout<<megaans.size()<<endl;

/*
//this solutions doesn't work
had to look at the editorial. Actually very simple
    int bitarr[n][32];

	for(int i=0;i<n;i++){
    	for(int j=0;j<32;j++){
    		bitarr[i][j]=0;
    	}
    }


    for(int i=0;i<n;i++){
    	int asd = arr[i];
    	for(int j=0;j<32;j++){
    		bitarr[i][j]=asd%2;
    		asd/=2;
    	}
    }

    int lastseen[32];
    for(int i=0;i<32;i++){
    	lastseen[i]=-1;
    }

    int ans=0;
    if(haszero) ans++;
    for(int i=0;i<n;i++){
    	int minlastseen=INT_MAX;
    	for(int j=0;j<32;j++){
    		if(bitarr[i][j]==1){
    			if(lastseen[j]<minlastseen)minlastseen=lastseen[j];
    			lastseen[j]=i;
    		}
    	}
    	if(minlastseen==-1){
	    	ans*=2;
	    }
	    cout<<i<<ans<<endl;
    }
*/
//    cout<<ans<<endl;

}
