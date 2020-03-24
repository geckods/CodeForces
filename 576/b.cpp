#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

	double l,h;
	cin>>h>>l;

	double x;

	x = pow(l,2)/(2*h);
	x-=(h/2);	   	


	cout<<setprecision(15)<<x<<endl;
}
