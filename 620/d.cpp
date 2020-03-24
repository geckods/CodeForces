#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;

    	int consLeftLT[n];
    	int consLeftGT[n];
    	int consRightLT[n];
    	int consRightGT[n];

    	int ltCount=0;
    	int gtCount=0;

    	consLeftLT[0]=consLeftGT[0]=0;
    	for(int i=0;i<n-1;i++){
    		if(s[i]=='>'){
    			gtCount++;
    			ltCount=0;
    		}
    		else{
    			ltCount++;
    			gtCount=0;
    		}

    		consLeftLT[i+1]=ltCount;
    		consLeftGT[i+1]=gtCount;
    	}

    	ltCount=0;
    	gtCount=0;

    	consRightLT[n-1]=consRightGT[n-1]=0;
    	for(int i=n-2;i>=0;i--){
    		if(s[i]=='>'){
    			gtCount++;
    			ltCount=0;
    		}
    		else{
    			ltCount++;
    			gtCount=0;
    		}

    		consRightLT[i]=ltCount;
    		consRightGT[i]=gtCount;
    	}

    	int atleastLT[n];
    	int atleastGT[n];

    	for(int i=0;i<n;i++){
    		atleastGT[i]=max(consLeftLT[i],consRightGT[i]);
    		atleastLT[i]=max(consLeftGT[i],consRightLT[i]);
    		// cerr<<i<<" "<<consLeftLT[i]<<" "<<consLeftGT[i]<<endl;
    		// cerr<<i<<" "<<consRightLT[i]<<" "<<consRightGT[i]<<endl;
    		// cerr<<i<<" "<<atleastLT[i]<<" "<<atleastGT[i]<<endl;

    	}

    	// ordered_set mySet;
    	// for(int i=1;i<=n;i++){
    	// 	mySet.insert(i);
    	// }

    	// int currcap=n;
    	// int newcurrcap=n;
    	// int curr;
    	// int prev;
    	// bool free=true;
    	// int abovec=0;
    	// for(int i=0;i<n;i++){
    		// auto temp=mySet.find_by_order(atleastGT[i]);
    		// auto temp2=mySet.find_by_order(mySet.size()-atleastLT[i]-1);
    		// // cerr<<i<<" "<<*temp<<" "<<*temp2<<endl;

    		// if(*temp==0)temp=temp2;
    		// if(*temp2==0)temp2=temp;

    		// if(*temp<*temp2){
	    	// 	cout<<*temp<<" ";
	    	// 	mySet.erase(temp);    			
    		// }
    		// else{
	    	// 	cout<<*temp2<<" ";
	    	// 	mySet.erase(temp2);    			
    		// }

    		//want largest number earliest
    		//on > or free, put largest number possible
    		//on <, increment last
    		// if(free){
    		// 	curr=currcap-max(consRightLT[i],1);
    		// }
    		// else{
    		// 	curr=prev+1;
    		// }
    		// // abovec++;
    		// cout<<curr<<" ";
    		// currcap=min(currcap,curr);
    		// prev=curr;

    		// if(i<n-1 && s[i]=='>'){
    		// 	free=true;
    		// }
    		// else{
    		// 	free=false;
    		// }

    	// 	if(i<n && s[i]=='>'){
    	// 		currcap=newcurrcap;
    	// 		curr=currcap;
    	// 		currcap--;
    	// 		if(newcurrcap>currcap)newcurrcap--;
    	// 	}
    	// 	else{
    	// 		curr=currcap-consRightLT[i];
    	// 		newcurrcap=min(newcurrcap,curr-1);
    	// 	}
    	// 	cout<<curr<<" ";
    	// }
    	// cout<<endl;
    	// mySet.clear();

    	// for(int i=1;i<=n;i++){
    	// 	mySet.insert(i);
    	// }

    	// free=true;
    	// currcap=1;
    	// for(int i=0;i<n;i++){
    		// auto temp=mySet.find_by_order(atleastGT[i]);
    		// auto temp2=mySet.find_by_order(mySet.size()-atleastLT[i]-1);
    		// if(*temp==0)temp=temp2;
    		// if(*temp2==0)temp2=temp;

    		// // cerr<<i<<" "<<*temp<<" "<<*temp2<<endl;
    		// if(*temp>*temp2){
	    	// 	cout<<*temp<<" ";
	    	// 	mySet.erase(temp);    			
    		// }
    		// else{
	    	// 	cout<<*temp2<<" ";
	    	// 	mySet.erase(temp2);    			
    		// }
    	// 	if(free){
    	// 		curr=currcap+atleastGT[i];
    	// 	}
    	// 	else{
    	// 		curr=prev-1;
    	// 	}
    	// 	cout<<curr<<" ";
    	// 	currcap=max(currcap,curr);
    	// 	prev=curr;

    	// 	if(i<n-1 && s[i]=='<'){
    	// 		free=true;
    	// 	}
    	// 	else{
    	// 		free=false;
    	// 	}


    	// }
    	// cout<<endl;

    	// int currmax=n;
    	// int prev;
    	// int curr;
    	// bool constrain=false;
    	// for(int i=0;i<n;i++){
    	// 	if(i<n && s[i]=='>' && !constrain){
    	// 		curr=currmax;
    	// 		currmax--;
    	// 	}
    	// 	else{
    	// 		if(i>0 && s[i-1]=='>'){
	    // 			curr=currmax-consRightLT[i];
	    // 			currmax=curr;
    	// 			constrain=true;
    	// 		}
    	// 		else{
    	// 			curr=prev+1;
    	// 		}
    	// 	}

    	// 	cout<<curr<<" ";
    	// 	prev=curr;
    	// }

    	// cout<<endl;

    	int i=0;
	    int currmax=n;
    	while(i<n){
	    	if(s[i]=='<'){
	    		currmax-=consRightLT[i];
	    		for(int j=0;j<=consRightLT[i];j++){
	    			cout<<currmax+j<<" ";
	    		}
	    		i+=consRightLT[i]+1;
	    		currmax--;
	    	}
	    	else{
	    		// cerr<<i<<" "<<currmax<<endl;
	    		cout<<currmax<<" ";
	    		currmax--;
	    		i++;
	    	}

    	}

    	cout<<endl;

    	i=0;
	    int currmin=1;
    	while(i<n){
	    	if(s[i]=='>'){
	    		currmin+=consRightGT[i];
	    		for(int j=0;j<=consRightGT[i];j++){
	    			cout<<currmin-j<<" ";
	    		}
	    		i+=consRightGT[i]+1;
	    		currmin++;
	    	}
	    	else{
	    		// cerr<<i<<" "<<currmax<<endl;
	    		cout<<currmin<<" ";
	    		currmin++;
	    		i++;
	    	}

    	}
    	cout<<endl;


    }
}