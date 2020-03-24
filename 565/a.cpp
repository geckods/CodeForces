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

   	int q;
   	cin>>q;

   	while(q--){
   		ll curr;
   		cin>>curr;

   		int twocount=0;
   		int threecount=0;
   		int fivecount=0;

   		while(curr%2==0){
   			curr/=2;
   			twocount++;
   		}

   		while(curr%3==0){
   			curr/=3;
   			threecount++;
   		}

   		while(curr%5==0){
   			curr/=5;
   			fivecount++;
   		}

   		// cout<<twocount<<" "<<threecount<<" "<<fivecount<<endl;

   		if(curr==1){
   			 cout<<twocount+2*threecount+3*fivecount<<endl;
   		}
   		else{
   			cout<<-1<<endl;
   		}
   	}

}
