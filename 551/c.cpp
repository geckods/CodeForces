#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int l;
    string s;
    cin>>l;
    cin>>s;

    int leftcount[l];
    int rightcount[l];

    if(s[l-1]=='(' || s[l-2]=='('||s[0]==')'||s[1]==')'){
    	cout<<":("<<endl;
    	return 0;
    }


    int currcost=0;
    for(int i=2;i<l-2;i++){
    	if(s[i]=='(') currcost++;
    	else if (s[i]==')') currcost--;
    	leftcount[i]=currcost;
    }

    currcost=0;
    for(int i=l-2;i>=2;i--){
    	if(s[i]=='(') currcost++;
    	else if (s[i]==')') currcost--;
    	rightcount[i]=currcost;
    }

    int effectivecount=0;
    int quesno=0;
    for(int i=2;i<l-2;i++){
    	if(s[i]=='(')effectivecount++;
    	if(s[i]==')')effectivecount--;
    	if(s[i]=='?')quesno++;
    }

    if(quesno<abs(effectivecount)){
    	cout<<":("<<endl;
    	return 0;
    }

    int maxdel[l];
    int i,j;

    int maxrem=0;
    for(int i=l-3;i>=2;i--){
    	if(s[i]==')') maxrem++;
    	else{
    		if(maxrem>0)
	    		maxrem--;
    	}
    	maxdel[i]=maxrem;
    }

   	// for(int i=0;i<l;i++){
   	// 	cout<<maxdel[i]<<" ";
   	// }
   	// cout<<endl;

   	char ans[l+1];
   	ans[0]='(';
   	ans[1]='(';
   	ans[l-1]=')';
   	ans[l-2]=')';

   	int currcount=0;
   	for(int i=2;i<l-2;i++){
   		if(currcount+1-maxdel[i]<=-2){
   			cout<<":("<<endl;
    		return 0;
   		}
   		else if(currcount-maxdel[i]==-2){
   			ans[i]='(';
   			currcount++;
   		}
   		else{
   			if(currcount+effectivecount <= 0){
   				ans[i]='(';
   				currcount++;
   			}
   			else{
   				ans[i]=')';
   				currcount--;
   			}
   		}
   	}

   	if(currcount+effectivecount!=0){
   		cout<<":("<<endl;
    	return 0;
   	}

   	ans[l]=0;

   	cout<<ans<<endl;
}