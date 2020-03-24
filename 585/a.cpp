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

	int a1,a2;
	int k1,k2;
	int n;

	cin>>a1>>a2>>k1>>k2>>n;

	int mina = max(n-(a1*(k1-1)+a2*(k2-1)),0);

	int c1,c2,d1,d2;

	if(k1<k2){
		d1 = k1;
		d2  = k2;
		c1 = a1;
		c2 = a2;
	}
	else{
		d1 = k2;
		d2 = k1;
		c1 = a2;
		c2 = a1;
	}

	int maxa; 

	if(n <= d1*c1){
		maxa=n/d1;
	}
	else{
		maxa=c1+((n-d1*c1)/d2);
		maxa=min(maxa,c1+c2);
	}

	cout<<mina<<" "<<maxa<<endl;


}
