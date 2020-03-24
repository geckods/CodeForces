#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
	int r,g,b;
	cin>>r>>g>>b;
	int rc=ceil(r/2.0), gc=ceil(g/2.0), bc=ceil(b/2.0);

	int ans=0;
	ans=max(ans,30+(rc-1)*3);
	ans=max(ans,31+(gc-1)*3);
	ans=max(ans,32+(bc-1)*3);
	cout<<ans<<endl;
}