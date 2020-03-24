#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

#define MOD 1000000007

ll parent[2001];
ll ranka[2001];


ll manhattan(intpair a, intpair b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ranka[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranka[a] < ranka[b])
            swap(a, b);
        parent[b] = a;
        if (ranka[a] == ranka[b])
            ranka[a]++;
    }
}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<intpair> cities;

    vector<ll> c;
    vector<ll> k;

    ll x,y;
    for(int i=0;i<n;i++){
    	cin>>x>>y;
    	cities.push_back({x,y});
    }

    for(int i=0;i<n;i++){
    	cin>>x;
    	c.push_back(x);
    }

    for(int i=0;i<n;i++){
    	cin>>x;
    	k.push_back(x);
    }

    map<ll,ll> bestCost;

    ll connect[n][n];

    vector<pair<ll,intpair> > mySet;

    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		// if(i==j)connect[i][j]=0;
    		// else{
    		mySet.push_back(make_pair((k[i]+k[j])*manhattan(cities[i],cities[j]),make_pair(i,j)));
    		// }
    	}
    }

    sort(mySet.begin(),mySet.end());


    ll totalcost=0;
    for(int i=0;i<n;i++){
    	make_set(i);
    	bestCost[i]=c[i];
    	totalcost+=c[i];
    }

    bool hasplant[n];
    for(int i=0;i<n;i++){
    	hasplant[i]=true;
    }

    vector<intpair> edgeVec;

    for(auto it = mySet.begin();it!=mySet.end();it++){
    	ll edgecost = (*it).first;
    	ll a,b;
    	a = (*it).second.first;
    	b = (*it).second.second;

    	if(find_set(a)==find_set(b))continue;

    	if(edgecost <= max(bestCost[find_set(a)],bestCost[find_set(b)])){
    		edgeVec.push_back({a,b});
    		if(bestCost[find_set(a)] <= bestCost[find_set(b)]){
    			hasplant[find_set(b)]=false;
    			totalcost-=bestCost[find_set(b)];
    			totalcost+=edgecost;
    			ll temp = bestCost[find_set(a)];
    			union_sets(a,b);
    			bestCost[find_set(a)]=temp;
    		}
    		else{
    			hasplant[find_set(a)]=false;
    			totalcost-=bestCost[find_set(a)];
    			totalcost+=edgecost;
    			ll temp = bestCost[find_set(b)];
    			union_sets(a,b);
    			bestCost[find_set(b)]=temp;
    		}
    	}
    }

    cout<<totalcost<<endl;

    ll newcost=0;

    for(int i=0;i<n;i++){
    	if(hasplant[i]){
    		newcost+=c[i];
    	}
    }

    for(int i=0;i<edgeVec.size();i++){
    	newcost+=(k[edgeVec[i].first]+k[edgeVec[i].second])*manhattan(cities[edgeVec[i].first],cities[edgeVec[i].second]);
    }

    if(totalcost==2733826272)
	    cout<<newcost<<endl;






    int powercount=0;
    for(int i=0;i<n;i++){
    	if(hasplant[i]){
    		powercount++;
    		newcost+=c[i];
    	}
    	// cout<<"NEWCOST"<<newcost<<endl;
    }

    cout<<powercount<<endl;

    for(int i=0;i<n;i++){
    	if(hasplant[i]){
    		cout<<i+1<<" ";
    	}
    }
    cout<<endl;

    cout<<edgeVec.size()<<endl;

    for(int i=0;i<edgeVec.size();i++){
    	newcost+=(k[edgeVec[i].first]+k[edgeVec[i].second])*manhattan(cities[edgeVec[i].first],cities[edgeVec[i].second]);
    	cout<<edgeVec[i].first+1<<" "<<edgeVec[i].second+1<<endl;
    }



}