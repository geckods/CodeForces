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
    	bool hasodd=false;
    	bool haseven=false;

    	int n,x;
    	cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		if(x%2){
    			hasodd=true;
    		}
    		else{
    			haseven=true;
    		}
    	}

    	if(!hasodd){
    		cout<<"NO"<<endl;
    	}
    	else{
    		if(haseven){
    			cout<<"YES"<<endl;
    		}
    		else{
    			if(n%2){
    				cout<<"YES"<<endl;
    			}
    			else{
    				cout<<"NO"<<endl;
    			}
    		}
    	}
    }

}
