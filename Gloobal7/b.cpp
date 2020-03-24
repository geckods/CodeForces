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

    ll n;
    cin>>n;

    ll b[n];
    for(int i=0;i<n;i++){
    	cin>>b[i];
    }

    ll a[n];
    a[0]=b[0];
    ll maxtill=a[0];

    for(int i=1;i<n;i++){
    	a[i]=maxtill+b[i];
    	maxtill=max(maxtill,a[i]);
    }

    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
    }
    cout<<endl;
}