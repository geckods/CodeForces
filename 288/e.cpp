#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
#define MAXN 600
ll dp[MAXN][MAXN];

string getString(ll i, ll j){
	if(dp[i][j]==j){
		if(i==j){
			return "()";
		}
		else{
			string temp=getString(i+1,j);
			temp = '(' + temp + ')';
			return temp;
		}
	}
	else{
		return getString(i,dp[i][j])+getString(dp[i][j]+1,j);
	}
}


inline bool isInRange(ll x, ll a, ll b){
	return (x>=a&&x<=b);
}

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

    // dp[i][j]-> the ith to jth (inclusive) opening brackets can form a unit
    ll ranges[n][2];
    for(int i=0;i<n;i++){
    	cin>>ranges[i][0]>>ranges[i][1];
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		dp[i][j]=-1;
    	}
    }

    // dp->j implies it forms outer shell of package
    // else dp[i][j]=i implies i is the end of it

    for(int range=0;range<n;range++){
    	for(int i=0;i<n-range;i++){
    		int j=i+range;
    		// cerr<<i<<" "<<j<<" "<<range<<" "<<ranges[i][0]<<" "<<ranges[i][1]<<" "<<isInRange(range+1,ranges[i][0],ranges[i][1])<<endl;

    		if(isInRange(range*2+1, ranges[i][0], ranges[i][1]) && (range==0 || dp[i+1][j]!=-1)){
    			// cerr<<"HI"<<endl;
    			dp[i][j]=j;
    			continue;
    		}

    		for(int k=i;k<j;k++){
    			if(dp[i][k]!=-1 && dp[k+1][j]!=-1){
    				dp[i][j]=k;
    				break;
    			}
    		}

    	}
    }

    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<n;j++){
    // 		cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    // 	}
    // }

    // cout<<dp[0][n-1]<<endl;
    if(dp[0][n-1]==-1){
    	cout<<"IMPOSSIBLE"<<endl;
    	return 0;
    }

    cout<<getString(0,n-1)<<endl;



}
