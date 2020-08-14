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

typedef pair<int,vector<int>> myPair;

vector<int> myAlgo(ll x){

    queue<myPair> myQ;

    myQ.push({x,vector<int>()});


    while(!myQ.empty()){
        myPair temp = myQ.front();
        myQ.pop();

        if(temp.first>47)continue;
        if(temp.first==47)return temp.second;

        temp.first*=2;
        temp.second.push_back(2);        
        myQ.push(temp);
        temp.first/=2;
        temp.second.pop_back();

        temp.first+=3;
        temp.second.push_back(3);        
        myQ.push(temp);
        temp.first-=3;
        temp.second.pop_back();

        temp.first+=1;
        temp.second.push_back(1);
        myQ.push(temp);
        temp.first-=1;
        temp.second.pop_back();
    }

}

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
        freopen("error", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sol = myAlgo(3);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<endl;
    }
}