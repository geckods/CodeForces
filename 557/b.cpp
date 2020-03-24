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

   	ll n,m;
   	cin>>n>>m;

   	ll arr1[n][m];
   	ll arr2[n][m];

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>arr1[i][j];
   		}
   	}

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>arr2[i][j];
   		}
   	}

   	ll minarr[n][m];
   	ll maxarr[n][m];

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			minarr[i][j]=min(arr1[i][j],arr2[i][j]);
   			maxarr[i][j]=max(arr1[i][j],arr2[i][j]);
   		}
   	}

   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<m;j++){
   	// 		cout<<minarr[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }

   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<m;j++){
   	// 		cout<<maxarr[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }


   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			ll thismax = maxarr[i][j];
   			ll thismin = minarr[i][j];
   			for(int k=i+1;k<n;k++){
   				if(thismax>=maxarr[k][j] ||  thismin>=minarr[k][j]){
   					cout<<"Impossible"<<endl;
   					// cout<<i<<" "<<j<<" "<<k<<endl;
   					return 0;
   				}
   			}

   			for(int k=j+1;k<m;k++){
   				if(thismax>=maxarr[i][k]  ||  thismin>=minarr[i][k]){
   					cout<<"Impossible"<<endl;
   					return 0;
   				}
   			}

   		}
   	}

   	cout<<"Possible"<<endl;
   	return 0;

}
