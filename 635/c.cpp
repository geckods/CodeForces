#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define MOD 998244353



ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
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
    string t;
    cin>>t;


    ll n,m;
    n=s.length();
    m=t.length();
    // dp[n][m]
    // ->number of ways to use uptill the ith characters to the j to j+ith substring of t

 	ll dp[n][m];

 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			dp[i][j]=0; 			
 		}
 	}

 	for(int i=0;i<m;i++){
 		if(s[0]==t[i])dp[0][i]=2;
 		else dp[0][i]=0;
 	}

 	for(int i=1;i<n;i++){
 		for(int j=0;j<m;j++){
	 		if(i+j>=m)
		 		dp[i][j]=dp[i-1][j];
 			if(s[i]==t[j]){
 				// cerr<<i<<" "<<j<<endl;
 				// j could be the first
 				if(j<m-1)
	 				dp[i][j]+=dp[i-1][j+1];
	 			else
	 				dp[i][j]+=power(2,i,MOD);

	 			// j could also be the last
	 			int startingpoint=j-i;
	 			if(startingpoint>=0){
		 			dp[i][startingpoint]+=dp[i-1][startingpoint];
	 			}
	 			// else{
	 			// 	dp[i][0]*=2;
	 			// }

	 			dp[i][j]%=MOD;
 			}
 		}
 	}

 	// for(int i=0;i<n;i++){
 	// 	for(int j=0;j<m;j++){
 	// 		cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
 	// 	}
 	// }

 	ll ans=0;
 	for(int i=m-1;i<n;i++){
 		ans+=dp[i][0];
 		ans%=MOD;
 	}
 	cout<<ans<<endl;
 }