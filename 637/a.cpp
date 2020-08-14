#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

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
    	ll p[n];
    	
    	map<ll,ll> loc;

    	for(int i=0;i<n;i++){
    		cin>>p[i];
    		p[i]--;
    		loc[p[i]]=i;
    	}

    	ll currEnd=n;
    	ll currElem=0;

    	bool works=true;
    	while(currElem<n){
    		int i=loc[currElem];
    		for(int j=i;j<currEnd-1;j++){
    			currElem++;
    			if(p[j+1]!=p[j]+1){
    				works=false;
    				break;
    			}
    		}


    		if(!works)break;
    		currElem++;
    		currEnd=i;
    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}


    }

}
