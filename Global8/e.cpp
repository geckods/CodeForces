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

typedef pair<ll,ll> intpair;

typedef pair<double,ll> dbpair;

void diffSet(ll x, double arr[], set<dbpair> &mySet, double diff){
    mySet.erase(mySet.find({arr[x],x}));
    arr[x]+=diff;
    mySet.insert({arr[x],x});
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
        ll n,m;
        cin>>n>>m;

        ll arr[n];
        memset(arr,0,sizeof(arr));

        vector<intpair> myVec;

        ll x,y;
        vector<ll> outwards[n];
        vector<ll> inwards[n];

        for(int i=0;i<m;i++){
            cin>>x>>y;
            x--;
            y--;
            outwards[x].push_back(y);
            inwards[y].push_back(x);

            myVec.push_back({x,y});
        }

        double scoreArr[n];
        for(int i=0;i<n;i++){
            scoreArr[i]=0;
        }

        for(int i=0;i<n;i++){
            if(outwards[i].size()>0 && inwards[i].size()>0){
                scoreArr[i]+=0.0;
                for(auto j:inwards[i]){
                    scoreArr[j]+=(1.0/inwards[i].size());
                }
                for(auto j:outwards[i]){
                    scoreArr[j]+=(1.0/outwards[i].size());
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     cerr<<i<<" "<<scoreArr[i]<<endl;
        // }


        set<dbpair> mySet;
        for(int i=0;i<n;i++){
            mySet.insert({scoreArr[i],i});
        }

        cout<<(4*n)/7<<endl;

        bool inSet[n];
        memset(inSet,true,sizeof(inSet));

        for(int i=0;i<(4*n)/7;i++){
            // cerr<<"HI"<<" "<<i<<endl;
            auto temp = prev(mySet.end());
            ll curr = (*temp).second;
            // cerr<<i<<" "<<(*temp).first<<" "<<(*temp).second<<endl;
            mySet.erase(temp);
            // cerr<<curr<<endl;
            inSet[curr]=false;
            cout<<curr+1<<" ";
            // 
            for(auto j:inwards[curr]){
                if(inSet[j]){
                    diffSet(j, scoreArr, mySet, -(1.0/inwards[curr].size()));

                    ll ogOutLen = outwards[j].size();
                    outwards[j].erase(find(outwards[j].begin(),outwards[j].end(),curr));

                    // if(outwards[j].size()==0){
                    //     diffSet(j, scoreArr, mySet, -1.0);
                    // }

                    for(auto k:outwards[j]){
                        if(inSet[k])
                            diffSet(k, scoreArr, mySet,(1.0/outwards[j].size())-(1.0/ogOutLen));
                    }
                }
            }

            for(auto j:outwards[curr]){
                if(inSet[j]){
                    diffSet(j, scoreArr, mySet, -(1.0/outwards[curr].size()));

                    ll ogInLen = inwards[j].size();
                    inwards[j].erase(find(inwards[j].begin(),inwards[j].end(),curr));

                    // if(inwards[j].size()==0){
                    //     diffSet(j, scoreArr, mySet, -1.0);
                    // }

                    for(auto k:inwards[j]){
                        if(inSet[k])
                            diffSet(k, scoreArr, mySet,(1.0/inwards[j].size())-(1.0/ogInLen));
                    }
                }
            }
        }
        cout<<endl;
    }
}

