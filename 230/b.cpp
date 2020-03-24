#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	double w[n][n];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cin>>w[i][j];
   		}
   	}

   	double a[n][n];
   	double b[n][n];

   	for(int i=0;i<n;i++){
   		a[i][i]=w[i][i];
   		b[i][i]=0;
   	}

   	for(int i=0;i<n;i++){
   		for(int j=0;j<i;j++){
   			double curr=w[i][j];
   			double opp=w[j][i];

   			a[i][j]=a[j][i]=(curr+opp)/2;
   			b[i][j]=w[i][j]-a[i][j];
   			b[j][i]=w[j][i]-a[j][i];
   		}
   	}

   	cout.precision(10);

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cout<<fixed<<a[i][j]<<" ";
   		}
   		cout<<endl;
   	}

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cout<<fixed<<b[i][j]<<" ";
   		}
   		cout<<endl;
   	}
}