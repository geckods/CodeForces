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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n,k;
    	cin>>n>>k;

    	if(n<k || k%3!=0){
    		if(n%3==0){
    			cout<<"Bob"<<endl;
    		}
    		else{
    			cout<<"Alice"<<endl;
    		}
    	}
    	else{
    		n%=(k+1);
    		if(n%3!=0 || n==k){
    			cout<<"Alice"<<endl;
    		}
    		else{
    			cout<<"Bob"<<endl;
    		}
    	}
    }
}