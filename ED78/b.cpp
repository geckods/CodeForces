#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
1
3
6
10
15
21
*/


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

    	ll c = min(a,b);
    	ll d = max(a,b);

    	ll diff = d-c;

    	ll x = 0;
    	while((x*(x+1))/2<diff)x++;

    	ll xt = (x*(x+1))/2;

    	// cout<<x<<" "<<x*(x+1)/2-diff<<endl;
    	if(xt==diff)cout<<x<<endl;
    	else{

    		while((xt-diff)%2!=0){
    			x++;
    			xt=x*(x+1)/2;
    		}

    		cout<<x<<endl;
    	}

    }
}