#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;
//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
#define MAXK 200000
ll counta[MAXK];

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

    memset(counta,0,sizeof(counta));
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	x--;
    	counta[x]++;
    }

    ll maxlim[k];
    for(int i=0;i<k;i++){
    	cin>>maxlim[i];
    }

    vector<intpair> myVec;
    // vector<vector<int> > myVec;
    // vector<vector<int> > myVec2;
    vector<ll> currGreater;

    ll maxVecPointer=0;

    priority_queue<intpair, vector<intpair>, greater<intpair>> mySet;

    
    ll currMaxVec=0;

    for(int i=k-1;i>=0;i--){
    	ll leftCurr=counta[i];
    	// auto it=mySet.begin();
    	// ll curr
	    ll vecPointer=0;

    	// if(i%1000==0)cerr<<i<<endl;

    	while(leftCurr>0){
    		// cerr<<i<<" "<<leftCurr<<endl;
    		if(vecPointer>=currMaxVec){
    			// myVec.push_back(vector<int>());
    			// myVec2.push_back(vector<int>());
    			// currGreater.push_back(0);
    			mySet.push({0,currMaxVec});
    			currMaxVec++;
    			// it=mySet.begin();
    		}
			auto it=mySet.top();

			// if(i==7){
			// cerr<<i<<" "<<maxlim[i]<<" "<<it->first<<" "<<it->second<<endl;
			// }

			ll temp=it.first;
			ll temp2=it.second;
			// cerr<<i<<" "<<leftCurr<<endl;
			// cerr<<temp<<" "<<temp2<<endl;
			if(leftCurr>maxlim[i]-temp){
				leftCurr-=maxlim[i]-temp;
				for(int j=0;j<maxlim[i]-temp;j++){
					// myVec[vecPointer].push_back(i+1);
					myVec.push_back({temp2,i+1});
				}
	    		// cerr<<i<<endl;
				// myVec[vecPointer].push_back(i+1);
				// myVec2[vecPointer].push_back(maxlim[i]-currGreater[vecPointer]);

				// mySet.erase(mySet.begin());
				mySet.pop();
				if(maxlim[i]<maxlim[0])
					mySet.push({maxlim[i],temp2});

				// currGreater[vecPointer]=maxlim[i];
				vecPointer++;
				// cerr<<vecPointer<<" "<<myVec.size()<<endl;
				// it++;
			}
			else{
				// myVec[vecPointer].push_back(i+1);
				// myVec2[vecPointer].push_back(leftCurr);
				// myVec[vecPointer].push_back({i+1,leftCurr});
				for(int j=0;j<leftCurr;j++){
					// myVec[vecPointer].push_back(i+1);
					myVec.push_back({temp2,i+1});
				}
				// ll temp=it->first;
				// mySet.erase(it);
				// mySet.erase(mySet.begin());
				mySet.pop();
				if(temp+leftCurr<maxlim[0])
					mySet.push({temp+leftCurr,temp2});
				else{
					currMaxVec++;
				}

				// currGreater[vecPointer]+=leftCurr;				
				leftCurr=0;
			}
			maxVecPointer=max(maxVecPointer,vecPointer);
    	// cerr<<leftCurr<<" "<<maxlim[i]-currGreater[vecPointer]<<endl;
    	}
    }

    // cerr<<myVec.size()<<"\n";
    // cerr<<currGreater.size()<<"\n";

    // for(int i=0;i<myVec.size();i++){
    // 	ll thesize=0;
    // 	for(int j=0;j<myVec[i].size();j++){
    // 		thesize+=myVec2[i][j];
    // 		// cout<<myVec[i][j]<<" ";
    // 	}
    // 	cout<<thesize<<" ";
    // 	for(int j=0;j<myVec[i].size();j++){
    // 		for(int k=0;k<myVec2[i][j];k++){
	   //  		cout<<myVec[i][j]<<" ";
    // 		}
    // 		// thesize+=myVec[i][j].second;
    // 	}

    // 	cout<<'\n';
    // }

    cout<<maxVecPointer+1<<"\n";
    sort(myVec.begin(),myVec.end());
    int i=0;
    while(i<n){
    	int j=i+1;
    	while(j<n && myVec[j].first==myVec[i].first)j++;
    	j--;
    	cout<<j-i+1<<" ";
    	for(int k=i;k<=j;k++){
    		cout<<myVec[k].second<<" ";
    	}
    	cout<<"\n";
    	i=j+1;
    }
}
