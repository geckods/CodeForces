#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;
// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes
#define MAXN 5001
vector<ll> adj[MAXN];

int isEven[MAXN];
int component[MAXN];
bool seen[MAXN];

bool labelGraph(int x, int c){
	
	queue<intpair> myQ;
	myQ.push({x,0});

	ll tc,oc;

	while(!myQ.empty()){
		intpair curr=myQ.front();
		seen[curr.first]=true;
		component[curr.first]=c;
		myQ.pop();
		tc=curr.second&1;
		oc=tc^1;
		if(isEven[curr.first]==-1){
			isEven[curr.first]=tc;
		}
		else{
			if(isEven[curr.first]!=tc){
				return false;
			}
		}

		for(auto j: adj[curr.first]){
			if(isEven[j]!=-1 && isEven[j]!=oc){
				return false;
			}

			if(!seen[j]){
				seen[j]=true;
				isEven[j]=oc;
				myQ.push({j,curr.second+1});
			}
		}
	}
	return true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll n1,n2,n3;
    cin>>n1>>n2>>n3;

    bool toBe2[n];
    for(int i=0;i<n;i++){
    	isEven[i]=-1;
    	seen[i]=false;
    	toBe2[i]=false;
    }

    ll u,v;
    for(int i=0;i<m;i++){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    bool canLabelGraph=true;
    int compNo=0;
    for(int i=0;i<n;i++){
    	if(!seen[i]){
    		canLabelGraph&=labelGraph(i,compNo);
    		compNo++;
    	}
    }


    if(!canLabelGraph){
    	cout<<"NO"<<endl;
    }
    else{

    	ll inComp[compNo];
    	ll ec[compNo];

    	memset(inComp,0,sizeof(inComp));
    	memset(ec, 0, sizeof(ec));

    	for(int i=0;i<n;i++){
    		inComp[component[i]]++;
    		if(isEven[i]==0)ec[component[i]]++;
    	}

    	vector<intpair> myVec;
    	for(int i=0;i<compNo;i++){
    		myVec.push_back({ec[i],inComp[i]-ec[i]});
    	}

    	// cerr<<myVec.size()<<endl;

    	ll dp[compNo][n2+1];

    	for(int i=0;i<compNo;i++){
    		for(int j=0;j<n2+1;j++){
    			dp[i][j]=-1;
    		}
    	}

    	for(int i=0;i<compNo;i++){
    		for(int j=0;j<n2+1;j++){
    			if(i==0){
	    			if(myVec[i].first==j){
	    				dp[i][j]=0;
	    			}
	    			if (myVec[i].second==j){
	    				dp[i][j]=1;
	    			}    				
    			}
    			else{
    				if(j-myVec[i].first>=0 && dp[i-1][j-myVec[i].first]>=0){
    					dp[i][j]=0;
    				}

			    	// cerr<<i<<" "<<j<<" "<<myVec[i].first<<" "<<myVec[i].second<<endl;

    				if(j-myVec[i].second>=0 && dp[i-1][j-myVec[i].second]>=0){
    					dp[i][j]=1;
    				}
    			}
    		}
    	}

    	if(dp[compNo-1][n2]==-1){
    		cout<<"NO"<<endl;
    		return 0;
    	}

    	cout<<"YES"<<endl;


		ll assignment[compNo];
		ll curr=n2;
		for(int i=compNo-1;i>=0;i--){
			assignment[i]=dp[i][curr];
			if(assignment[i]==0){
				curr-=myVec[i].first;
			}
			else{
				curr-=myVec[i].second;
			}
		}

		for(int i=0;i<n;i++){
			if(assignment[component[i]]==isEven[i]){
				toBe2[i]=true;
			}
		}


    	ll onec=0;
    	for(int i=0;i<n;i++){
    		if(toBe2[i]){
    			cout<<2;
    		}
    		else{
    			if(onec<n1){
    				cout<<1;
    				onec++;
    			}
    			else{
    				cout<<3;
    			}
    		}
    	}
    	cout<<endl;
    }
}