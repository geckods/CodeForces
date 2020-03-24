#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<char> charVec;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(char c = 'a';c<='z';c++)charVec.push_back(c);
    for(char c = 'A';c<='Z';c++)charVec.push_back(c);
    for(char c = '0';c<='9';c++)charVec.push_back(c);

    for(int test=0;test<t;test++){
    	int r,c,k;
    	cin>>r>>c>>k;

    	char arr[r][c];
    	int ricecount=0;
    	for(int i=0;i<r;i++){
    		for(int j=0;j<c;j++){
    			cin>>arr[i][j];
    			if(arr[i][j]=='R')ricecount++;
    		}
    	}

    	int base = ricecount/k;

    	int togiveextra = ricecount%k;
    	int togivebase = k-togiveextra;

    	char ans[r][c];

    	int charpointer=0;
    	int currcellcount=0;
    	int currricecount=0;

    	for(int i=0;i<r;i++){
    		for(int j=0;j<c;j++){
    			int whichj = j;
    			if(i%2==1){
    				whichj=c-j-1;
    			}

    			ans[i][whichj]=charVec[charpointer];
    			// cout<<ans[i][whichj]<<endl;
    			if(arr[i][whichj]=='R')
	    			currricecount++;

	    		if(charpointer<k-1){
	    			if(currricecount==base && togivebase>0){
	    				currricecount=0;
	    				charpointer++;
	    				togivebase--;
	    			}
	    			else if (currricecount>base){
	    				currricecount=0;
	    				charpointer++;
	    				togiveextra--;
	    			}
	    		}

    		}
    	}

    	for(int i=0;i<r;i++){
    		for(int j=0;j<c;j++){
    			cout<<ans[i][j];
    		}
    		cout<<endl;
    	}

    }
}
