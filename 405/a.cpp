#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int a,b;
    cin>>a>>b;

    int x = 0;
    while(a<=b){
    	a = a*3;
    	b = b*2;
    	x++;
    }

    cout<<x<<endl;
}
