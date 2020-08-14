#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

bool works(ll req, ll currNum, ll toSplit){
    return req>=2*(currNum+toSplit);
}

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

        vector<ll> myVec;
        ll currWeight=1;
        ll currNum=1;
        ll req;
        while(1){
            req=n-currWeight;
            // cerr<<req<<endl;
            if(req <= 2*currNum){
                myVec.push_back(req-currNum);
                break;
            }
            else{
                ll bmin=0;
                ll bmax=currNum;
                ll bmid;
                while(bmin<bmax){
                    bmid=ceil(((double)(bmax+bmin))/2);
                    // cerr<<bmin<<" "<<bmax<<" "<<bmid<<endl;
                    // cerr<<req<<" "<<currNum<<" "<<bmid<<" "<<works(req,currNum,bmid)<<endl;
                    if(works(req,currNum,bmid)){
                        // cerr<<"HI"<<endl;
                        bmin=bmid;
                    }
                    else{
                        bmax=bmid-1;
                    }
                    // cerr<<bmin<<" "<<bmax<<" "<<bmid<<endl;
                }
                currNum+=bmin;
                myVec.push_back(bmin);
            }
            currWeight+=currNum;
            // req-=currNum;
        }
        cout<<myVec.size()<<endl;
        for(int i=0;i<myVec.size();i++){
            cout<<myVec[i]<<" ";
        }
        cout<<endl;
    }
}