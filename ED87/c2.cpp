#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

#define PI 3.14159265358979323846

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

        double ans=1;
        ll splits=(n-2)/2+1;
        // split 90 degrees into this many

        cerr<<1+2*sin(PI/6)<<endl;
        cerr<<1+2*sin(3*PI/10)+2*sin((PI)/10)<<endl;

        for(int i=1;i<=splits;i++){
            ans+=2*(sin(i*PI/(2*splits)));
        }
        cout<<setprecision(12)<<ans<<endl;

    }
}