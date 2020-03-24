#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.length();

    int dp[n];

    memset(dp,0,n*sizeof(int));

    dp[0]=1;

    for(int i=1;i<n;i++){
    	if(s[i]!=s[i-1]){
    		dp[i]=dp[i-1]+1;
    	}
    	else{
    		dp[i]=1;
    	}
    }

    int maxof=0;

    for(int i=0;i<n;i++){
    	if(dp[i]>maxof) maxof=dp[i];
    }

    int wraparound=dp[n-1];

    if(dp[n-1]<n-1 && s[n-1]!=s[0]){
    	wraparound++;
    	int i=1;
    	while(s[i]!=s[i-1]){
    		i++;
    		wraparound++;
    	}
    }

    cout<<max(maxof,wraparound)<<endl;

}
