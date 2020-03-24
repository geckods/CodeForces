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

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int l=0;
    	int r=0;
    	int u=0;
    	int d=0;

    	string s;
    	cin>>s;

    	for(int i=0;i<s.length();i++){
    		if(s[i]=='L')l++;
    		if(s[i]=='R')r++;
    		if(s[i]=='D')d++;
    		if(s[i]=='U')u++;
    	}

    	l = r = min(l,r);
    	u = d = min(u,d);

    	if(u==0){
    		if(l>0){
    			cout<<2<<endl;
    			cout<<"LR"<<endl;
    		}
    		else{
    			cout<<0<<endl;
    		}
    	}
    	else if (l==0){
    		if(u>0){
    			cout<<2<<endl;
    			cout<<"UD"<<endl;
    		}    		
    		else{
    			cout<<0<<endl;
    		}
    	}
    	else{
    		vector<char> ans;
    		for(int i=0;i<l;i++){
    			ans.push_back('L');
    			// cout<<"L";
    		}
    		for(int i=0;i<u;i++){
    			ans.push_back('U');
    			// cout<<"U";
    		}
    		for(int i=0;i<r;i++){
    			ans.push_back('R');
    			// cout<<"R";
    		}
    		for(int i=0;i<d;i++){
    			ans.push_back('D');
    			// cout<<"D";
    		}
    		// cout<<endl;

    		cout<<ans.size()<<endl;
    		for(int i=0;i<ans.size();i++){
    			cout<<ans[i];
    		}
    		cout<<endl;
    	}
    }
}