#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

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
        ll arr[n];
        bool hask=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==k)hask=true;
        }

        if(!hask){
            cout<<"no"<<endl;
            continue;
        }

        if(n==1){
            cout<<"yes"<<endl;
            continue;
        }

        ll prefix[n];
        ll prefix2[n];
        if(arr[0]<k){
            prefix[0]=-1;
        }
        else if (arr[0]>k){
            prefix[0]=1;
        }
        else{
            prefix[0]=0;
        }

        if(arr[n-1]<k){
            prefix2[n-1]=-1;
        }
        else if (arr[n-1]>k){
            prefix2[n-1]=1;
        }
        else{
            prefix2[n-1]=0;
        }


        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1];

            if(arr[i]<k){
                prefix[i]--;
            }
            else if (arr[i]>k){
                prefix[i]++;
            }
            // cerr<<i<<" "<<prefix[i]<<endl;
        }

        for(int i=n-2;i>=0;i--){
            prefix2[i]=prefix2[i+1];

            if(arr[i]<k){
                prefix2[i]--;
            }
            else if (arr[i]>k){
                prefix2[i]++;
            }
            // cerr<<i<<" "<<prefix[i]<<endl;
        }



        map<ll,ll> seenMap;
        for(int i=0;i<n;i++){
            seenMap[prefix[i]]=-1;
        }
        seenMap[0]=-2;

        bool works=false;

        for(int i=0;i<n-1;i++){
            if(arr[i+1]==k){
                if(seenMap[prefix[i]]!=-1 || arr[i]>k){
                    works=true;
                    break;
                }
            }
            seenMap[prefix[i]]=i;
        }

        for(int i=0;i<n-2;i++){
            if(arr[i]==k&&arr[i+2]==k){
                works=true;
            }
        }

        if(works){
            cout<<"yes"<<endl;
            // cerr<<"HI"<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            seenMap[prefix2[i]]=-1;
        }
        seenMap[0]=-2;

        for(int i=n-1;i>=1;i--){
            if(arr[i-1]==k){
                // cerr<<prefix2[i]<<endl;
                if(seenMap[prefix2[i]]!=-1|| arr[i]>k){
                    // cerr<<i<<endl;
                    works=true;
                    break;
                }
            }
            seenMap[prefix2[i]]=i;
        }

        // cerr<<"HI"<<endl;
        if(works){
            cout<<"yes"<<endl;
            continue;
        }
        cout<<"no"<<endl;

    }
}