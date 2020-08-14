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

#define endl '\n'

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    cout<<7+(n-1)*3<<endl;

    cout<<0<<" "<<0<<endl;
    cout<<0<<" "<<1<<endl;
    cout<<1<<" "<<0<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<2<<" "<<1<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<2<<" "<<2<<endl;

    for(int i=0;i<n-1;i++){
    	cout<<i+2<<" "<<i+3<<endl;
    	cout<<i+3<<" "<<i+2<<endl;
    	cout<<i+3<<" "<<i+3<<endl;
    }
}