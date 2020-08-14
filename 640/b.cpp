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

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n<k){
            cout<<"NO"<<endl;
            continue;
        }

        if(n%2==0){
            if(k%2==1){
                if(n<2*k){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                    for(int i=0;i<k-1;i++){
                        cout<<2<<" ";
                    }
                    cout<<n-2*(k-1)<<" ";
                    cout<<endl;
                }
                // must use even numbers
            }
            else{
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++){
                    cout<<1<<" ";
                }
                cout<<n-(k-1)<<" ";
                cout<<endl;                
                // can use even or odd numbers
            }
        }
        else{
            if(k%2==1){
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++){
                    cout<<1<<" ";
                }
                cout<<n-(k-1)<<" ";
                cout<<endl;
                // must use odd numbers
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }
}