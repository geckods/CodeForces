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

    int n;
    cin>>n;

    string s;
    cin>>s;

    bool works=true;
    int minneg=0;
    int curr=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='(')curr++;
    	else curr--;

    	minneg=min(minneg,curr);
    	if(minneg<-1)works=false;
    }
    if(curr!=0)works=false;
    if(works){
    	cout<<"Yes"<<endl;
    }
    else{
    	cout<<"No"<<endl;
    }
}