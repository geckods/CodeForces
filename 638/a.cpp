#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

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

    	// ll maxset=pow(2ll,n);
    	// for(int i=1;i<n/2;i++){
    	// 	maxset+=pow(2ll,i);
    	// }
    	// ll minset=0;
    	// for(int i=n/2;i<n;i++){
    	// 	minset+=pow(2ll,i);
    	// }
    	// cout<<abs(minset-maxset)<<endl;

    	cout<<pow(2ll,n/2+1)-2<<endl;
    }

}
