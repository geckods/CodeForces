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

    int n;
    cin>>n;

    string s;
    cin>>s;

    int a=0,b=0;
    int ac=0,bc=0;
    for(int i=0;i<n/2;i++){
    	if(s[i]=='?')
    		ac++;
    	else
	    	a+=s[i]-'0';
    }
    for(int i=n/2;i<n;i++){
    	if(s[i]=='?')
    		bc++;
    	else
	    	b+=s[i]-'0';
    }

    if((ac+bc)%2==1){
    	cout<<"Monocarp"<<endl;
    	return 0;
    }
    if(a==b && ac==bc){
    	cout<<"Bicarp"<<endl;
    	return 0;
    }

    if((a<=b && ac<=bc) || (a>=b && ac>=bc)){
    	cout<<"Monocarp"<<endl;
    	return 0;
    }

    //monocarp can enforce a min difference of 9*excess/2 or a max difference of 
    if((abs(ac-bc)/2)*9 == abs(a-b)){
    	cout<<"Bicarp"<<endl;
    	return 0;
    }

    cout<<"Monocarp"<<endl;
}