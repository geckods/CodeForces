#include <bits/stdc++.h>
using namespace std;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use intONG_MAX/intONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

typedef long long ll;

#define MOD 1000000007
ll encode(char a, char b){
	ll ans = 0;
	if(a!='X'){
		ans+=a-'a'+1;
		ans*=27;
	}

	if(b!='X'){
		ans+=b-'a'+1;
	}
	return ans;
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

    // cout<<encode('z','z')<<endl;
    ll dp[n][729];
    ll pref[n][729];

    vector<string> myVec;
    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	myVec.push_back(s);
    	for(int j=0;j<729;j++){
    		dp[i][j]=pref[i][j]=0;
    	}
    }

    ll temp;

    for(int i=0;i<n;i++){

    	map<ll,ll> encodeCount;

    	if(myVec[i].size()==1){
    		// remove first char
    		encodeCount[encode('X','X')]++;
    		// do not remove first char
			encodeCount[encode(myVec[i][0],'X')]++;
    	}
    	else if (myVec[i].size()==2){
    		// remove nothing    		
    		encodeCount[encode(myVec[i][0],myVec[i][1])]++;

    		// remove first char
    		encodeCount[encode(myVec[i][1],'X')]++;

    		// remove second char
    		encodeCount[encode(myVec[i][0],'X')]++;
    	}
    	else{
    		// remove nothing
    		encodeCount[encode(myVec[i][0],myVec[i][1])]+=myVec[i].size()-1;

    		// remove first char
    		encodeCount[encode(myVec[i][1],myVec[i][2])]++;

    		// remove second char
    		encodeCount[encode(myVec[i][0],myVec[i][2])]++;
    	}

    	for(auto it:encodeCount){
    		dp[i][it.first] = it.second%MOD;
    		// cerr<<i<<" "<<it.first<<" "<<dp[i][it.first]<<endl;
    		if(i>0){
    			dp[i][it.first]*=pref[i-1][it.first];
    			dp[i][it.first]%=MOD;
    		}
    		// cerr<<i<<" "<<it.first<<" "<<dp[i][it.first]<<endl;
    	}

    	if(encodeCount[0]>0 && i>0){
    		for(int j=1;j<729;j++){
    			dp[i][j]+=dp[i-1][j];
    		}
    	}


    	pref[i][0]=dp[i][0]%MOD;
    	for(int j=1;j<729;j++){
    		pref[i][j]=pref[i][j-1]+dp[i][j];
    		pref[i][j]%=MOD;
    	}
    }

    ll ans=pref[n-1][728]%MOD;
    while(ans<0)ans+=MOD;
    cout<<ans<<endl;

}
