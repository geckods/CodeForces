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

    ll n,h;
    cin>>n>>h;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll bmin=1;
    ll bmax=n;
    ll prevmid=-1;
    ll bmid=0;

    while(bmid!=prevmid){
    	prevmid=bmid;
    	bmid=(bmin+bmax)/2;

    	ll newarr[bmid];
    	for(int i=0;i<bmid;i++){
    		newarr[i]=arr[i];
    	}
    	sort(newarr,newarr+bmid);

    	ll i=bmid-1;
    	ll sum=0;
    	while(i>=0){
    		sum+=newarr[i];
    		i-=2;
    	}

    	// cout<<bmin<<" "<<bmax<<endl;

    	if(sum<=h){
    		bmin=bmid;
    	}
    	else{
    		bmax=bmid-1;
    	}
    }


    sort(arr,arr+bmax);
    ll sum=0;
    ll ind = bmax-1;
    while(ind>=0){
    	sum+=arr[ind];
    	ind-=2;
    }

    if(sum>h){
    	cout<<bmax-1<<endl;
    }
    else{
    	cout<<bmax<<endl;
    }
    return 0;
}