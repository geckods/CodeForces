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

   	int n,k;
   	cin>>n>>k;

   	bool canend[n][3];

   	for(int i=0;i<n;i++){
   		for(int j=0;j<3;j++){
   			canend[i][j]=true;
   		}
   	}

   	canend[0][0]=false;
   	canend[n-1][2]=false;

   	bool seen[n];
   	for(int i=0;i<n;i++){
   		seen[i]=false;
   	}

   	int x;
   	for(int i=0;i<k;i++){
   		cin>>x;
   		x--;


   		canend[x][1]=false;
   		if(x>0 && seen[x-1]){
   			canend[x][0]=false;
   		}

   		if(x<n-1 && seen[x+1]){
   			canend[x][2]=false;
   		}
   		// cout<<x<<" "<<seen[x-1]<<" "<<seen[x+1]<<endl;

   		seen[x]=true;
   	}

   	int ans=0;
   	for(int i=0;i<n;i++){
   		for(int j=0;j<3;j++){
   			// if(canend[i][j])cout<<i+1<<" "<<j<<endl;
   			// if(canend[i][j]){
   			// 	if(j==0){
   			// 		cout<<i<<" "<<i+1<<endl;
   			// 	}
   			// 	else if (j==1){
   			// 		cout<<i+1<<" "<<i+1<<endl;
   			// 	}
   			// 	else{
   			// 		cout<<i+2<<" "<<i+1<<endl;
   			// 	}
   			// }
   			if(canend[i][j])ans++;
   		}
   	}

   	cout<<ans<<endl;
}