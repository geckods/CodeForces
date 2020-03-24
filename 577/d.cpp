#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MY_MAX LLONG_MAX/2
#define MY_MIN LLONG_MIN/2

ll travel(ll entry, ll exit, ll rangemin, ll rangemax){
	if(rangemin==MY_MAX){
		return abs(entry-exit);
	}
	return min((abs(entry-rangemax)+abs(rangemax-rangemin)+abs(rangemin-exit)),(abs(entry-rangemin)+abs(rangemax-rangemin)+abs(rangemax-exit)));
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	//need to keep track of max & min of each row
   	//start from the top row
   	//given a starting position, you can either go right till max first or go left toll min first
   	//then there are four cases -> either min's closest left col, min's closest right col, max's closest left col, max's closest right col

   	ll n,m,k,q;
   	cin>>n>>m>>k>>q;

   	ll range[n][2];

   	for(int i=0;i<n;i++){
   		range[i][0]=MY_MAX;
   		range[i][1]=MY_MIN;
   	}

   	ll r,c;
   	for(int i=0;i<k;i++){
   		cin>>r>>c;
   		r--;
   		c--;

   		range[r][0]=min(range[r][0],c);
   		range[r][1]=max(range[r][1],c);
   	}

   	vector<ll> safe;
   	ll x;
   	for(int i=0;i<q;i++){
   		cin>>x;
   		x--;
   		safe.push_back(x);
   	}

   	ll dp[n][4][2]; // dp[i][j][0] represents the minimum value to collect all coins on the ith row and end up at the jth safe route, where j<4 corresponding to the 4 things that matter.
	// dp[i][j][1] is the column	
   	ll safecols[n][4];
   	for(int i=0;i<n;i++){
   		safecols[i][0]=safecols[i][1]=safecols[i][2]=safecols[i][3]=-1;
   	}

   	for(int i=n-1;i>=0;i--){
   		if(range[i][0]!=MY_MAX){
	   		safecols[i][0]=lower_bound(safe.begin(),safe.end(),range[i][0])-safe.begin();
	   		if(safecols[i][0]>0)safecols[i][0]--;
	   		safecols[i][0]=safe[safecols[i][0]];
	   		// if(i==1)cout<<safecols[i][0]<<endl;

	   		safecols[i][1]=lower_bound(safe.begin(),safe.end(),range[i][0])-safe.begin();
	   		if(safecols[i][1]==q)safecols[i][1]--;
	   		safecols[i][1]=safe[safecols[i][1]];
   		}
   		else{
			safecols[i][0]=safecols[i+1][0];
			safecols[i][1]=safecols[i+1][1];		
   		}

   		if(range[i][1]!=MY_MIN){
	   		safecols[i][2]=lower_bound(safe.begin(),safe.end(),range[i][1])-safe.begin();
	   		if(safecols[i][2]>0)safecols[i][2]--;
	   		safecols[i][2]=safe[safecols[i][2]];

	   		safecols[i][3]=lower_bound(safe.begin(),safe.end(),range[i][1])-safe.begin();
	   		if(safecols[i][3]==q)safecols[i][3]--;
	   		safecols[i][3]=safe[safecols[i][3]];
   		}
   		else{
			safecols[i][2]=safecols[i+1][2];
			safecols[i][3]=safecols[i+1][3];		
   		}
   	}

   	int thelast=n-1;
   	while(range[thelast][0]==MY_MAX)thelast--;

   	if(thelast==0){
   		cout<<range[0][1]<<endl;
   		return 0;
   	}

   	// cout<<range[1][0]<<" "<<range[1][1]<<endl;

   	// cout<<" "<<thelast<<endl;
   	for(int i=0;i<4;i++){
   		// cout<<i<<" "<<safecols[thelast][i]<<endl;
   		dp[thelast][i][1]=safecols[thelast][i];
   		dp[thelast][i][0]=abs(range[thelast][1]-range[thelast][0])+min(abs(dp[thelast][i][1] - range[thelast][0]),abs(dp[thelast][i][1] - range[thelast][1]));
	   	// cout<<thelast<<" "<<i<<" "<<dp[thelast][i][0]<<" "<<dp[thelast][i][1]<<endl;
   	}


   	for(int i=thelast-1;i>=1;i--){


   		for(int j=0;j<4;j++){
	   		ll minans=MY_MAX;
	   		ll bestk;
   			for(int k=0;k<4;k++){
	   			ll entry=dp[i+1][k][1];
   				ll exit=dp[i][j][1]=safecols[i][j];
   				ll rangemin=range[i][0];
   				ll rangemax=range[i][1];

   				ll minians=1+dp[i+1][k][0]+travel(entry,exit,rangemin,rangemax);

   				// cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" minians:"<<minians<<" entry:"<<entry<<" exit:"<<exit<<" rangemin:"<<rangemin<<" rangemax:"<<rangemax<<" travel:"<<travel(entry,exit,rangemin,rangemax)<<endl;
   				if(minians<minans){
   					minans=minians;
   					bestk=k;
   				}
   			}

   			// cout<<i<<" "<<minans<<" "<<bestk<<endl;
   			dp[i][j][0]=minans;
   			// dp[i][j][1]=safecols
	   		// cout<<"DP:"<<i<<" "<<j<<" "<<dp[i][j][0]<<endl;
   		}
   	}

   	ll ans=MY_MAX;
   	for(int k=0;k<4;k++){

		ll entry=dp[1][k][1];
    	ll exit=0;
   		ll rangemin=range[0][0];
   		ll rangemax=range[0][1];
   		// cout<<"AAA"<<k<<" "<<dp[1][k][0]<<" "<<entry<<" "<<exit<<" "<<rangemin<<" "<<rangemax<<" "<<travel(entry,exit,rangemin,rangemax)<<endl;
   		ans=min(ans,1+dp[1][k][0]+travel(entry,exit,rangemin,rangemax));
   	}

   	// for(int i=0;i<n;i++){
   	// 	cout<<i<<" "<<range[i][0]<<" "<<range[i][1]<<endl;
   	// }

   	// for(int i=0;i<n;i++){
   	// 	cout<<i<<" "<<safecols[i][0]<<" "<<safecols[i][1]<<" "<<safecols[i][2]<<" "<<safecols[i][3]<<endl;
   	// }


   	cout<<ans<<endl;
}
