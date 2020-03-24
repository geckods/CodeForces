#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000000

int nextleft[MAXN][3];
int nextright[MAXN][3];
int dp[MAXN][3][3];

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    string s;
    cin>>s;
    int n=s.length();

    int lasta=-1,lastb=-1,lastc=-1;

    for(int i=0;i<n;i++){
    	nextleft[i][0]=lasta;
    	nextleft[i][1]=lastb;
    	nextleft[i][2]=lastc;

    	if(s[i]=='a')lasta=i;
    	if(s[i]=='b')lastb=i;
    	if(s[i]=='c')lastc=i;
    }

    lasta=n;
    lastb=n;
    lastc=n;

    for(int i=n-1;i>=0;i--){
    	nextright[i][0]=lasta;
    	nextright[i][1]=lastb;
    	nextright[i][2]=lastc;

    	if(s[i]=='a')lasta=i;
    	if(s[i]=='b')lastb=i;
    	if(s[i]=='c')lastc=i;
    }

    int firsta=0;
    while(firsta<n && s[firsta]!='a')firsta++;
    int firstb=0;
    while(firstb<n && s[firstb]!='b')firstb++;
    int firstc=0;
    while(firstc<n && s[firstc]!='c')firstc++;

    lasta=n;
    lastb=n;
    lastc=n;
    while(lasta>=0 && s[lasta]!='a')lasta--;
    while(lastb>=0 && s[lastb]!='b')lastb--;
    while(lastc>=0 && s[lastc]!='c')lastc--;

    for(int i=2;i<n;i++){
    	for(int j=0;j<3;j++){
    		// cout<<"HI"<<endl;
    		dp[i][j][0]=n;
    		dp[i][j][1]=-1;
    		dp[i][j][2]=-1;
    	}
    }


    dp[1][0][0]=firsta;
    dp[1][0][1]=lasta;
    dp[1][1][0]=firstb;
    dp[1][1][1]=lastb;
    dp[1][2][0]=firstc;
    dp[1][2][1]=lastc;

    if(n<=3){
    	cout<<s[0]<<endl;
    	return 0;
    }

    int cd = ceil((double)(n)/4);

    for(int i=2;i<=cd;i++){
    	for(int j=0;j<3;j++){//lastchar
    		int prev[3]={n,-1,-1};
    		for(int k=0;k<3;k++){
    			//prevlast

    			if(dp[i-1][k][0]==n || dp[i-1][k][1]==-1)continue;

    			int nextone = nextright[dp[i-1][k][0]][j];
    			int prevone = nextleft[dp[i-1][k][1]][j];

    			if(nextone>prevone) continue;

    			// cout<<nextone<<" "<<prevone<<endl;

    			if(prevone-nextone > prev[1]-prev[0]){
    				prev[0]=nextone;
    				prev[1]=prevone;
    				prev[2]=k;
    			}
    		}

    		dp[i][j][0]=prev[0];
    		dp[i][j][1]=prev[1];
    		dp[i][j][2]=prev[2];
    	}
    }

    // for(int i=1;i<=cd;i++){
    // 	for(int j=0;j<3;j++){
    // 		for(int k=0;k<3;k++){
    // 			cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    // 		}
    // 	}
    // }

    string ans;
    // cout<<cd<<endl;

    int mymax=INT_MIN;
    for(int j=0;j<3;j++){
    	if(dp[cd][j][1]-dp[cd][j][0]>=mymax){
    		mymax=dp[cd][j][1]-dp[cd][j][0];
    		ans.clear();
	    	int currj=j;
    		for(int i=cd;i>=1;i--){
    			if(currj==0)ans.append("a");
    			if(currj==1)ans.append("b");
    			if(currj==2)ans.append("c");
    			currj=dp[i][currj][2];
    		}
    		// break;
    	}
    }

    reverse(ans.begin(),ans.end());
    cout<<ans;

    if(ans.length()*2 - 1 >= n/2){
    	ans.pop_back();
    }

    reverse(ans.begin(),ans.end());
    cout<<ans;

    cout<<endl;
}

