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

	int x,y,z;

	cin>>x>>y>>z;

	int ans = x-y;

	if(ans==0){
		if(z==0){
			cout<<0<<endl;
			return 0;
		}
		else{
			cout<<"?"<<endl;
			return 0;
		}
	}

	if(abs(ans)>z){
		if(ans>0){
			cout<<"+"<<endl;
		}
		else{
			cout<<"-"<<endl;
		}
	}    
	else{
		cout<<"?"<<endl;
	}
}
