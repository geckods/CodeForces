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

    int t;
    cin>>t;

    while(t--){
    	string s;
    	cin>>s;

    	int n=s.length();
    	int firstone=0;
    	while(firstone<n && s[firstone]=='0')firstone++;

    	int lastone=n-1;
    	while(lastone>=0 && s[lastone]=='0')lastone--;

    	int ans=0;
    	for(int i=firstone;i<lastone;i++){
    		if(s[i]=='0')ans++;
    	}

    	cout<<ans<<endl;

    }

}
