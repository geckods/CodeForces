#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;

   	int n=s.length();
   	ll dp[10][10][10];
   	for(int i=0;i<10;i++){
   		for(int j=0;j<=i;j++){
   			for(int k=0;k<10;k++){

   				if(i==0&&j==0){
   					// if(k==0){
   					// 	dp[i][j][k]=0;
   					// }
   					// else{
	   				dp[i][j][k]=-1;
   					// }
   					continue;
   				}
   				if((i==0 || j==0)&&k==0){
   					dp[i][j][k]=0;
   					continue;
   				}
   				ll minisum=INT_MAX;
   				ll a=k;
   				ll themax=i;
   				ll themin=j;
   				for(int z=0;z<100;z++){
   					if(a==0)a+=10;
   					if(a%gcd(themin,themax)==0){
   						ll minc=0;
   						ll newa=a;
   						while(newa>0 && newa%themax!=0){
   							newa-=themin;
   							minc++;
   						}

   						if(newa<0){
   							a+=10;
   							continue;
   						}

   						if(newa==0){
   							minisum=min(minisum,minc-1);
   						}
   						else{
	   						minisum=min(minisum,minc+newa/themax-1);
   						}
   					}
   					a+=10;
   				}
   				dp[j][i][k]=dp[i][j][k]=minisum;

   				if(dp[j][i][k]>=INT_MAX){
   					dp[j][i][k]=dp[i][j][k]=-1;
   				}
   			}
   		}
   	}

   	dp[0][0][0]=0;

   	for(int i=0;i<10;i++){
   		for(int j=0;j<10;j++){

   			// for(int k=0;k<10;k++){
   			// 	if(i<=j)
	   		// 		cerr<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
   			// }

   			ll ans=0;
   			for(int z=0;z<n-1;z++){
   				ll a = s[z+1]-s[z];
   				if(a<0)a+=10;
   				ans+=dp[i][j][a];
   				if(dp[i][j][a]==-1){
   					ans=-1;
   					break;
   				}
   			}
	   		cout<<ans<<" ";
   		}
   		cout<<endl;
   	}

}