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
   	string t;
   	cin>>s;
   	cin>>t;

   	int n = s.length();
   	int m = t.length();

   	int dp[m][2];

   	int i=0,j=0;

   	while(j<m){
	   	while(s[i]!=t[j]){
   			i++;
   		}

   		dp[j][0]=i;
   		i++;
   		j++;
   	}

   	i=n-1;
   	j=m-1;

   	while(j>=0){
	   	while(s[i]!=t[j]){
   			i--;
   		}

   		dp[j][1]=i;
   		i--;
   		j--;   		
   	}

   	int ans=0;
   	ans=max(ans,dp[0][1]);
   	ans=max(ans,n-dp[m-1][0]-1);

   	for(int i=0;i<m-1;i++){
   		ans=max(ans,dp[i+1][1]-dp[i][0]-1);
   	}
   	cout<<ans<<endl;
}