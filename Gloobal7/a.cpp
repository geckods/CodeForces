#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;

    	if(n==1){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<2;
    		for(int i=0;i<n-1;i++){
    			cout<<3;
    		}
    		cout<<endl;
    	}
    }

}
