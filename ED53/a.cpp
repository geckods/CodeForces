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

    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<n-1;i++){
    	if(s[i]!=s[i+1]){
    		cout<<"YES"<<endl;
    		cout<<s[i]<<" "<<s[i+1]<<endl;
    		return 0;
    	}
    }

    cout<<"NO"<<endl;

}
