#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m;
    cin>>n>>m;
    int countarr[n];
    vector<vector<int> > mainarr;

    for(int i=0;i<n;i++){
    	//mainarr[i]=(int*)malloc(sizeof(int));
    	vector<int> vec;
    	mainarr.push_back(vec);
    	countarr[i]=0;
    }

    int a,b;
    for(int i=0;i<m;i++){
    	cin>>a>>b;
    	a--;
    	b--;
    	mainarr[a].push_back(b);
    	countarr[a]++;
    	mainarr[b].push_back(a);
    	countarr[b]++;
    }


    int maxk=-1;
    int maxlen=0;

    for(int i=0;i<n;i++){
    	if(countarr[i]>maxlen){
    		maxlen=countarr[i];
    		maxk=i;
    	}
    }

    set<int> seenSet;
    queue<int> nextQueue;

    seenSet.insert(maxk);
    nextQueue.push(maxk);

    int nextval;
    int possnext;

    while(seenSet.size()<n && nextQueue.size()>0){
    	nextval=nextQueue.front();
    	nextQueue.pop();
    	for(int i=0;i<countarr[nextval];i++){
    		possnext=mainarr[nextval][i];
    		if(seenSet.find(possnext)!=seenSet.end()) continue;
    		cout<<nextval+1<<" "<<possnext+1<<endl;
    		seenSet.insert(possnext);
    		nextQueue.push(possnext);
    	}
    }
}
