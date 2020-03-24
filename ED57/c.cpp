#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

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
    	int ang;
    	cin>>ang;

    	for(int i=3;i<=360;i++){
    		double base = 180.0/i;
    		double ans=base;
    		double z=1;
    		bool done=false;
    		while(z<i-2 && ans<ang){
    			ans+=base;
    			z++;
    		}
    		if((int)ans==ang && ans-(int)ans < pow(10.0,-6)){
    			cout<<i<<endl;
    			break;
    		}
    	}
    }
}