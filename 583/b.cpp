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


    int b,g,n;
    cin>>b>>g>>n;

    int ans=n+1;
    
    if(n<=max(b,g)){
	    ans=min(ans,b+1);
    	ans=min(ans,g+1);
	}
	else{
		ans=max(b,g)-(n-min(b,g))+1;
	}
	cout<<ans<<endl;

}    
