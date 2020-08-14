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

string operate(string x, ll i){
	// cerr<<x<<" "<<i<<endl;
	reverse(x.begin(),x.begin()+i);
	string ret = x;
	for(int j=0;j<=i;j++){
		if(ret[j]=='0')ret[j]='1';
		else ret[j]='0';
	}
	// cerr<<ret<<endl;
	return ret;
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
    	string a;
    	cin>>a;
    	string b;
    	cin>>b;

    	vector<ll> ans;

    	ll j=n-1;
    	while(j>=0){

    		// cerr<<a<<" "<<b<<" "<<j<<endl;
    		// cerr<<a<<" "<<b<<" "<<j<<endl;
    		if(a[j]==b[j]){
    			j--;
    		}
    		else if(a[0]!=b[j]){
    			ans.push_back(j);
    			a = operate(a,j);
    			j--;
    			// cerr<<"HI"<<endl;
    		}
    		else{
    			ans.push_back(0);
    			// cerr<<a<<" "<<j<<endl;
    			a = operate(a,0);
    			// cerr<<a<<" "<<j<<endl;
    			ans.push_back(j);
    			a = operate(a,j);
    			j--;
    			// cerr<<"HI2"<<endl;
    		}
    		// cerr<<a<<" "<<b<<" "<<j<<endl;


    		// bool done=false;
    		// for(int i=1;i<j;i++){
    		// 	if(a[i]==b[j]){
	    	// 		ans.push_back(i);
	    	// 		a = operate(a,i);
	    	// 		ans.push_back(j);
	    	// 		a = operate(a,j);
	    	// 		done=true;
	    	// 		break;
    		// 	}
    		// }

    		// if(done){
    		// 	j--;
    		// 	continue;
    		// }

    		// ans.push_back(j);
    		// a = operate(a,j);
    	}

    	cout<<ans.size()<<" ";
    	for(int i=0;i<ans.size();i++){
    		cout<<ans[i]+1<<" ";
    	}
    	cout<<endl;
    }
}
