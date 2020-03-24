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

    for(int test=0;test<t;test++){
    	ll a,b;
    	cin>>a>>b;
    	ll c,d;
    	c=min(a,b);
    	d=max(a,b);

    	if(d>2*c){
    		cout<<"NO"<<endl;
    	}
    	else{
    		if((c+d)%3==0){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
}