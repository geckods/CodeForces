#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200001
typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int count[MAX] = {0};
    int x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	count[x]++;
    }


    int bmin=0;
    int bmax=n;
    int prevmid=-1;
    int bmid=0;
	while(prevmid!=bmid){
		prevmid=bmid;
		bmid=(bmin+bmax)/2;
		// cerr<<bmin<<" "<<bmax<<" "<<bmid<<endl;
	    priority_queue<intpair> myPQ;
	    for(int i=1;i<MAX;i++){
	    	myPQ.push(make_pair(count[i],i));
	    }

	    bool done=false;
	    for(int i=0;i<k;i++){
	    	intpair thispair=myPQ.top();
	    	// cerr<<thispair.first<<" "<<thispair.second<<endl;
	    	myPQ.pop();
	    	if(thispair.first<bmid){
	    		bmax=bmid-1;
	    		done=true;
	    		break;
	    	}
	    	myPQ.push(make_pair(thispair.first-bmid,thispair.second));
	    }

	    if(done) continue;
	    bmin=bmid;
	}

	int anst = bmax;
	// cout<<anst<<endl;

    priority_queue<intpair> myPQ;
    for(int i=1;i<MAX;i++){
    	myPQ.push(make_pair(count[i],i));
    }

    bool done=false;
    for(int i=0;i<k;i++){
    	intpair thispair=myPQ.top();
    	myPQ.pop();
    	if(thispair.first<anst){
    		done=true;
    		break;
    	}
    	myPQ.push(make_pair(thispair.first-anst,thispair.second));
    }

    if(done){
    	anst--;
    }

    // cout<<anst<<endl;
	// myPQ.empty();    

    priority_queue<intpair> newPQ;
    for(int i=1;i<MAX;i++){
    	newPQ.push(make_pair(count[i],i));
    	// cout<<i<<" "<<count[i]<<endl;
    }

    // cout<<count[173502]<<endl;

    vector<int> sol;

    for(int i=0;i<k;i++){
    	intpair thispair=newPQ.top();
    	newPQ.pop();
    	// cout<<thispair.second<<endl;
    	sol.push_back(thispair.second);
    	newPQ.push(make_pair(thispair.first-anst,thispair.second));
    }
    sort(sol.begin(),sol.end());

    for(int i=0;i<sol.size();i++){
    	cout<<sol[i]<<" ";
    }
    cout<<endl;

}
