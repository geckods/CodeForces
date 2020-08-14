#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
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
    	ll n;
    	cin>>n;

    	ll arr[n];
    	bool isSorted=true;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		if(i>0 && arr[i]<arr[i-1]){
    			isSorted=false;
    		}
    	}

    	ll b[n];
    	bool works=false;
    	for(int i=0;i<n;i++){
    		cin>>b[i];
    		if(i>0 && b[i]!=b[i-1]){
    			works=true;
    		}
    	}

    	if(works || isSorted){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}

    }
}