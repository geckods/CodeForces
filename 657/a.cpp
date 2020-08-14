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

bool hasOneOccurance(string s){
	ll sc=0;
	ll n = s.length();
	for(int i=0;i<n-6;i++){
		if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='a' && s[i+3]=='c' && s[i+4]=='a' && s[i+5]=='b' && s[i+6]=='a'){
			sc++;
		}
	}
	return sc==1;
}


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
    	ll n;
    	cin>>n;
    	string s;
    	cin>>s;
    	ll sc = 0;
    	ll msc = 0;
    	vector<ll> mpos;

    	for(int i=0;i<n-6;i++){
    		if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='a' && s[i+3]=='c' && s[i+4]=='a' && s[i+5]=='b' && s[i+6]=='a'){
    			sc++;
    		}
    		if((s[i]=='a' || s[i]=='?') && (s[i+1]=='b' || s[i+1]=='?') && (s[i+2]=='a' || s[i+2]=='?') && (s[i+3]=='c' || s[i+3]=='?') && (s[i+4]=='a' || s[i+4]=='?') && (s[i+5]=='b' || s[i+5]=='?') && (s[i+6]=='a' || s[i+6]=='?')){
    			mpos.push_back(i);
    			msc++;
    		}
    	}



    	if(sc == 1){
    		cout<<"YES"<<endl;
    		for(int i=0;i<n;i++){
    			if(s[i]=='?'){
    				cout<<'z';
    			}
    			else{
    				cout<<s[i];
    			}
    		}
    		cout<<endl;
    	}
    	else if (sc>1){
    		cout<<"NO"<<endl;
    	}
    	else{
    		bool done=false;
    		for(auto it: mpos){
    			string news = s;
    			for(int i=0;i<n;i++){
    				if(news[i]=='?')news[i]='z';
    			}
    			news[it]='a';
    			news[it+1]='b';
    			news[it+2]='a';
    			news[it+3]='c';
    			news[it+4]='a';
    			news[it+5]='b';
    			news[it+6]='a';
    			if(hasOneOccurance(news)){
    				cout<<"YES"<<endl;
    				cout<<news<<endl;
    				done=true;
    				break;
    			}
    		}
    		if(!done){
    			cout<<"No"<<endl;
    		}
    	}
    }

}
