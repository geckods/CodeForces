#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b,k;
    cin>>n>>a>>b>>k;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	vector<ll> myVec;
   	ll temp;
   	for(int i=0;i<n;i++){
   		temp=arr[i]%(a+b);
   		// cout<<temp<<endl;
   		if(temp>=1&&temp<=a){
   			myVec.push_back(0);
   		}
   		else{
   			if(temp>0){   				
   				// x=arr[i]/(a+b)
   				myVec.push_back(ceil(( (double)arr[i]-((a+b)*(arr[i]/(a+b))+a))/a));
   			}
   			else{
   				// cout<<i<<" "<<(a+b)*((arr[i]-1)/(a+b))+a<<endl;
	   			myVec.push_back(ceil(( (double)arr[i]-((a+b)*((arr[i]-1)/(a+b))+a))/a));
   			}
   		}
   		// cout<<i<<" "<<myVec[myVec.size()-1]<<endl;
   	}
   	sort(myVec.begin(),myVec.end());
   	ll ans=0;
   	ll curr=0;
   	for(int i=0;i<n;i++){
   		curr+=myVec[i];
   		if(curr<=k){
   			ans++;
   		}
   	}
   	cout<<ans<<endl;
}