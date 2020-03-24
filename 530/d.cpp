#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int par[n];
    for(int i=0;i<n;i++){
    	if(i==0){
    		par[i]=-1;
    		continue;
    	}
    	cin>>par[i];
    	par[i]--;
    }

    ll s[n];
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }

    ll h[n];
    for(int i=0;i<n;i++){
    	h[i]=INT_MAX;
    }

    ll sum=s[0];
    
    for(int i=1;i<n;i++){
    	if(s[i]!=-1){
    		if(s[i]<s[par[par[i]]]){
    			cout<<-1<<endl;
    			return 0;
    		}
	    	h[par[i]]=min(h[par[i]],s[i]);
    	}
    }

    for(int i=0;i<n;i++){
    	if(h[i]==INT_MAX && s[i]==-1){
    		h[i]=s[par[i]];
    	}
    }

    // for(int i=0;i<n;i++)

    // for(int i=0;i<n;i++){
    // 	cout<<i<<" "<<s[i]<<" "<<h[i]<<endl;
    // }

    for(int i=1;i<n;i++){
    	if(s[i]==-1){
    		sum+=h[i]-s[par[i]];
    	}
    	else{
    		sum+=s[i]-h[par[i]];
    	}
    	// sum+=s[i]-s[par[i]];
    }

    cout<<sum<<endl;
}