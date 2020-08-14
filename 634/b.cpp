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
    	ll n,a,b;
    	cin>>n>>a>>b;

    	int curr=0;
    	string s;
    	for(int i=0;i<n;i++){
    		s+='a'+curr;
    		curr++;
    		curr%=b;
    	}
    	cout<<s<<endl;

    }
}