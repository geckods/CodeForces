#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	ll a,b,c;
    	cin>>a>>b>>c;

    	// do all alternates first

    	if(b==0){
    		if(a>0){
    			for(int i=0;i<a+1;i++){
    				cout<<0;
    			}
    			cout<<endl;
    		}
    		else{
    			for(int i=0;i<c+1;i++){
    				cout<<1;
    			}
    			cout<<endl;
    		}
    	}
    	else{
    		bool wasZero=true;
    		for(int i=0;i<b-1;i++){
    			if(wasZero){
    				cout<<0;
    				wasZero=false;
    			}
    			else{
    				cout<<1;
    				wasZero=true;
    			}
    		}

    		if(wasZero){
    			for(int i=0;i<a+1;i++){
    				cout<<0;
    			}
    			for(int i=0;i<c+1;i++){
    				cout<<1;
    			}    			
    			cout<<endl;
    		}
    		else{
    			for(int i=0;i<c+1;i++){
    				cout<<1;
    			}    			
    			for(int i=0;i<a+1;i++){
    				cout<<0;
    			}
    			cout<<endl;
    		}

    	}
    }
}