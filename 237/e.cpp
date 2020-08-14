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

bool simulate(string s, int block){
	ll minCurr=0;
	ll maxCurr=0;
	ll curr=0;
	if(block==0)block=INT_MIN;
	for(int j=0;j<s.length();j++){
		minCurr=min(minCurr,curr);
		maxCurr=max(maxCurr,curr);
		if(s[j]=='R' && curr+1!=block)curr++;
		if(s[j]=='L' && curr-1!=block)curr--;
	}
	return (curr<minCurr || curr>maxCurr);
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    ll curr=0;
    ll n = s.size();

    ll minCurr=0;
    ll maxCurr=0;

    for(int i=0;i<n;i++){
    	minCurr=min(minCurr,curr);
    	maxCurr=max(maxCurr,curr);
    	if(s[i]=='R')curr++;
    	else curr--;
    }
    if(curr>maxCurr || curr<minCurr){
    	cout<<1<<endl;
    	return 0;
    }

    // only one block required worst case
    // 
    ll ans=0;

    ll bmin=0;
    ll bmax=maxCurr;
    while(bmin<bmax){
    	ll bmid=(bmin+bmax)/2;
    	if((bmax-bmin)&1)bmid++;
    	if(simulate(s, bmid)){
    		bmin=bmid;
    	}
    	else{
    		bmax=bmid-1;
    	}
    }
    ans+=bmin;

    bmin=0;
    bmax=abs(minCurr);
    while(bmin<bmax){
    	ll bmid=(bmin+bmax)/2;
    	if((bmax-bmin)&1)bmid++;
    	if(simulate(s, -bmid)){
    		bmin=bmid;
    	}
    	else{
    		bmax=bmid-1;
    	}
    }
    ans+=bmin;


    cout<<ans<<endl;
}
