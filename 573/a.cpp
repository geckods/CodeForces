#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin>>x;

    if(x%4==0){
    	cout<<1<<" "<<"A"<<endl;
    }
    else if (x%4==1){
    	cout<<0<<" "<<"A"<<endl;
    }
    else if (x%4==2){
    	cout<<1<<" "<<"B"<<endl;
    }
    else{
    	cout<<2<<" "<<"A"<<endl;
    }
}
