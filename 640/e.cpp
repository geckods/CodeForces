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

#define MAXN 8000
int arr[MAXN];
int pref[MAXN];
bool seen[2*MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=arr[i]+pref[i-1];
        }
        for(int i=0;i<2*n;i++)
            seen[i]=false;

        int ans=0;
        for(int i=0;i<n;i++){
            int bef=0;
            if(i>0)bef=pref[i-1];
            for(int j=i+1;j<n;j++){
                if(pref[j]-bef<=n)
                    seen[pref[j]-bef]=true;
            }
        }

        for(int i=0;i<n;i++){
            if(seen[arr[i]])ans++;
        }
        cout<<ans<<endl;

    }
}