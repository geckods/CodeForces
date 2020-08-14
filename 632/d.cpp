#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    // hypothesis -> do moves, it will always converge

    vector<intpair> myVec;

    bool hasFace=true;

    ll iteration=1;

    unordered_set<ll> mySet;

    for(int i=0;i<n-1;i++){
        if(s[i]=='R' && s[i+1]=='L'){
            mySet.insert(i);
        }
    }

    // cerr<<mySet.size()<<endl;

    while(!mySet.empty()){
        // hasFace=false;
        // for(int i=0;i<n-1;i++){
        // int i=0;
        // while(i<n-1){
            // if(s[i]=='R' && s[i+1]=='L'){
                // cerr<<iteration<<endl;
        // cerr<<iteration<<" "<<mySet.size()<<endl;

        unordered_set<ll> newSet=mySet;

        for(auto it:newSet){
            myVec.push_back({iteration,it});
            mySet.erase(it);

            s[it]='L';
            s[it+1]='R';

            if(it>0 && s[it-1]=='R')mySet.insert(it-1);
            if(it<n-2 && s[it+2]=='L')mySet.insert(it+1);
            // hasFace=true;
        }
                // i++;
            // }
            // i++;
        // }
        // cerr<<s<<" "<<iteration<<endl;
        // if(hasFace)
        iteration++;
    }

    iteration--;

    // cerr<<iteration<<endl;
    if(k<iteration || k>myVec.size()){
        cout<<-1<<endl;
        return 0;
    }

    int i=0;
    int j=0;

    ll remain=k;

    while(i<myVec.size()){
        j=i;
        while(j<myVec.size() && myVec[j].first==myVec[i].first && myVec.size()-j>=remain){
            j++;
        }
        j--;

        // cerr<<i<<" "<<j<<endl;

        // make a move
        cout<<j-i+1<<" ";
        for(int k=i;k<=j;k++){
            cout<<myVec[k].second+1<<" ";
        }
        cout<<"\n";
        remain--;
        i=j+1;
    }
}
