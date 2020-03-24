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

    if(n==1){
    	cout<<1<<endl;
    	cout<<1<<" "<<1<<endl;
    	return 0;
    }

    int m = ceil(((double)n+1)/2);

    cout<<m<<endl;

    cout<<1<<" "<<1<<endl;
    for(int i=2;i<=min(m+1,n-1);i++){
    	cout<<2<<" "<<i-1<<endl;
    }

    for(int i=min(m+1,n-1)+1;i<=n-1;i++){
    	cout<<i-m+1<<" "<<m<<endl;
    }

    cout<<m<<" "<<m<<endl;
}