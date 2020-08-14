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
 		string s;
 		cin>>s;

 		ll prefz=0;
 		ll sufo=n-1;

 		while(prefz<n && s[prefz]=='0')prefz++;
 		while(sufo>=0 && s[sufo]=='1')sufo--;
 		sufo=n-sufo-1;

 		if(prefz+sufo==n){
 			cout<<s<<endl;
 		}
 		else{
 			for(int i=0;i<prefz+1;i++){
 				cout<<"0";
 			}
 			for(int i=0;i<sufo;i++){
 				cout<<"1";
 			}
 			cout<<endl;
 		}

 	}   
}
