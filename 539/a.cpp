#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,v;
    cin>>n>>v;

    int a=n-v;
/*

    int ans=0;
    while(a>=1){
    	ans+=a*v;
    	a-=v;
    }
    if(a<1)a+=v;
    ans+=a-1;
*/

    if(v>=n-1){
    	cout<<n-1<<endl;
    	return 0;
    }

    int ans=v;
    for(int i=2;i<=n-v;i++){
    	ans+=i;
    }

    cout<<ans<<endl;

}
