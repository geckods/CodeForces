#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll arr[n][2];
    for(int i=0;i<n;i++){
    	cin>>arr[i][0]>>arr[i][1];
    	arr[i][0]--;
    }

    vector< vector<ll> > myVec(m);
    vector< vector<ll> > cumulVec(m);

    for(int i=0;i<m;i++){
    	myVec[i]=vector<ll>();
    	cumulVec[i]=vector<ll>();
    }


    for(int i=0;i<n;i++){
    	myVec[arr[i][0]].push_back(arr[i][1]);
    }

    for(int i=0;i<m;i++){
    	sort(myVec[i].rbegin(),myVec[i].rend());
    }
//    cout<<"HI"<<endl;

    for(int i=0;i<m;i++){
    	ll sum=0;
    	for(int j=0;j<myVec[i].size();j++){
    		sum+=myVec[i][j];
    		cumulVec[i].push_back(sum);
    	}
    }

    // for(int i=0;i<cumulVec.size();i++){
    // 	for(int j=0;j<cumulVec[i].size();j++){
    // 		cout<<cumulVec[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }


    set<ll> toAdd;
    for(int i=0;i<m;i++){
    	if(myVec[i].size()>0) toAdd.insert(i);
    }

    ll ans=0;

    int currSize=0;

//    cout<<toAdd.size()<<endl;
    while(!toAdd.empty()){
    	ll minians=0;
    	set<ll> toRemove;
    	for(set<ll>::iterator j = toAdd.begin();j!=toAdd.end();j++){
    		minians+=max(cumulVec[*j][currSize],(ll)0);
    		if(cumulVec[*j].size()==currSize+1){
    			toRemove.insert(*j);
    		}
    	}

    	for(set<ll>::iterator j = toRemove.begin();j!=toRemove.end();j++){
    		toAdd.erase(*j);
    	}

    	if(minians>ans) ans=minians;
    	currSize++;
    }

    cout<<ans<<endl;
}
