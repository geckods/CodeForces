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

    ll root = sqrt(n);

    ll ans=2*root;

    ll mod = n-(root*root);

    if(mod>0 && mod<=root){
    	ans++;
    }
    else if (mod>root){
    	ans+=2;
    }
    cout<<ans<<endl;
}