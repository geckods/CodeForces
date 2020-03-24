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

    ll q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll a,b;
    	cin>>a>>b;

    	string s;
    	cin>>s;

    	vector<ll> gaps;

    	ll currlength=0;
    	for(int i=0;i<s.size();i++){
    		if(s[i]=='.')currlength++;
    		else{
    			if(currlength>0)
	    			gaps.push_back(currlength);
	    		currlength=0;
    		}
    	}
    	
    	if(currlength>0)
	    	gaps.push_back(currlength);

	    

    }
}