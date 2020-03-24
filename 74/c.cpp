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
	long long int n,m,k;
	cin>>n>>m>>k;
	long long int r[n], ans=INT_MAX;
	for(int i=0; i<n; i++)
	{
		cin>>r[i];
		if(i%2==0)
			ans=min(ans,r[i]);
	}
	if(n==1) 
	{
		cout<<(k*m<r[0]?k*m:r[0])<<endl;
		return 0;
	}
	ans=min(ans,k*(m/(n/2+1)));
	if(n%2==0) ans=0;
	cout<<ans<<endl;
}
