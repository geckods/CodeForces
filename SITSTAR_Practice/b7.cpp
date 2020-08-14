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

    ll a,b;
    cin>>a>>b;

    if(a&1){
    	// you need an extra head
    	// you need to get tails to 4N+2
    	while(b%4!=2){
    		cout<<"T"<<endl;
    		b++;
    	}
    	while(b>0){
    		cout<<"TT"<<endl;
    		b--;
    		b--;
    		a++;
    	}
    	while(a>0){
    		cout<<"HH"<<endl;
    		a-=2;
    	}
    }
    else{
    	while(b%4!=0){
    		cout<<"T"<<endl;
    		b++;
    	}
    	while(b>0){
    		cout<<"TT"<<endl;
    		b--;
    		b--;
    		a++;
    	}
    	while(a>0){
    		cout<<"HH"<<endl;
    		a-=2;
    	}
    }
}
