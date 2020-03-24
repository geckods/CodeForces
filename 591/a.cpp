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

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int n;
    	cin>>n;

    	if(n<4){
    		cout<<4-n<<endl;
    	}
    	else{
    		if(n%2==1){
    			cout<<1<<endl;
    		}
    		else{
    			cout<<0<<endl;
    		}
    	}
    }
}
