#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==d && ((c>0 && a>0)||c==0)){
    	cout<<1<<endl;
    }
    else{
    	cout<<0<<endl;
    }
}
