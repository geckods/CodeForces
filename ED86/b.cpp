#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

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
        string ts;
        cin>>ts;
        int zc=0;
        int oc=0;
        for(int i=0;i<ts.length();i++){
            if(ts[i]=='0')zc++;
            else oc++;
        }
        if(zc==0||oc==0){
            cout<<ts<<endl;
        }
        else{
            for(int i=0;i<ts.length();i++){
                cout<<"01";
            }
            cout<<endl;
        }
    }

}
