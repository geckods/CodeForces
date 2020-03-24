#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,m;
   	cin>>n>>m;

   	int arr[n][m];
   	int dp[n][m];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>arr[i][j];
   			dp[i][j]=0;
   		}
   	}

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			if(arr[i][j]==1){
   				//tl=1,tr=2,bl=3,br=4

   				if(i<n-1 && j<m-1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
   					dp[i][j]=1;
   				}
   				else if (j>0 && i<n-1 && arr[i][j-1]==1  &&  arr[i+1][j]==1 && arr[i+1][j-1]==1){
   					dp[i][j]=2;
   				}
   				else if (i>0 && j<m-1 && arr[i-1][j]==1 && arr[i-1][j+1]==1 && arr[i][j+1]==1){
   					dp[i][j]=3;
   				}
   				else if (i>0 && j>0 && arr[i-1][j-1]==1 && arr[i-1][j]==1 && arr[i][j-1]==1){
   					dp[i][j]=4;
   				}
   				if(dp[i][j]==0){
   					cout<<-1<<endl;
   					return 0;
   				}
   			}
   		}
   	}

   	vector<int> as;
   	vector<int> df;

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			if(dp[i][j]==1){
   				as.push_back(i);
   				df.push_back(j);
   				dp[i][j]=dp[i+1][j]=dp[i][j+1]=dp[i+1][j+1]=0;
   			}
   			if(dp[i][j]==2){
   				as.push_back(i);
   				df.push_back(j-1);
   				dp[i][j-1]=dp[i][j]=dp[i+1][j]=dp[i+1][j]=0;
   			}
   			if(dp[i][j]==3){
   				as.push_back(i-1);
   				df.push_back(j);
   				dp[i-1][j]=dp[i-1][j+1]=dp[i][j]=dp[i][j+1]=0;
   			}
   			if(dp[i][j]==4){
   				as.push_back(i-1);
   				df.push_back(j-1);
   				dp[i-1][j-1]=dp[i-1][j]=dp[i][j-1]=dp[i][j]=0;
   			}

   		}
   	}

   	cout<<as.size()<<endl;
   	for(int i=0;i<as.size();i++){
   		cout<<as[i]+1<<" "<<df[i]+1<<endl;
   	}
}