#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pdd pair<ll,ll>
#define line pair<pair<ll,ll>,pair<ll,ll>>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // template <class T1, class T2> 
    size_t operator()(const pair<ll, ll> p) const
    { 
        // auto hash1 = hash<T1>{}(p.first); 
        // auto hash2 = hash<T2>{}(p.second); 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(p.first + FIXED_RANDOM) ^ splitmix64(p.second + FIXED_RANDOM); 
    } 

};

ll gcd(ll a, ll b) 
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

line lineFromPoints(pdd P, pdd Q) 
{ 
    ll a = Q.second - P.second; 
    ll b = P.first - Q.first; 
    ll c = a*(P.first) + b*(P.second);

    if(b==0){

        ll asdgcd=gcd(c,a);

        return {{LLONG_MAX,LLONG_MAX},{c/asdgcd,a/asdgcd}};
    }

    ll slopen=-a;
    ll sloped=b;
    ll interceptn=c;
    ll interceptd=b;

    ll slopegcd = gcd(slopen,sloped);
    ll interceptgcd = gcd(interceptn,interceptd);

    slopen/=slopegcd;
    sloped/=slopegcd;

    interceptn/=interceptgcd;
    interceptd/=interceptgcd;

    return {{slopen,sloped},{interceptn,interceptd}};
} 

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    //for each pair of points, compute slope and intercept. store in set, count set

    unordered_map<pair<ll,ll>,unordered_set<pair<ll,ll>,custom_hash >,custom_hash > mainMap;

    ll arr[n][2];
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    //compute the line between each pair of points, store in a map with key=slope
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            line myLine = lineFromPoints(make_pair(arr[i][0],arr[i][1]), make_pair(arr[j][0],arr[j][1]));
            mainMap[myLine.first].insert(myLine.second);
        }
    }

    //put number of lines with each slope in a vector 
    vector<ll> myVec;
    for(auto asd = mainMap.begin();asd!=mainMap.end();asd++){
        myVec.push_back((asd->second).size());
    }

    //answer = pairwise product of number of lines with each slope
    ll curr=0;
    ll ans=0;
    for(int i=0;i<myVec.size();i++){
        ans+=curr*myVec[i];
        curr+=myVec[i];
        // cout<<myVec[i]<<" ";
    //     for(int j=i+1;j<myVec.size();j++){
    //         ans+=myVec[i]*myVec[j];
    //     }
    }

    cout<<ans<<endl;

}