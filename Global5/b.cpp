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

   	int n;
   	cin>>n;

   	vector<int>enter;
   	vector<int>exit;

   	int x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		enter.push_back(x);
   	}

   	for(int i=0;i<n;i++){
   		cin>>x;
   		exit.push_back(x);
   	}

   	int i=0;
   	int j=0;

   	int entered[n+1];
   	int exited[n+1];
   	memset(entered,0,sizeof(entered));
   	memset(exited,0,sizeof(exited));

   	int ans=0;
   	while(j<n){
   		while(!exited[enter[i]]){
   			// cout<<i<<" "<<j<<" "<<enter[i]<<" "<<exit[j]<<endl;
   			if(enter[i]!=exit[j])
	   			ans++;
   			exited[exit[j++]]=1;
   		}
   		i++;
   		if(i==n)break;
   		// cout<<i<<" "<<j<<endl;
   	}

   	cout<<ans<<endl;
}
