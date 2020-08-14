#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

typedef pair<ll,ll> intpair;

clock_t startTime;

map<set<ll>,bool> theMap;
#define MAXN 10001

vector<intpair> adj[MAXN];

ll weirdDjikstra(ll start, ll finish, ll g,ll r){
    ll currGMult=g;

    ll ansAccum=0;


    set<intpair> theStop;

    set<intpair> myPQ;

    myPQ.insert({0,start});

    int k=0;

    bool seen[finish+1];
    int seenC=0;

    while(1){
        while(!myPQ.empty()){
            intpair curr=*myPQ.begin();
            myPQ.erase(myPQ.begin());

            // cerr<<currGMult<<" "<<curr.first<<" "<<curr.second<<endl;

            for(auto y:adj[curr.second]){
                if(curr.first+y.first>currGMult){
                    continue;
                }
                else{
                    if(!seen[y.second]){
                        seen[y.second]=true;
                    }
                    if(y.second==finish)return curr.first+y.first+ansAccum;
                    if (curr.first+y.first<currGMult){
                        myPQ.insert({curr.first+y.first,y.second});
                    }
                    else{
                        theStop.insert({curr.first+y.first,y.second});
                    }
                }
            }
        }

        if(theStop.empty())return -1;

        // set<ll> newSet;
        // for(auto a:theStop){
        //     newSet.insert(a.second);
        // }

        // if(theMap[newSet])return -1;
        // theMap[newSet]=true;

            // cerr<<clock()-startTime<<endl;
        // if(clock()-startTime>980){
        //     return -1;
        // }

        myPQ=theStop;
        theStop.clear();
        currGMult+=g;
        ansAccum+=r;
        // k++;
        // cerr<<currGMult<<endl;
    }

}


int main(){
	
    startTime=clock();

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    vector<ll> myVec;
    ll x;
    for(int i=0;i<m;i++){
        cin>>x;
        myVec.push_back(x);
    }

    sort(myVec.begin(),myVec.end());
    set<ll> dists;

    ll g,r;
    cin>>g>>r;

    for(int i=0;i<m-1;i++){
        auto it=upper_bound(myVec.begin(),myVec.end(),(myVec[i]+g));
        int temp=it-myVec.begin();
        temp--;
        while(temp>i){
            adj[i].push_back({myVec[temp]-myVec[i],temp});
            adj[temp].push_back({myVec[temp]-myVec[i],i});
            temp--;
        }
    }

    cout<<weirdDjikstra(0,m-1,g,r)<<endl;



}