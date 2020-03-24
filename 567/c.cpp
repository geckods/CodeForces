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

   	int n,m;
   	cin>>n>>m;

   	char grid[n][m];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>grid[i][j];
   		}
   	}

   	int bottomflag[n][m];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			bottomflag[i][j]=0;
   		}
   	}


   	for(int j=0;j<m;j++){
   		int curri=0;
   		//track three colors;
   		while(curri<n){
	   		int coloroneind=curri+1;
	   		while(coloroneind<n && grid[coloroneind][j]==grid[coloroneind-1][j]){
	   			coloroneind++;
	   		}
	   		coloroneind--;//it is now the last grid square with the first color
	   		if(coloroneind>=n-1){
	   			for(int i=curri;i<n;i++){
	   				bottomflag[i][j]=0;
	   			}
	   			break;
	   		}

	   		int colortwoind=coloroneind+2;
	   		while(colortwoind<n && grid[colortwoind][j]==grid[colortwoind-1][j]){
	   			colortwoind++;
	   		}
	   		colortwoind--;//it is now the last grid square with the second color

	   		if(colortwoind-coloroneind > coloroneind-curri+1){
	   			for(int i=curri;i<=coloroneind;i++){
	   				bottomflag[i][j]=0;
	   			}
	   			curri = coloroneind+1;
	   			continue;
	   		}

	   		if(colortwoind>=n-1){
	   			for(int i=curri;i<n;i++){
	   				bottomflag[i][j]=0;
	   			}
	   			break;
	   		}

	   		int colorthreeind=colortwoind+2;
	   		while(colorthreeind<n && grid[colorthreeind][j]==grid[colorthreeind-1][j]){
	   			colorthreeind++;
	   		}
	   		colorthreeind--;//it is now the last grid square with the third color


	   		// cout<<" "<<j<<" "<<coloroneind<<" "<<colortwoind<<" "<<colorthreeind<<endl;

	   		int minlen=colortwoind-coloroneind;

	   		if(colorthreeind-colortwoind<minlen){
	   			for(int i=curri;i<=coloroneind;i++){
	   				bottomflag[i][j]=0;
	   			}
	   			curri=coloroneind+1;
	   			continue;	   			
	   		}

	   		bottomflag[coloroneind-minlen+1][j]=pow(26,3)*minlen+pow(26,2)*(grid[coloroneind][j]-'a')+pow(26,1)*(grid[colortwoind][j]-'a')+pow(26,0)*(grid[colorthreeind][j]-'a');
			curri=coloroneind+1;
		}
   	}

   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<m;j++){
   	// 		cout<<bottomflag[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }

   	ll ans=0;
   	for(int i=0;i<n;i++){
   		int currj=0;
   		while(currj<m){
   			if(bottomflag[i][currj]==0){
   				currj++;
   				continue;
   			}
	   	// cerr<<"HI"<<endl;
   			int newj=currj+1;
   			while(newj<m && bottomflag[i][newj]==bottomflag[i][currj]){
   				newj++;
   			}
   			newj--;

   			int len=newj-currj+1;
   			ans+=((len)*(len+1))/2;
   			currj=newj+1;
   		}
   	}
   	cout<<ans<<endl;
}