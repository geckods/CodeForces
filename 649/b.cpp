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
#define endl '\n'
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

        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n==2){
            cout<<2<<endl;
            cout<<arr[0]<<" "<<arr[1]<<endl;
            continue;
        }

        vector<ll> ans1;
        ans1.push_back(arr[0]);
        ll sum1=0;
        bool goingUp = arr[1]>arr[0];
        for(int i=2;i<n;i++){
            // cerr<<i<<" "<<goingUp<<endl;
            if(goingUp){
                if(arr[i]<arr[i-1]){
                    sum1+=abs(*ans1.end()-arr[i-1]);
                    ans1.push_back(arr[i-1]);
                    goingUp=false;
                }
            }
            else {
                if(arr[i]>arr[i-1]){
                    sum1+=abs(*ans1.end()-arr[i-1]);
                    ans1.push_back(arr[i-1]);
                    goingUp=true;
                }                
            }
        }
        sum1+=abs(arr[n-1]-*ans1.end());
        ans1.push_back(arr[n-1]);

        // cout<<ans1.size()<<endl;

        vector<ll> ans=ans1;

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}