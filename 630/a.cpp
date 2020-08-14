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

    // =

    ll t;
    cin>>t;
    while(t--){
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;
    	ll x,y,x1,y1,x2,y2;
    	cin>>x>>y>>x1>>y1>>x2>>y2;

    	bool works=true;
    	if(a+b>0){
    		//must move left or right
    		if(x==x1 && x==x2){
    			works=false;
    		}
    	}

    	if(c+d>0){
    		if(y==y1 && y==y2){
    			works=false;
    		}
    	}

    	ll fx=x-a+b;
    	ll fy=y-c+d;
    	if(fx>x2 || fx<x1 || fy>y2 || fy<y1){
    		works=false;
    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    }
}
