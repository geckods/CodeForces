#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll maxVal;
    maxVal=(n*(n+1))/2;
    maxVal-=((n-k)*(n-k+1))/2;

    ll permNum=1;
    //place k-1 spaces between the highest k numbers
    vector<ll> temp;
    for(int i=0;i<n;i++){
    	if(arr[i]>n-k){
    		temp.push_back(i);
    	}
    }

    for(int i=1;i<temp.size();i++){
    	permNum*=(temp[i]-temp[i-1]);
    	permNum%=MOD;
    }


    cout<<maxVal<<" "<<permNum<<endl;
}