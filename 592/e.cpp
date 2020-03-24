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

  	ll n,k;
  	cin>>n>>k;

  	ll arr[n];
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}

  	sort(arr,arr+n);

  	ll weight=1;
  	int i=0;
  	int j=n-1;


  	while(1){

  		if(i>=j){
  			cout<<0<<endl;
  			return 0;
  		}
  		// cout<<i<<" "<<j<<" "<<k<<endl;

  		ll thingy=weight*(arr[i+1]-arr[i] + arr[j]-arr[j-1]);
  		if(i==j-1)thingy/=2;

  		if(k>thingy){
  			k-=thingy;
  			i++;
  			j--;
  			weight++;
  		}
  		else{
  			cout<<arr[j]-arr[i]-k/weight<<endl;
  			return 0;
  		}
  	}

}