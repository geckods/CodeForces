#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,h;
    cin>>n>>m>>h;

    int a[m];
    for(int i=0;i<m;i++){
    	cin>>a[i];
    }

    int b[n];
    for(int i=0;i<n;i++){
    	cin>>b[i];
    }

    int ispos[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>ispos[i][j];
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(ispos[i][j]==0) cout<<0;
    		else cout<<min(a[j],b[i]);
    		cout<<" ";
    	}
    	cout<<endl;
    }
}