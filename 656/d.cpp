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

        ll prefix[n][26];
        for(int i=0;i<26;i++){
            if(s[0]=='a'+i){
                prefix[0][i]=1;
            }
            else{
                prefix[0][i]=0;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                prefix[i][j]=prefix[i-1][j];
            }
            prefix[i][s[i]-'a']++;
        }

        ll maxk=0;
        while(1<<maxk <= n)maxk++;
        maxk--;

        ll dp[2*n][26];
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                dp[n+i][j]=1;
            }
            dp[n+i][s[i]-'a']--;
        }

        for(int k=1;k<=maxk;k++){
            for(int i=0;i<n/(1<<k);i++){
                ll currIndexer = n/(1<<k)+i;
                // cerr<<currIndexer<<endl;
                for(int j=0;j<25;j++){

                    ll lr = currIndexer;
                    ll rr = currIndexer;
                    while(lr < n)lr*=2;
                    while(rr < n){
                        rr*=2;
                        rr+=1;
                    }
                    lr-=n;
                    rr-=n;
                    ll mid = (lr+rr)/2;

                    ll leftConv = prefix[mid][j];
                    if(lr>0)leftConv -= prefix[lr-1][j];

                    ll rightConv = prefix[rr][j] - prefix[mid][j];

                    // if(j==0){
                        // cerr<<lr<<" "<<rr<<" "<<mid<<endl;
                        // cerr<<" "<<currIndexer<<" "<<leftConv<<" "<<rightConv<<endl;
                    // }


                    leftConv = (1<<(k-1))-leftConv;
                    rightConv = (1<<(k-1))-rightConv;

                    // if(j==0){
                    //     cerr<<" "<<currIndexer<<" "<<leftConv<<" "<<rightConv<<endl;
                    // }

                    dp[currIndexer][j]=dp[2*currIndexer][j+1]+rightConv;
                    dp[currIndexer][j]=min(dp[currIndexer][j],dp[2*currIndexer+1][j+1] + leftConv);
                }

                // cerr<<currIndexer<<" "<<dp[currIndexer][1]<<endl;
            }
        }

        // cerr<<dp[2][1]<<" "<<dp[3][1]<<endl;


        cout<<dp[1][0]<<endl;
    }
}