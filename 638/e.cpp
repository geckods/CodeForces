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

    ll n,k;
    cin>>n>>k;

    ll dp[n][k][k];

    ll red[n];
    ll blue[n];

    for(int i=0;i<n;i++){
    	cin>>red[i]>>blue[i];
    }

    for(int i=0;i<n;i++){
    	for(int z=0;z<k;z++){
    		for(int x=0;x<k;x++){
    			dp[i][z][x]=0;
    		}
    	}
    }

    dp[0][red[0]%k][blue[0]%k]=(red[0]/k+blue[0]/k);

    for(int sum=2*k-1;sum>=0;sum--){
    	for(int rc=k-1;rc>=0;rc--){
    		if(rc>sum)continue;
    		ll bc=sum-rc;
    		if(bc<0 || bc>=k)continue;
    		if(rc<k-1){
    			dp[0][rc][bc]=max(dp[0][rc][bc],dp[0][rc+1][bc]);
    		}
    		if(bc<k-1){
    			dp[0][rc][bc]=max(dp[0][rc][bc],dp[0][rc][bc+1]);
    		}
    	}
    }

    for(int i=1;i<n;i++){
	    for(int sum=2*k-1;sum>=0;sum--){
	    	for(int rc=k-1;rc>=0;rc--){

	    		if(rc>sum)continue;
	    		ll bc=sum-rc;
	    		if(bc<0 || bc>=k)continue;


	    		ll hasSpare=(red[i]/k+blue[i]/k);

	    		ll rind=rc-red[i]%k;
	    		ll bind=bc-blue[i]%k;

	    		if(rind<0){
	    			hasSpare--;
	    			rind+=k;
	    		}
	    		if(bind<0){
	    			hasSpare--;
	    			bind+=k;	    			
	    		}
	    		if(hasSpare<0)continue;

    		    dp[i][rc][bc]=max(dp[i][rc][bc],dp[i-1][rind][bind]+hasSpare);

	    		if(rc<k-1){
	    			dp[i][rc][bc]=max(dp[i][rc][bc],dp[i][rc+1][bc]);
	    		}
	    		if(bc<k-1){
	    			dp[i][rc][bc]=max(dp[i][rc][bc],dp[i][rc][bc+1]);
	    		}
	    	}
	    }    	
    }

    for(int i=0;i<n;i++){
    	for(int rc=0;rc<k;rc++){
    		for(int bc=0;bc<k;bc++){
    			cerr<<i<<" "<<rc<<" "<<bc<<" "<<dp[i][rc][bc]<<endl;
    		}
    	}
    }

    cout<<dp[n-1][0][0]<<endl;

}
