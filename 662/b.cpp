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

#define MAXN 100001

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll occ[MAXN] = {0};
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	occ[x]++;
    }

    set<intpair> mySet;
    for(int i=1;i<MAXN;i++){
    	mySet.insert({occ[i],i});
    }

    ll q;
    cin>>q;
	char c;
	intpair temp;
    while(q--){
    	cin>>c>>x;
    	if(c=='+'){
    		temp = {occ[x],x};
    		mySet.erase(temp);
    		occ[x]++;
    		temp.first++;
    		mySet.insert(temp);
    	}
    	else{
    		temp = {occ[x],x};
    		mySet.erase(temp);
    		occ[x]--;
    		temp.first--;
    		mySet.insert(temp);
    	}

    	ll a,b,c;
    	auto temp = mySet.rbegin();
    	a = (*temp).first;
    	temp++;
    	b = (*temp).first;
    	temp++;
    	c = (*temp).first;


    	if(a>=4){
    		a-=4;
    		vector<ll> temp;
    		temp.push_back(a);
    		temp.push_back(b);
    		temp.push_back(c);
    		sort(temp.begin(),temp.end());
    		if((temp[1]>=2 && temp[2]>=2)||(temp[2]>=4)){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    	else{
    		cout<<"NO"<<endl;
    	}

    }
}