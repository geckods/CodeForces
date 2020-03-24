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

   	int q;
   	cin>>q;

   	char globarr[]={'R','G','B'};

   	for(int quer=0;quer<q;quer++){
	   	int n,k;
	   	cin>>n>>k;

	   	string s;
	   	cin>>s;

	   	int dp[n][3];//the moves required for the string ending at i to be = 0->R,1->G,2->B
	   	for(int i=0;i<n;i++){
	   		for(int j=0;j<3;j++){
	   			dp[i][j]=0;
	   		}
	   	}

	   	string firstk=s.substr(0,k);

	   	int tostartR=0;
	   	int tostartG=0;
	   	int tostartB=0;


	   	for(int i=0;i<k;i++){
	   		if(firstk[i]!=globarr[i%3]){
	   			tostartR++;
	   		}
	   		if(firstk[i]!=globarr[(i+1)%3]){
	   			tostartG++;
	   		}
	   		if(firstk[i]!=globarr[(i+2)%3]){
	   			tostartB++;
	   		}
	   	}

	   	// if((k-1)%3==0){
	   	dp[k-1][(k-1)%3]=tostartR;
	   	dp[k-1][(k)%3]=tostartG;
	   	dp[k-1][(k+1)%3]=tostartB;
	   	int ans=INT_MAX;

	   	ans=min(ans,tostartR);
	   	ans=min(ans,tostartG);
	   	ans=min(ans,tostartB);
	   	// cout<<tostartR<<" "<<tostartG<<" "<<tostartB<<endl;

	   	for(int i=k;i<n;i++){
	   		dp[i][0]=dp[i-1][2];
	   		if(s[i-k]!=globarr[((((0-k)%3)+3))%3])dp[i][0]--;
	   		if(s[i]!='R')dp[i][0]++;

	   		dp[i][1]=dp[i-1][0];
	   		if(s[i-k]!=globarr[(((1-k)%3)+3)%3])dp[i][1]--;
	   		// cout<<i-k<<" "<<(1-k)%3<<endl;
	   		if(s[i]!='G')dp[i][1]++;

	   		dp[i][2]=dp[i-1][1];
	   		if(s[i-k]!=globarr[(((2-k)%3)+3)%3])dp[i][2]--;
	   		if(s[i]!='B')dp[i][2]++;

	   		ans=min(ans,dp[i][0]);
	   		ans=min(ans,dp[i][1]);
	   		ans=min(ans,dp[i][2]);
	   	}

	   	// for(int i=0;i<n;i++){
	   	// 	cout<<k<<" "<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	   	// }

	   	ans=max(ans,0);

	   	cout<<ans<<endl;
   	}
}