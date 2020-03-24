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
    	ll n;
    	cin>>n;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	//kanade
    	ll maxtillhere=0;
    	ll maxglobal=INT_MIN;

    	ll totalsum=0;
    	int currstart=0;
    	for(int i=0;i<n;i++){
    		totalsum+=arr[i];
    		maxtillhere+=arr[i];
    		if(maxtillhere<=0){
    			currstart=i+1;
    		}
    		maxtillhere=max(maxtillhere,0ll);
    		if(i==n-1){
    			if(currstart!=0){
		    		maxglobal=max(maxglobal,maxtillhere);
    			}
    		}
    		else{
		    	maxglobal=max(maxglobal,maxtillhere);    			
    		}
    	}

    	if(maxglobal>=totalsum){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}

    }
}