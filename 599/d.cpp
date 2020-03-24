#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //as you explore, keep a set of all places which you currently cannot visit

    int n,m;
    cin>>n>>m;

    map<int,unordered_set<int> > edgeMap;

    int x,y;
    for(int i=0;i<m;i++){
    	cin>>x>>y;
    	x--;
    	y--;

    	edgeMap[x].insert(y);
    	edgeMap[y].insert(x);
    }

    bool seen[n+1];
    int firstunseen=0;
    for(int i=0;i<=n;i++){
    	seen[i]=false;
    }

    while(firstunseen<n){

    	unordered_set<int> cantSee;
    	for(int i=0;i<n;i++){
    		if(!seen[i])cantSee.insert(i);
    	}


    	int curr=firstunseen;

    	while()
	    	vector<int> toDel;
	    	for(unordered_set<int>::iterator i = cantSee.begin();i!=cantSee.end();i++){
	    		if(edgeMap[curr].find(*i)==edgeMap[curr].end()){
	    			toDel.push_back(*i);
	    		}
	    	}

	    	for(int i=0;i<toDel.size();i++){
	    		cantSee.erase(cantSee.find(toDel[i]));
	    	}
	    	if(toDel.size()==0)break



    	while(seen[firstunseen])firstunseen++;
    }