#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes
typedef pair<ll,ll> intpair;
int arr[10000000];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;


    while(t--){
	    map<pair<intpair,char>,bool> myMap;
    	ll ans=0;
    	string s;
    	cin>>s;

    	ll x=0;
    	ll y=0;
    	for(int i=0;i<s.size();i++){

    		intpair other;
    		other.first=x;
    		other.second=y;
    		char oc;
    		switch(s[i]){
    			case 'N':
	    			other.second++;
	    			oc='S';
    				break;
    			case 'S':
    				other.second--;
    				oc='N';
    				break;
    			case 'E':
    				oc='W';
    				other.first++;
    				break;
    			case 'W':
    				oc='E';
    				other.first--;
    				break;
    		}

    		if(myMap[{{x,y},s[i]}] || myMap[{other,oc}]){
    			ans++;
    		}
    		else{
    			ans+=5;
    		}
    		myMap[{{x,y},s[i]}]=true;
    		switch(s[i]){
    			case 'N':
	    			y++;
    				break;
    			case 'S':
    				y--;
    				break;
    			case 'E':
    				x++;
    				break;
    			case 'W':
    				x--;
    				break;

    		}
    	}

    	cout<<ans<<endl;
    }

}