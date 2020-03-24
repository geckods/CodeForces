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

    ll t;
    cin>>t;
    for(int test=0;test<t;test++){
    	ll a,b,k;
    	cin>>a>>b>>k;

    	if(k%2==0){
    		cout<<(a-b)*(k/2)<<endl;
    	}
    	else{
    		cout<<(a-b)*(k/2)+a<<endl;
    	}
    }

}
