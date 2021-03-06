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
    	ll n,m;
    	cin>>n>>m;

    	ll arr[n][m];
    	bool claimedr[n];
    	bool claimedc[m];
    	memset(claimedr, false, sizeof(claimedr));
    	memset(claimedc,false,sizeof(claimedc));
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			cin>>arr[i][j];
    			if(arr[i][j]==1){
    				claimedr[i]=true;
    				claimedc[j]=true;
    				// cerr<<i<<" "<<j<<endl;
    			}
    		}
    	}

    	int cc=0;
    	int rc=0;
    	for(int i=0;i<n;i++){
    		if(!claimedr[i])rc++;
    	}

    	for(int i=0;i<m;i++){
    		if(!claimedc[i])cc++;
    	}

    	ll c = min(cc,rc);

    	if(c%2==1){
    		cout<<"Ashish"<<endl;
    	}
    	else{
    		cout<<"Vivek"<<endl;
    	}
    }

}
