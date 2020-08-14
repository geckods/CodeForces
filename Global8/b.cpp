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

    ll k;
    cin>>k;

    ll arr[10];
    for(int i=0;i<10;i++){
        arr[i]=1;
    }

    ll i=0;
    ll currWays=1;
    while(currWays<k){
        currWays/=(arr[i]);
        arr[i]++;
        currWays*=arr[i];
        i++;
        i%=10;
    }

    for(int i=0;i<arr[0];i++){
        cout<<'c';
    }
    for(int i=0;i<arr[1];i++){
        cout<<'o';
    }
    for(int i=0;i<arr[2];i++){
        cout<<'d';
    }
    for(int i=0;i<arr[3];i++){
        cout<<'e';
    }
    for(int i=0;i<arr[4];i++){
        cout<<'f';
    }
    for(int i=0;i<arr[5];i++){
        cout<<'o';
    }
    for(int i=0;i<arr[6];i++){
        cout<<'r';
    }
    for(int i=0;i<arr[7];i++){
        cout<<'c';
    }
    for(int i=0;i<arr[8];i++){
        cout<<'e';
    }
    for(int i=0;i<arr[9];i++){
        cout<<'s';
    }

    cout<<endl;
}
