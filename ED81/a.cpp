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
    	int n;
    	cin>>n;

    	string ans;
    	for(int i=0;i<n/2;i++){
    		ans.push_back('1');
    	}
    	n%=2;
    	if(n==1){
    		ans[0]='7';
    	}
    	cout<<ans<<endl;

    }

}
