#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    int a,x,b,y;

    cin>>n>>a>>x>>b>>y;

    int d,v;
    d = a;
    v = b;

    while(1){
    	if(d==v){
    		cout<<"YES"<<endl;
    		return 0;
    	}

    	if(d==x || v==y){
    		cout<<"NO"<<endl;
    		return 0;
    	}

    	d++;
    	v--;
    	if(d==n+1) d=1;
    	if(v==0) v=n;

    }

}
