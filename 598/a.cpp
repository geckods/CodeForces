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

    int q;
    cin>>q;
    for(int quer=0;quer<q;quer++){
    	ll a,b,n,s;
    	cin>>a>>b>>n>>s;

    	if(n*a+b < s){
    		cout<<"NO"<<endl;
    		continue;
    	}

    	if(b<s%n){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}

    }
}
