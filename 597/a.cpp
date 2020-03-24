#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
	if(a==0)return b;
	return gcd(b%a,a);
}



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

	    int a,b;
    	cin>>a>>b;

    	if(gcd(a,b)==1){
    		cout<<"Finite"<<endl;
    	}
    	else{
    		cout<<"Infinite"<<endl;
    	}
    }


}
