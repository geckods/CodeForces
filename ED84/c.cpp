#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	// =


    ll n,m,k;
    cin>>n>>m>>k;

    ll start[k][2];

    ll maxStarti=-1;
    ll maxStartj=-1;

    for(int i=0;i<k;i++){
    	cin>>start[i][0]>>start[i][1];
    	start[i][0]--;
    	start[i][1]--;
    	// cerr<<start[i][0]<<" "<<start[i][1]<<endl;
    	maxStarti=max(maxStarti,start[i][0]);
    	maxStartj=max(maxStartj,start[i][1]);
    }


    ll lastFinish[2]={n-1,m-1};

    if(n%2==0)lastFinish[1]=0;

    ll finish[k][2];
    for(int i=0;i<k;i++){
    	cin>>finish[i][0]>>finish[i][1];
		finish[i][0]--;
		finish[i][1]--;
    }


    vector<char> ans;

    for(int i=0;i<maxStarti;i++){
    	ans.push_back('U');
    }

    for(int i=0;i<maxStartj;i++){
    	ans.push_back('L');
    }


    ll curri=0,currj=0;
	bool right=true;
    while(1){
    	if(curri==lastFinish[0] && currj==lastFinish[1])break;
    	if(right){
    		if(currj<m-1){
    			currj++;
    			ans.push_back('R');
    		}
    		else{
    			right=false;
    			curri++;
    			ans.push_back('D');
    		}
    	}
    	else{
    		if(currj>0){
    			currj--;
    			ans.push_back('L');
    		}
    		else{
    			right=true;
    			curri++;
    			ans.push_back('D');
    		}
    	}
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i];
    }
    cout<<endl;
}
