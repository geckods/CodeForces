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

    ll ans=0;

    int n;
    cin>>n;

    for(int i=2;i<=n-1;i++){
    	ans+=i*(i+1);
    }
    cout<<ans<<endl;
}