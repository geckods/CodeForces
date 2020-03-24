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

   	for(int j=1;j<=m/2;j++){
	   	for(int i=1;i<=n;i++){
	   		printf("%d %d\n",i,j);
	   		printf("%d %d\n",n-i+1,m-j+1);
   		}
   	}

   	if(m%2==1){
	   	for(int i=1;i<=n/2;i++){
	   		printf("%d %d\n",i,(m+1)/2);
	   		printf("%d %d\n",n-i+1,(m+1)/2);
   		}

   		if(n%2==1){
	   		printf("%d %d\n",(n+1)/2,(m+1)/2);
   		}
   	}
}