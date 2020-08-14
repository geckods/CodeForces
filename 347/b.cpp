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

    int i = 2;
    vector<bool> pos;
    pos.push_back(true);
    ll posCount = 1;
    ll negCount = 0;
    while(s[i]!='='){
    	if(s[i]=='+'){
    	// cerr<<s[i]<<" ";
    		pos.push_back(true);
    		posCount++;
    	}
    	else{
    		pos.push_back(false);
    		negCount++;
    	}
    	i+=4;
    }

    i += 2;


    ll n = stoi(s.substr(i,20));
    // cerr<<"HI"<<endl;

    if(posCount*n - negCount*1<n || posCount*1 - negCount*n>n){
    	cout<<"Impossible"<<endl;
    	return 0;
    }

    ll m = pos.size();
    ll prefixCount[m];
    prefixCount[m-1]=n;
    for(int i=m-2;i>=0;i--){
    	prefixCount[i]=prefixCount[i+1];
    	if(pos[i+1])prefixCount[i]--;
    	else prefixCount[i]++;
    }

    vector<ll> ans;
    ll curr = 0;
    for(int i=0;i<pos.size();i++){
    	if(pos[i]){
    		ans.push_back(max(1ll,min(n,prefixCount[i]-curr)));
    		curr += max(1ll,min(n,prefixCount[i]-curr));
    	}
    	else {
    		ans.push_back(max(1ll,min(n,curr-prefixCount[i])));
    		curr -= max(1ll,min(n,curr-prefixCount[i]));
    	}
    }

    cout<<"Possible"<<endl;

    // cerr<<pos.size()<<" "<<ans.size()<<endl;
    cout<<ans[0]<<" ";
    // cerr<<s<<endl;
    for(int i=1;i<ans.size();i++){
    	if(pos[i]){
    		cout<<"+ ";
    	}
    	else{
    		cout<<"- ";
    	}
    	cout<<ans[i]<<" ";
    }
    cout<<"= "<<n<<endl;

}