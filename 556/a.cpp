#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,r;
    cin>>n>>m>>r;

    int s[n];
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }

    int b[m];
	for(int i=0;i<m;i++){
    	cin>>b[i];
    }

    sort(s,s+n);
    sort(b,b+m);

    cout<<max(r,(r/s[0])*b[m-1] + r%s[0])<<endl;
}
