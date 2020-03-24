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

   	ll n,l,r;

   	cin>>n>>l>>r;

   	cout<<(n-l+1)+(ll)pow(2,l)-2<<" "<<(n-r+2)*(ll)pow(2,r-1)-1<<endl;
}