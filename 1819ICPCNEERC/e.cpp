#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;


struct FenwickTree {
    int n;
    vector<ll> t;
 
    FenwickTree(int nn) {
        n = nn;
        t.resize(n + 1);
    }
 
    void inc(int pos, ll delta) {
        pos++;
        while (pos <= n) {
            t[pos] += delta;
            pos += pos & -pos;
        }
    }
 
    ll sum(int r) {
        r++;
        ll res = 0;
        while (r > 0) {
            res += t[r];
            r -= r & -r;
        }
        return res;
    }
 
    int firstIndexOfGE(ll val) {
        int step = (1 << 19);
        int i = 0;
        ll now = 0;
        while (step > 0) {
            if (i + step <= n && now + t[i + step] < val) {
                now += t[i + step];
                i += step;
            }
            step /= 2;
        }
        return i; // 1-indexed fenwick
    }
 
    void debug() {
        for (int i = 0; i < n; i++) {
            cerr << sum(i) - sum(i - 1) << ' ';
        }
        cerr << endl;
    }
};
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

    ll c;
    cin>>c;
    while(c--){
        ll n,m,t;
        cin>>n>>m>>t;
        vector<intpair> myVec;

        // ll maxTime=0;

        ll x;
        for(int i=0;i<n;i++){
            cin>>x;
            // maxTime=max(maxTime,x);
            myVec.push_back({x,i});
        }
        sort(myVec.begin(),myVec.end());
        ll maxTime=myVec[myVec.size()-1].first;

        int currPointer=0;

        ll maxTasks=-1;
        ll maxD=-1;

        ll tbt=t/2;

        FenwickTree myft = FenwickTree(n);
        FenwickTree myftc = FenwickTree(n);

        ll totsum=0;



        // for(int d=1;d<=maxTime;d++){
        while(currPointer<n){
            ll j=currPointer+1;
            ll d=myVec[currPointer].first;

            while(j<n&&myVec[j].first==myVec[currPointer].first)j++;

            // cerr<<currPointer<<" "<<j<<endl;

            for(int k=currPointer;k<j;k++){
                myft.inc(myVec[k].second,d);
                myftc.inc(myVec[k].second,1);
                totsum++;
            }
            // while(currPointer<n && myVec[currPointer].first==d){
            // }
            // binary search for the multiple of m which has a prefix just less than t/2

            // ll totsum=myftc.sum(n-1);

            ll bmin=0;
            ll bmax=totsum/m;
            ll bmid;
            ll bmidm;

            while(bmin<bmax){
                // bmid=ceil((((double)bmin)+bmax)/2);
                bmid=(bmin+bmax)/2;
                if((bmax-bmin)&1  && bmin!=-1)bmid++;
                bmidm=bmid*m;


                ll bbmin=0;
                // ll bbmax=n-1;
                // ll bbmid;
                // while(bbmin<bbmax){
                //     bbmid=(bbmin+bbmax)/2;
                //     if(myftc.sum(bbmid)<bmidm){
                //         bbmin=bbmid+1;
                //     }
                //     else if (myftc.sum(bbmid)==bmidm){
                //         bbmax=bbmid;
                //     }
                //     else{
                //         bbmax=bbmid-1;
                //     }
                // }

                bbmin=myftc.firstIndexOfGE(bmidm);
                // cerr<<d<<" "<<bmin<<" "<<bmax<<" "<<bmid<<" "<<bbmin<<" "<<bmidm<<endl;

                if(myft.sum(bbmin)>tbt){
                    bmax=bmid-1;
                }
                else{
                    bmin=bmid;
                }
            }

            // cerr<<d<<" "<<bmin<<" "<<bmax<<endl;
            ll keepers=bmin;

            ll thatInd=-1;
            if(bmin==0){

            }
            else{
                // ll bbmin=0;
                // ll bbmax=n-1;
                // ll bbmid;
                // while(bbmin<bbmax){
                //     bbmid=(bbmin+bbmax)/2;
                //     if(myftc.sum(bbmid)<bmin*m){
                //         bbmin=bbmid+1;
                //     }
                //     else if (myftc.sum(bbmid)==bmin*m){
                //         bbmax=bbmid;
                //     }
                //     else{
                //         bbmax=bbmid-1;
                //     }
                // }
                thatInd=myftc.firstIndexOfGE(bmin*m);
            }

            // bmin is the highest index which has a multiple of m elements and has time <= tbt
            bmin=thatInd;
            ll toRem=0;
            ll mkeep=keepers*m;
            bmax=min((ll)myftc.firstIndexOfGE(mkeep+m),n-1);

            ll thatIndSum=myft.sum(thatInd);

            ll bms;
            // if(thatInd>=0)toRem=thatIndSum*2;
            // cerr<<d<<" "<<bmin<<" "<<bmax<<" "<<toRem<<" "<<thatInd<<" "<<keepers<<endl;

            while(bmin<bmax){

                bmid=(bmin+bmax)/2;
                if(((bmax-bmin)&1) && bmin!=-1)bmid++;
                // cerr<<d<<" "<<bmin<<" "<<bmax<<" "<<bmid<<" "<<bbmin<<" "<<bmidm<<endl;
                // bms=myft.sum(bmid);
                // cerr<<d<<" "<<bmin<<" "<<bmax<<" "<<bmid<<endl;
                // if(myftc.sum(bmid)-mkeep>m){
                //     bmax=bmid-1;
                //     continue;
                // }
                // ll currVal=toRem;
                ll currVal=myft.sum(bmid)+thatIndSum;
                if(currVal<=t){
                    bmin=bmid;
                }
                else{
                    bmax=bmid-1;
                }
            }


            ll bestTasks = myftc.sum(bmin);
            // cerr<<d<<" "<<bestTasks<<" "<<bmin<<endl;
            if(bestTasks>maxTasks){
                maxTasks=bestTasks;
                maxD=d;
            }
            currPointer=j;
            // currPointer++;
        }
        // }
        cout<<maxTasks<<" "<<min(maxD,t)<<"\n";

    }

}