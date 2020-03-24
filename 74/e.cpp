#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("fma") 
int myans(vector<string> myVec, int a, int b){
	int ans=0;
	int n=myVec.size();
	int m=myVec[0].size();

	while(1){
		ans++;
		if(myVec[a][b]=='U'){
			myVec[a][b]='.';
			a--;
			while(a>=0 && myVec[a][b]=='.')a--;
		}
		else if (myVec[a][b]=='R'){
			myVec[a][b]='.';
			b++;
			while(b<m && myVec[a][b]=='.')b++;
		}
		else if (myVec[a][b]=='D'){
			myVec[a][b]='.';
			a++;
			while(a<n && myVec[a][b]=='.'){
				a++;
			}
		}
		else{
			myVec[a][b]='.';
			b--;
			while(b>=0 && myVec[a][b]=='.')b--;
		}
		if(a<0 || a==n || b<0 || b==m)break;
	}
	return ans;
}

int main(){
 
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    ll n,m;
    cin>>n>>m;

    vector<string> myVec;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	myVec.push_back(s);
    }

    int currmax=0;
    int currcount=0;

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(myVec[i][j]!='.'){
    			int currans=myans(myVec,i,j);
    			if(currans>currmax){
    				currmax=currans;
    				currcount=1;
    			}
    			else if (currans==currmax){
    				currcount++;
    			}
    		}
    	}
    }
    cout<<currmax<<" "<<currcount<<endl;
}

