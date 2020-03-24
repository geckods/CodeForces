#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,t;
    cin>>n>>t;

    vector<ll> typea;
	vector<ll> typeb;
	vector<ll> typec;

	ll ti,gi;
	for(int i=0;i<n;i++){
		cin>>ti>>gi;
		if(gi==1){
			typea.push_back(ti);
		}
		if(gi==2){
			typeb.push_back(ti);
		}
		if(gi==3){
			typec.push_back(ti);
		}
	}

	sort(typea.begin(),typea.end());
	sort(typeb.begin(),typeb.end());
	sort(typec.begin(),typec.end());


	ll dp[t+1][(int)pow(2,n)];
	for(int time=0;time<t+1;time++){
		for(int i=0;i<3;i++){
			for(int j=0;j<15;j++){
				dp[time][i][j]=0;
			}
		}
	}

	for(int time=1;time<=t;time++){
		for(int i=0;i<typea.size();i++){
			if(typea[i]<time){
				dp[time][0]=dp[time-typea[i]][1]+dp[time-typea[i]][2];
			}
			else if (typea[i]==time){
				dp[time][0]++;
			}
			else{
				break;
			}

		}
		dp[time][0]%=MOD;


		for(int i=0;i<typeb.size();i++){
			if(typeb[i]<time){
				dp[time][1]=dp[time-typeb[i]][0]+dp[time-typeb[i]][2];
			}
			else if (typeb[i]==time){
				dp[time][1]++;
			}
			else{
				break;
			}

		}
		dp[time][1]%=MOD;

		for(int i=0;i<typec.size();i++){
			if(typec[i]<time){
				dp[time][2]=dp[time-typec[i]][0]+dp[time-typec[i]][1];
			}
			else if (typec[i]==time){
				dp[time][2]++;
			}
			else{
				break;
			}
		}
		dp[time][2]%=MOD;
	}

	for(int time=1;time<=t;time++){
		cout<<time<<" "<<dp[time][0]<<" "<<dp[time][1]<<" "<<dp[time][2]<<endl;
	}

	ll ans=dp[t][0]+dp[t][1]+dp[t][2];
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<endl;
}