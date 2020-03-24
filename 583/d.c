#include <stdio.h>
typedef long long ll;

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #pragma GCC target ("avx,tune=native")

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m;
    scanf("%d %d\n",&n,&m);

    char myVec[n][m];
    // vector<string> myVec;
    for(int i=0;i<n;i++){
    	// myVec.push_back(s);
    	for(int j=0;j<m;j++){
    		scanf("%c",&myVec[i][j]);
    	}
    	getchar();
    }

    //let's build a 'does there exist a path dp arr'
    // vector<vector<int> > dp;
    // for(int i=0;i<n;i++){
    // 	dp.push_back(vector<int>(m,0));
    // }
    int dp[n][m];
    dp[n-1][m-1]=1;
    for(int ijsum=n+m-3;ijsum>=0;ijsum--){
    	for(int i=0;i<=ijsum;i++){
    		int j=ijsum-i;
    		if(j<0 || i>n-1)break;
    		if(j<0||i<0||j>m-1||i>n-1)continue;
    		if(myVec[i][j]=='#')dp[i][j]=0;
    		else{
    			if(i==n-1){
    				dp[i][j]=dp[i][j+1];
    			}
    			else if (j==m-1){
    				dp[i][j]=dp[i+1][j];
    			}
    			else{
    				dp[i][j]=dp[i+1][j]|dp[i][j+1];
    			}
    		}
    	}
    }

    if(dp[0][0]==0){
        printf("0");
    	return 0;
    }

    if(n==1||m==1){
        printf("1");
    	return 0;
    }

    //now send two dudes;
    int onei=0,onej=0,twoi=0,twoj=0;

    //one goes right if he can
    //two goes down if he can
    while(1){
    	if((onei==n-1&&onej==m-1)||onei>n-1 || onej>m-1){
    		break;
    	}

    	if(onei==twoi && onej==twoj && (onei>0 || onej>0)){
            printf("1");
    		return 0;
    	}

    	if(onej<m-1 && dp[onei][onej+1]){
    		onej++;
    	}
    	else{
    		onei++;
    	}

    	if(twoi<n-1 && dp[twoi+1][twoj]){
    		twoi++;
    	}
    	else{
    		twoj++;
    	}
    }

    printf("2");
}
