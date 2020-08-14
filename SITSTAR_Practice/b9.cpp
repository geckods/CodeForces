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

bool isLess(vector<ll> a, vector<ll> b, ll c){
    if(c==a.size())return false;
    if(a[c]<b[c])return true;
    if(a[c]>b[c])return false;
    return isLess(a,b,c+1);
}

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

    vector<ll> myArr;
    ll x;
    for(int i=0;i<n;i++){
        cin>>x;
        myArr.push_back(x);
    }

    vector<ll> myVec;
    bool inMaxMode=false;

    for(int i=0;i<n;i++){
        myVec.push_back(i);
    }

    vector<ll> ans;

    for(int i=0;i<n;i++){
        if(inMaxMode){
            ans.push_back(myVec[myVec.size()-1]);
            myVec.erase(myVec.begin()+myVec.size()-1);
        }
        else{
            int theInd = upper_bound(myVec.begin(),myVec.end(),myArr[i])-myVec.begin()-1;
            if(theInd==-1){
                theInd++;
            }
            if(myVec[theInd]<myArr[i]){
                inMaxMode=true;
            }
            ans.push_back(myVec[theInd]);
            myVec.erase(myVec.begin()+theInd);
        }
    }

    // for(int i=0;i<n;i++){
    //     cerr<<ans[i]<<" ";
    // }
    // cerr<<endl;

    while(!isLess(ans,myArr,0)){
        if(!prev_permutation(ans.begin(), ans.end())){
            cout<<-1<<endl;
            return 0;
        }        
    }
    // if(!inMaxMode){
    // }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}