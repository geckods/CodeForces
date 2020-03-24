#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int x,y,z;
   	cin>>x>>y>>z;
   	auto w=[=]{
   		if(y<x) return 1;
   		else if(y>=x && y<=z)return 2;
   		else return 3;
   	};
   	cout<<w()<<endl;
}