#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

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

    	if(n%4!=0){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    		for(int i=2;i<=n;i+=2)cout<<i<<" ";
    		for(int i=1;i<=n-2;i+=2)cout<<i<<" ";
    		cout<<n+n/2-1<<endl;
    	}
    }
}