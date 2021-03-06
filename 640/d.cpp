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
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll ap=0;
        ll bp=n-1;

        ll prevScore=0;
        bool apTurn=true;

        ll ac=0;
        ll bc=0;
        ll turn=0;

        while(ap<=bp){
            turn++;
            if(apTurn){
                int j=ap;
                ll sum=0;
                while(j<=bp && sum<=prevScore){
                    sum+=arr[j++];
                }
                ac+=sum;
                prevScore=sum;
                ap=j;
                apTurn=false;
            }
            else{
                int j=bp;
                ll sum=0;
                while(j>=ap && sum<=prevScore){
                    sum+=arr[j--];
                }
                bc+=sum;
                prevScore=sum;
                bp=j;
                apTurn=true;
            }
        }
        cout<<turn<<" "<<ac<<" "<<bc<<endl;
    }
}