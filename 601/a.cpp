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

	int t;
	cin>>t;

	for(int test=0;test<t;test++){
		int a,b;
		cin>>a>>b;

		int c = abs(b-a);

		int ans=0;
		ans+=c/5;
		c%=5;
		ans+=c/2;
		c%=2;
		ans+=c/1;
		c%=1;

		cout<<ans<<endl;

	}    

}
