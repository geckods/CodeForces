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

    if(n%2==1){
    	cout<<0<<endl;
    	return 0;
    }
    cout.precision(63);
    cout<<pow(2,(ll)n/2)<<endl;
}