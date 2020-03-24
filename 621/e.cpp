#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

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

   	ll sweet[n];
   	for(int i=0;i<n;i++){
   		cin>>sweet[i];
   	}

   	ll cows[m][2];
   	for(int i=0;i<m;i++){
   		cin>>cows[i][0]>>cows[i][1];
   	}

   	ll cowstops[m][2];

   	ll curr;
   	bool done;

   	ll leftcow[n];
   	ll rightcow[n];

   	memset(leftcow,-1,sizeof(leftcow));
   	memset(rightcow,-1,sizeof(rightcow));

   	for(int i=0;i<m;i++){
   		curr=0;
   		done=false;
   		for(int j=0;j<n;j++){
   			if(sweet[j]==cows[i][0]){
   				curr++;
   			}
   			if(curr==cows[i][1]){
   				done=true;
   				cowstops[i][0]=j;
   				leftcow[j]=i;
   				break;
   			}
   		}

   		if(!done){
   			cowstops[i][0]=INT_MAX;
   		}

   		curr=0;
   		done=false;
   		for(int j=n-1;j>=0;j--){
   			if(sweet[j]==cows[i][0]){
   				curr++;
   			}
   			if(curr==cows[i][1]){
   				done=true;
   				cowstops[i][1]=j;
   				rightcow[j]=i;
   				break;
   			}
   		}

   		if(!done){
   			cowstops[i][1]=INT_MAX;
   		}
   	}

   	ll currmaxsleep=0;
   	ll currways=0;

   	for(int i=0;i<=n;i++){
   		ll mul[n];
   		memset(mul,0,sizeof(mul));
   		ll twopow=0;
   		//last leftcow sleeps at i-1
   		ll sleepc=0;

   	// 	for(int j=0;j<m;j++){
   	// 		if(cowstops[j][0]==INT_MAX)continue;
   	// 		if(cowstops[j][0]<i && cowstops[j][1]>=i){
   	// 			sleepc++;
   	// 			twopow++;
   	// 		}
   	// 		else{
				// if(cowstops[j][0]<i || cowstops[j][1]>=i){
				// 	if(cowstops[j][0]<i){
				// 		mul[cowstops[j][0]]++;
				// 	}
				// 	else{
				// 		mul[cowstops[j][1]]++;
				// 	}
				// 	sleepc++;
				// }
   	// 		}
   	// 	}

   		int o=i-1;
   		int p=i;
   		cerr<<i<<endl;
   		if(o>-1 && leftcow[o]==-1)continue;

   		set<int> usedCow;
   		set<int> leftusedCow;
   		set<int> rightusedCow;


   		while(o>=0 || p<n){
   			while(o>=0 && leftcow[o]==-1)o--;
	   		while(p<n && rightcow[p]==-1)p++;

	   		cerr<<o<<" "<<p<<" "<<leftcow[0]<<" "<<rightcow[p]<<endl;
	   		if(o>=0 && p<n && leftcow[o]==rightcow[p] && leftusedCow.find(cows[leftcow[o]][0])==leftusedCow.end() && rightusedCow.find(cows[leftcow[o]][0])==rightusedCow.end()){
	   			twopow++;
	   			sleepc++;
	   			leftusedCow.insert(cows[leftcow[o]][0]);
	   			rightusedCow.insert(cows[leftcow[o]][0]);
	   			// usedCow.insert(leftcow[o]);
	   		}
	   		else{
	   			if(o>=0 && leftusedCow.find(cows[leftcow[o]][0])==leftusedCow.end() && usedCow.find(leftcow[o])==usedCow.end()){
	   				sleepc++;
		   			leftusedCow.insert(cows[leftcow[o]][0]);
		   			usedCow.insert(leftcow[o]);
	   			}
	   			if (p<n && rightusedCow.find(cows[rightcow[p]][0])==rightusedCow.end()&& usedCow.find(rightcow[p])==usedCow.end()){
	   			// cerr<<"H"<<endl;
	   				sleepc++;
		   			rightusedCow.insert(cows[rightcow[p]][0]);
		   			usedCow.insert(rightcow[p]);
	   			}
	   		}
	   		o--;
	   		p++;
   		}

   		if(sleepc==currmaxsleep || sleepc>currmaxsleep){
   			ll mult=1;
   			while(twopow--){
   				mult*=2;
   				mult%=MOD;
   			}

   			if(sleepc==currmaxsleep){
   				currways+=mult;
   				currways%=MOD;
   			}
   			else{
   				currmaxsleep=sleepc;
   				currways=mult;
   			}
   		}

   		o=i-1;
   		p=i;
   		sleepc=0;
   		twopow=0;
   		usedCow.clear();
   		leftusedCow.clear();
   		rightusedCow.clear();

   		while(o>=0 || p<n){
   			while(o>=0 && leftcow[o]==-1)o--;
	   		while(p<n && rightcow[p]==-1)p++;

	   		cerr<<o<<" "<<p<<" "<<leftcow[0]<<" "<<rightcow[p]<<endl;
	   		if(o>=0 && p<n && leftcow[o]==rightcow[p] && leftusedCow.find(cows[leftcow[o]][0])==leftusedCow.end() && rightusedCow.find(cows[leftcow[o]][0])==rightusedCow.end()){
	   			twopow++;
	   			sleepc++;
	   			leftusedCow.insert(cows[leftcow[o]][0]);
	   			rightusedCow.insert(cows[leftcow[o]][0]);
	   			// usedCow.insert(leftcow[o]);
	   		}
	   		else{
	   			if (p<n && rightusedCow.find(cows[rightcow[p]][0])==rightusedCow.end()&& usedCow.find(rightcow[p])==usedCow.end()){
	   			// cerr<<"H"<<endl;
	   				sleepc++;
		   			rightusedCow.insert(cows[rightcow[p]][0]);
		   			usedCow.insert(rightcow[p]);
	   			}
	   			if(o>=0 && leftusedCow.find(cows[leftcow[o]][0])==leftusedCow.end() && usedCow.find(leftcow[o])==usedCow.end()){
	   				sleepc++;
		   			leftusedCow.insert(cows[leftcow[o]][0]);
		   			usedCow.insert(leftcow[o]);
	   			}
	   		}
	   		o--;
	   		p++;
   		}
   		// cerr<<"HO"<<endl;

   		if(sleepc==currmaxsleep || sleepc>currmaxsleep){
   			ll mult=1;
   			while(twopow--){
   				mult*=2;
   				mult%=MOD;
   			}

   			if(sleepc==currmaxsleep){
   				currways+=mult;
   				currways%=MOD;
   			}
   			else{
   				currmaxsleep=sleepc;
   				currways=mult;
   			}
   		}

   		cerr<<i<<" "<<sleepc<<endl;


   	}

   	cout<<currmaxsleep<<" "<<currways<<endl;

}