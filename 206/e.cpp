#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//if k<smallest number, ans=smallest number
//else{
	// minans=k;
	// binary search in range k to smallest number, 0(n) check if it works	
//}

bool works(ll arr[], ll n, ll k, ll g){
	for(int i=0;i<n;i++){
		if((arr[i]-k)/g != arr[i]/g || (arr[i]-k)%g==0){

		}
		else{
			return false;
		}
	}
	return true;
}

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
    ll minno=INT_MAX;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	minno=min(minno,arr[i]);
    }

    if(k>=minno){
    	cout<<minno<<endl;
    	return 0;
    }
    else{
    	int poss=minno;
    	while(!works(arr,n,k,poss)){
    		poss--;
    	}
    	cout<<poss<<endl;
    }

}
