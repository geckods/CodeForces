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

   	ll arr[m][5];
   	for(int i=0;i<m;i++){
   		for(int j=0;j<5;j++){
   			arr[i][j]=0;
   		}
   	}

   	for(int i=0;i<n;i++){
   		string s;
   		cin>>s;

   		for(int j=0;j<m;j++){
   			arr[j][s[j]-'A']++;
   		}

   	}

   	ll ans=0;

   	ll currscore;

   	for(int i=0;i<m;i++){
   		cin>>currscore;
   		ll maxof=0;
   		for(int j=0;j<5;j++){
   			maxof=max(maxof,arr[i][j]);
   		}

   		ans+=maxof*currscore;

   	}

   	cout<<ans<<endl;

}
