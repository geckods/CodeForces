#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll avengercount(ll lower, ll upper, ll positions[], ll k){
//	cout<<positions[0]<<" "<<positions[1]<<endl;
//	cout<<lower<<" "<<upper<<" "<<lower_bound(positions,positions+k,lower)-positions<<endl;
	if(*(lower_bound(positions,positions+k,lower)) > upper){
		return 0;
	}
	else{
		return (upper_bound(positions,positions+k,upper)-lower_bound(positions,positions+k,lower));
	}
}


ll destroy(ll lower, ll upper, ll positions[], ll k, ll a, ll b){
	ll num = avengercount(lower,upper,positions,k);
	if(lower==upper){
		if(num==0){
			// if(k==96518){
			// 	cout<<lower<<endl;
			// }
			return a;
		}
		else{
			return b*num;
		}
	}
	else if (num==0){
		return a;
	}
	else{
		ll mid = lower+(upper-lower)/2;
		return min(b*num*(upper-lower+1),destroy(lower,mid,positions,k,a,b)+destroy(mid+1,upper,positions,k,a,b));
	}
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    ll n,k,a,b;
    cin>>n>>k>>a>>b;

    ll positions[k];
    for(int i=0;i<k;i++){
    	cin>>positions[i];
    }

    sort(positions,positions+k);

//    cout<<avengercount(1,3,positions,k)<<endl;

    cout<<destroy(1,pow(2,n),positions,k,a,b)<<endl;
}