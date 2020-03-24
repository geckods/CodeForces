#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//=

typedef pair<ll,ll> intpair;

#define MAXN 200001

int parent[MAXN];
int drank[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    drank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (drank[a] < drank[b])
            swap(a, b);
        parent[b] = a;
        if (drank[a] == drank[b])
            drank[a]++;
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

    int n;
    cin>>n;

    ll arr[n][2];
    for(int i=0;i<n;i++){
    	cin>>arr[i][0]>>arr[i][1];
    }

    vector<pair<ll,intpair> > myVec;

    ll thedist[n][n];

    for(int i=0;i<n;i++){
    	thedist[i][i]=0;
    	for(int j=i+1;j<n;j++){
    		ll dist = pow(arr[i][0]-arr[j][0],2) + pow(arr[i][1]-arr[j][1],2);
    		thedist[j][i]=thedist[i][j]=dist;
    		myVec.push_back({dist,{i,j}});
    	}
    }

    // sort(myVec.begin(),myVec.end());

    //if there's a cycle of odd length > 1 then they must all be same set

    map<ll,ll> myMap;

    int theblue=-1;

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(i==j)continue;
    		myMap[thedist[i][j]]++;
    	}
    }

    for(int i=0;i<n;i++){
    	bool works=true;
    	for(int j=0;j<n;j++){
    		if(i==j)continue;
    		// cout<<i<<" "<<j<<" "<<thedist[i][j]<<endl;
    		myMap[thedist[i][j]]--;
    		myMap[thedist[i][j]]--;
    	}

    	for(int j=0;j<n;j++){
    		if(i==j)continue;
    		if(myMap[thedist[i][j]]>0){
    			works=false;
    			break;
    		}
    	}

    	for(int j=0;j<n;j++){
    		if(i==j)continue;
    		myMap[thedist[i][j]]++;
    		myMap[thedist[i][j]]++;
    	}


    	if(works){
    		theblue=i+1;
    		break;
    	}
    }

    cout<<1<<endl<<theblue<<endl;


}