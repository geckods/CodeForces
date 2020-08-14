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
    	ll n;
    	cin>>n;

    	ll arr[2*n];

    	vector<ll> even;
    	vector<ll> odd;

    	for(int i=0;i<2*n;i++){
    		cin>>arr[i];
    		if(arr[i]%2==0){
    			even.push_back(i);
    		}
    		else{
    			odd.push_back(i);
    		}
    	}

    	ll pc=0;
    	for(int i=0;i+1<even.size();i+=2){
    		if(pc==n-1)break;
    		pc++;
    		cout<<even[i]+1<<" "<<even[i+1]+1<<endl;
    	}

    	for(int i=0;i+1<odd.size();i+=2){
    		if(pc==n-1)break;
    		pc++;
    		cout<<odd[i]+1<<" "<<odd[i+1]+1<<endl;
    	}


    }
}