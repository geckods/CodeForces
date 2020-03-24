#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int c,m,x;
    	cin>>c>>m>>x;

    	int ans;
    	ans=min(c,m);

    	if(ans*3>c+m+x){
    		ans=(c+m+x)/3;
    	}
    	cout<<ans<<endl;
    }
}