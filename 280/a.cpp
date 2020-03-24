#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,l;
	cin>>n>>l;

	vector<int> lanterns;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		lanterns.push_back(a);
	} 

	sort(lanterns.begin(),lanterns.end());

	double ans=0;

	for(int i=1;i<n;i++){
		ans = max(ans,(lanterns[i]-lanterns[i-1])/2.0);
	}

	ans=max(ans,(double)lanterns[0]);
	ans=max(ans,(double)l-lanterns[n-1]);

	cout<<setprecision(10)<<fixed<<ans<<endl;
}
