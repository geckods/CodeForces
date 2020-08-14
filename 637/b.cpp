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

ll preCom[256][10];

ll stringToNum(string s){
	ll ans=0;
	for(int i=0;i<7;i++){
		if(s[i]=='1')ans++;
		ans=ans<<1;
		// cerr<<ans<<endl;
	}
	ans=ans>>1;
	return ans;
}

void recurseDown(ll num, ll dig, ll x){
	// cerr<<num<<" "<<dig<<" "<<x<<endl;
	if(preCom[num][dig]==-1){
		preCom[num][dig]=x;

		for(int i=1;i<256;i=i<<1){
			if(num&i){
				recurseDown(num^i,dig,x+1);
			}
		}

	}
	else{
		return;
	}
}

void fillPrecom(){

	for(int i=0;i<256;i++){
		for(int j=0;j<10;j++){
			preCom[i][j]=-1;
		}
	}

	vector<string> myVec;
	myVec.push_back("1110111");
	myVec.push_back("0010010");
	myVec.push_back("1011101");
	myVec.push_back("1011011");
	myVec.push_back("0111010");
	myVec.push_back("1101011");
	myVec.push_back("1101111");
	myVec.push_back("1010010");
	myVec.push_back("1111111");
	myVec.push_back("1111011");

	for(int i=0;i<10;i++){
		// cerr<<i<<endl;
		recurseDown(stringToNum(myVec[i]), i,0);
	}

	// 0 is 1110111
	// 1 is 0010010
	// 2 is 1011101
	// 3 is 
}

#define MAXN 2000
ll dp[MAXN+1][MAXN+1];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    vector<int> myVec;
    string s;


    fillPrecom();
    // cerr<<preCom[33][5]<<endl;
    // cerr<<"HI"<<endl;
    for(int i=0;i<n;i++){
    	cin>>s;
		myVec.push_back(stringToNum(s));   	
    	// myVec.push_back(s);
    }

    reverse(myVec.begin(),myVec.end());

    for(int i=0;i<n;i++){
    	for(int j=0;j<=k;j++){
    		dp[i][j]=-1;
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<=k;j++){
    		for(int dig=9;dig>=0;dig--){
    			ll theC=preCom[myVec[i]][dig];
    			if(theC==-1)continue;
    			if(theC>j)continue;

    			// cerr<<i<<" "<<myVec[i]<<" "<<j<<" "<<dig<<" "<<theC<<endl;
    			if(i==0 && theC==j){
    				dp[i][j]=dig;
    				// cerr<<i<<" "<<myVec[i]<<" "<<theC<<" "<<dig<<endl;
    				break;
    			}

    			if(i==0)continue;

    			bool miniDone=false;

				if(dp[i-1][j-theC]!=-1){
					// cerr<<i-1<<" "<<j-theC<<" "<<dp[i-1][j-theC]<<endl;
					dp[i][j]=dig;
					// cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
					break;
				}

    			// cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;

    		}
    	}
    }

    // cerr<<dp[n-1][k]<<endl;



    ll currK=k;
    for(int i=n-1;i>=0;i--){
    	cout<<dp[i][currK];
    	if(dp[i][currK]==-1)break;
    	int temp=preCom[myVec[i]][dp[i][currK]];
    	currK-=temp;
    	// cerr<<dp[i][currK]<<" "<<myVec[i]<<" "<<temp<<endl;
    	// cerr<<i<<" "<<currK<<endl;
    }
    cout<<endl;

    // precompute from each number, how many to get to each digit


}