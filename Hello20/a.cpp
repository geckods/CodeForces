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

    int n,m;
    cin>>n>>m;

    vector<string> narr;
    vector<string> marr;

    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	narr.push_back(s);
    }

    for(int i=0;i<m;i++){
    	cin>>s;
    	marr.push_back(s);
    }

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll y;
    	cin>>y;

    	y--;
    	cout<<narr[y%n]<<marr[y%m]<<endl;
    }
}
