#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	int monsters[n];
    	for(int i=0;i<n;i++){
    		cin>>monsters[i];
    	}

    	int m;
    	cin>>m;

    	intpair heros[m];

    	for(int i=0;i<m;i++){
    		cin>>heros[i].first>>heros[i].second;
    	}

    	sort(heros,heros+m);

    	int rightmax[m];
    	rightmax[m-1]=heros[m-1].second;
    	for(int i=m-2;i>=0;i--){
    		rightmax[i]=max(rightmax[i+1],heros[i].second);
    	}

    	int firstmon=0;
    	int currmon;
    	int currmonmax;
    	int moncount=0;

    	bool works=true;
    	for(int i=0;i<n;i++){
    		if(monsters[i]>heros[m-1].first){
    			works=false;
    			break;
    		}
    	}

    	if(!works){
    		cout<<-1<<endl;
    		continue;
    	}
    	int ans=1;
    	while(firstmon<n){
    		currmon=firstmon;
    		moncount=1;
    		currmonmax=0;

    		//checking if currmon can be defeated on this day
    		// cout<<currmon<<endl;
    		while(currmon<n){
	    		currmonmax=max(monsters[currmon],currmonmax);
    			int lowhero = lower_bound(heros, heros+m, make_pair(currmonmax,-1))-heros;
    			if(rightmax[lowhero]<moncount){
    				//this monster cannot be defeated on this day
    				ans++;
    				break;
    			}
    			else{
    				currmon++;
    				moncount++;
    			}
    		}
    		// cout<<currmon<<" "<<moncount<<endl;
    		firstmon=currmon;
    	}
    	// cout<<endl;
    	cout<<ans<<endl;

    }
}