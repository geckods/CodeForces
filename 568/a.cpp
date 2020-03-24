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

    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;

    sort(arr,arr+3);

    ll ans1=0;
    if(arr[1]<arr[0]+d){
    	ans1+=(arr[0]+d-arr[1]);
    }
    if(arr[2]<max(arr[0]+2*d,arr[1]+d)){
    	ans1+=(max(arr[0]+2*d,arr[1]+d)-arr[2]);    	
    }

    ll ans2=0;
    if(arr[0]>arr[1]-d){
    	ans2+=arr[0]-(arr[1]-d);
    }
    if(arr[2]<arr[1]+d){
    	ans2+=arr[1]+d-arr[2];
    }

    ll ans3=0;
    if(arr[1]>arr[2]-d){
    	ans3+=arr[1]-(arr[2]-d);
    }

    if(arr[0]>min(arr[2]-2*d,arr[1]-d)){
    	ans3+=arr[0]-min(arr[2]-2*d,arr[1]-d);
    }

    cout<<min(min(ans1,ans2),ans3)<<endl;

}
