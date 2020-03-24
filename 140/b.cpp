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

	int n;
	cin>>n;

	int location[n];
	int x;

	for(int i=0;i<n;i++){
		cin>>x;
		x--;
		location[x]=i;
	}

	int m;
	cin>>m;

	ll ans1=0;
	ll ans2=0;

	for(int i=0;i<m;i++){
		cin>>x;
		x--;
		ans1+=location[x]+1;
		ans2+=n-location[x];
	}

	cout<<ans1<<" "<<ans2<<endl;
}