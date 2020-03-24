#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){

    	map<intpair,int> myMap;

    	int n;
    	cin>>n;
    	string s;
    	cin>>s;

    	ll x=0,y=0;
    	ll ans=INT_MAX;
    	ll currrangemin=0;
    	ll currrangemax=0;

    	for(int i=0;i<n;i++){
    		// cout<<i<<" "<<x<<" "<<y<<endl;
    		if(myMap[{x,y}]>0){
    			if(i-myMap[{x,y}]<ans){
    				ans=i-myMap[{x,y}];
    				currrangemin=myMap[{x,y}];
    				currrangemax=i;
    			}
    		}
    		myMap[{x,y}]=i+1;
    		switch(s[i]){
    			case 'L':
    				x--;
    				break;
    			case 'R':
    				x++;
    				break;
    			case 'U':
    				y++;
    				break;
    			case 'D':
    				y--;
    				break;
    		}
    	}
		if(myMap[{x,y}]>0){
			if(n-myMap[{x,y}]<ans){
				ans=n-myMap[{x,y}];
				currrangemin=myMap[{x,y}];
				currrangemax=n;
			}
		}


    	if(ans==INT_MAX){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<currrangemin<<" "<<currrangemax<<endl;
    	}
    }
}