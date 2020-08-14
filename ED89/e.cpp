#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes


typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll part[m];
    for(int i=0;i<m;i++){
    	cin>>part[i];
    }


    // ll gtb[n];
    // ll gta[n];

    // stack<intpair> myStack;
    // for(int i=0;i<n;i++){
    // 	while(!myStack.empty() && myStack.top().first>=arr[i]){
    // 		myStack.pop();
    // 	}
    // 	if(myStack.empty()){
    // 		gtb[i]=-1;
    // 	}
    // 	else{
    // 		gtb[i]=myStack.top().second;
    // 	}
    // 	myStack.push({arr[i],i});
    // }

    // while(!myStack.empty())myStack.pop();

    // for(int i=n-1;i>=0;i--){
    // 	while(!myStack.empty() && myStack.top().first>=arr[i]){
    // 		myStack.pop();
    // 	}
    // 	if(myStack.empty()){
    // 		gta[i]=-1;
    // 	}
    // 	else{
    // 		gta[i]=myStack.top().second;
    // 	}
    // 	myStack.push({arr[i],i});
    // }

    // ll partp=0;
    // ll lastSec=-1;

    // for(int i=0;i<n;i++){
    // 	if(arr[i]!=part[partp]){
    // 		continue;
    // 	}
    // }

    reverse(arr,arr+n);
    reverse(part,part+m);

    ll partP=0;
    bool seenCurr = false;
    ll startPos=-1;

    ll ans=1;

    for(int i=0;i<n;i++){
    	if(!seenCurr){
    		if(arr[i]==part[partP]){
    			seenCurr=true;
    			startPos=i;
    		}
    		else if (arr[i]<part[partP]){
    			cout<<0<<endl;
    			return 0;
    		}
    	}
    	else {
    		if(arr[i]<part[partP]){
    			if(partP==m-1 || (partP<m-1 && arr[i]<part[partP+1])){
    				cout<<0<<endl;
    				return 0;
    			}
    			else{
	    			ans*=(i-startPos);
    				ans%=MOD;
    				if(partP<m-1 && arr[i]==part[partP+1]){
    					seenCurr=true;
    					startPos=i;
    				}
    				else{
    					seenCurr=false;
    					startPos=-1;
    				}
    				partP++;
    			}
    		}
    	}
    }

    if(partP<m-1 || (partP==m-1 && seenCurr==false)){
    	cout<<0<<endl;
    	return 0;
    }

    cout<<ans<<endl;

}