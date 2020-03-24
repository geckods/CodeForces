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

    int a[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>a[i][j];
    	}
    }

    int b[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>b[i][j];
    	}
    }

    // int tlbrxora[n+m-1];
    // int tlbrxorb[n+m-1];
    // int trblxora[n+m-1];
    // int trblxorb[n+m-1];

    int rowa[n];
    int rowb[n];
    int cola[m];
    int colb[m];

    for(int i=0;i<n;i++){
    	// tlbrxora[i]=tlbrxorb[i]=trblxora[i]=trblxorb[i]=0;
    	rowa[i]=rowb[i]=0;
    }

    for(int i=0;i<m;i++){
    	// tlbrxora[i]=tlbrxorb[i]=trblxora[i]=trblxorb[i]=0;
    	cola[i]=colb[i]=0;
    }


    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		// tlbrxora[i-j+m-1]^=a[i][j];
    		// tlbrxorb[i-j+m-1]^=b[i][j];
    		// trblxora[i+j]^=a[i][j];
    		// trblxorb[i+j]^=b[i][j];    		
    		rowa[i]^=a[i][j];
    		cola[j]^=a[i][j];
    		rowb[i]^=b[i][j];
    		colb[j]^=b[i][j];
    	}
    }

    for(int i=0;i<n;i++){
    	// if(tlbrxora[i]!=trblxorb[i] || trblxora[i]!=trblxorb[i]){
    		// cout<<"No"<<endl;
    		// return 0;
    	// }
    	if(rowa[i]!=rowb[i]){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }

    for(int j=0;j<m;j++){
    	if(cola[j]!=colb[j]){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }

    cout<<"Yes"<<endl;
}

