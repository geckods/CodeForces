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

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	sort(arr,arr+n);

   	//just add the i-mth day

   	ll currsum=0;
   	ll currans;
   	vector<ll> ans;

   	for(int i=0;i<n;i++){
   		currsum+=arr[i];
   		currans=currsum;

   		if(i>=m){
   			currans+=ans[i-m];
   		}
   		ans.push_back(currans);
   	}

   	for(int i=0;i<n;i++){
   		cout<<ans[i]<<" ";
   	}
   	cout<<endl;
}