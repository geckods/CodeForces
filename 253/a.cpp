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

    string s;
    getline(cin,s);


    unordered_set<char> mySet;

    for(int i=0;i<s.length();i++){
    	// cout<<s[i]<<endl;
    	if(s[i]>='a' && s[i]<='z'){
    		mySet.insert(s[i]);
    	}
    }

    cout<<mySet.size()<<endl;
}