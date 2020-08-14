#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

typedef pair<int,int> intpair;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes
vector<vector<int> > hasNeigbor(vector<vector<int> > board, int n, int m){
    vector<vector<int> > ans;
    for(int i=0;i<n;i++){
        ans.push_back(vector<int>());
        for(int j=0;j<m;j++){
            ans[i].push_back(INT_MAX);
        }
    }

    queue<intpair> myQ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i>0 && board[i][j]==board[i-1][j])|| (j>0 && board[i][j]==board[i][j-1])||(i<n-1 && board[i][j]==board[i+1][j])||(j<m-1 && board[i][j]==board[i][j+1])){
                ans[i][j]=0;
                myQ.push({i,j});
            }   
        }
    }

    while(!myQ.empty()){
        intpair temp=myQ.front();
        int i=temp.first;
        int j=temp.second;
        myQ.pop();

        if(i>0 && ans[i-1][j]==INT_MAX){
            ans[i-1][j]=ans[i][j]+1;
            myQ.push({i-1,j});
        }
        if(j>0 && ans[i][j-1]==INT_MAX){
            ans[i][j-1]=ans[i][j]+1;
            myQ.push({i,j-1});
        }
        if(i<n-1 && ans[i+1][j]==INT_MAX){
            ans[i+1][j]=ans[i][j]+1;
            myQ.push({i+1,j});
        }
        if(j<m-1 && ans[i][j+1]==INT_MAX){
            ans[i][j+1]=ans[i][j]+1;
            myQ.push({i,j+1});
        }
    }
    return ans;

}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,t;
    cin>>n>>m>>t;

    vector<vector<int> > grid;

    string s;
    for(int i=0;i<n;i++){
        grid.push_back(vector<int>());
        cin>>s;
        for(int j=0;j<m;j++){
            grid[i].push_back(s[j]-'0');
        }
    }


    vector<vector<int> > asdf=hasNeigbor(grid,n,m);

    for(int test=0;test<t;test++){
        ll i,j,p;
        cin>>i>>j>>p;
        i--;
        j--;
        if(asdf[i][j]==INT_MAX){
            cout<<grid[i][j]<<endl;
        }
        else{
            if((p-asdf[i][j])%2==1){
                cout<<1-grid[i][j]<<endl;
            }
            else{
                cout<<grid[i][j]<<endl;
            }
        }
    // cerr<<"HI"<<endl;
    }
    // connected components of size > 1 keep toggling




}