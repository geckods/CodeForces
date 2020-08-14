#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    if(n<=2){
    	cout<<-1<<endl;
    	return 0;
    }

    ll curr=1;
    ll currFill=n;
    ll arr[n][n];

    bool way=true;

    while(currFill>0){
    	if(currFill==3){
    		arr[1][1]=curr++;
    		arr[1][0]=curr++;
    		arr[2][1]=curr++;
    		arr[0][1]=curr++;
    		arr[0][2]=curr++;
    		arr[2][2]=curr++;
    		arr[1][2]=curr++;
    		arr[2][0]=curr++;
    		arr[0][0]=curr++;
    		currFill=0;
    	}
    	else if(currFill==4){
    		if(way){
    			for(int i=0;i<currFill;i++){
    				arr[i][currFill-1]=curr++;
    			}
    			for(int i=currFill-2;i>=2;i--){
    				arr[currFill-1][i]=curr++;
    			}
    			arr[currFill-1][0]=curr++;
    			arr[currFill-1][1]=curr++;
    		}
    		else{
    			for(int i=0;i<currFill;i++){
    				arr[currFill-1][i]=curr++;
    			}
    			for(int i=currFill-2;i>=2;i--){
    				arr[i][currFill-1]=curr++;
    			}
    			arr[0][currFill-1]=curr++;
    			arr[1][currFill-1]=curr++;
    		}
			way=!way;	
			currFill--;
    	}
    	else{
    		if(way){
    			for(int i=0;i<currFill;i++){
    				arr[i][currFill-1]=curr++;
    			}
    			for(int i=currFill-2;i>=0;i--){
    				arr[currFill-1][i]=curr++;
    			}
    		}
    		else{
    			for(int i=0;i<currFill;i++){
    				arr[currFill-1][i]=curr++;
    			}
    			for(int i=currFill-2;i>=0;i--){
    				arr[i][currFill-1]=curr++;
    			}
    		}
			way=!way;	
			currFill--;
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }
}