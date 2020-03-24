#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n;
    int firstcount;
    int lastcount;
    string s;
    cin>>t;

    for(int test=0;test<t;test++){
    	cin>>n;
    	cin>>s;
    	if(s[0]=='<' && s[n-1]=='>'){
   			firstcount=0;
    		while(firstcount<n && s[firstcount]=='<')
    			firstcount++;
    		lastcount=n-1;
    		while(lastcount>0 && s[lastcount]=='>')
    			lastcount--;
    		cout<<min(firstcount,n-1-lastcount)<<endl;
    	}
    	else{
    		cout<<0<<endl;
    	}
    }
}