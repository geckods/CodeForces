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

    //=
    ll n;
    cin>>n;
    vector<intpair> edgeList;
    
    ll x,y;
    ll adjcount[n];
    memset(adjcount,0,sizeof(adjcount));

    ll maxdegreenode=-1;
    ll maxdegreecount=0;
    for(int i=0;i<n-1;i++){
        //take any vertex with adjlist size > 3, assign 0,1,and 2 to all it's edges
        //if no such vertex exists, it is a line - assign randomly
        cin>>x>>y;
        x--;
        y--;
        adjcount[x]++;
        adjcount[y]++;
        edgeList.push_back({x,y});

        if(adjcount[x]>maxdegreecount){
            maxdegreecount=adjcount[x];
            maxdegreenode=x;
        }

        if(adjcount[y]>maxdegreecount){
            maxdegreecount=adjcount[y];
            maxdegreenode=y;
        }
    }

    set<ll> mySet;
    for(int i=0;i<n-1;i++)mySet.insert(i);
    if(maxdegreecount==1){
        cout<<0<<endl;
        return 0;
    }

    if(maxdegreecount==2){
        while(!mySet.empty()){
            cout<<*mySet.begin()<<endl;
            mySet.erase(mySet.begin());
        }
        return 0;
    }

    ll assignment[n-1];
    memset(assignment,-1,sizeof(assignment));
    for(int i=0;i<n-1;i++){
        if(edgeList[i].first==maxdegreenode||edgeList[i].second==maxdegreenode){
            assignment[i]=*mySet.begin();
            mySet.erase(*mySet.begin());
        }
    }

    for(int i=0;i<n-1;i++){
        if(assignment[i]==-1){
            assignment[i]=*mySet.begin();
            mySet.erase(*mySet.begin());            
        }
    }

    for(int i=0;i<n-1;i++){
        cout<<assignment[i]<<endl;
    }

}
