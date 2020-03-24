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

    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll cumul[n];
    ll cum=0;
    for(int i=0;i<n;i++){
    	cum+=arr[i];
    	cumul[i]=cum;
    }

    map<ll,int> countmap;

    for(int i=0;i<n;i++){
    	countmap[cumul[i]]++;
    }

    ll ans=0;

//    cout<<countmap[0]<<endl;

    for(int i=0;i<n;i++){
    	countmap[cumul[i]]--;
    	if(cumul[n-1]-cumul[i]==cumul[i]*2){
	    	ans+=countmap[cumul[i]*2];
//    		cout<<i<<cumul[i]<<ans<<endl;
	    	if(cumul[n-1]==cumul[i]*2 && i<n-1){
	    		ans--;
	    	}
    	}
    }

    cout<<ans<<endl;

}
