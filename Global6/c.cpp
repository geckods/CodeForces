#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r,c;
    cin>>r>>c;

    if(r==c && r==1){
    	cout<<0<<endl;
    	return 0;
    }

    if(r==1){
    	for(int j=0;j<c;j++){
    		cout<<j+2<<" ";
    	}
    	cout<<endl;
    	return 0;
    }

    if(c==1){
    	for(int i=0;i<r;i++){
    		cout<<i+2<<endl;
    	}
    	cout<<endl;
    	return 0;    	
    }


    int ans[r][c];

    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		ans[i][j]=i+1;
    	}
    }


    for(int j=0;j<c;j++){
    	for(int i=0;i<r;i++){
    		ans[i][j]*=r+1+j;
    	}
    }

    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cout<<ans[i][j]<<" ";
    	}
    	cout<<endl;
    }
}