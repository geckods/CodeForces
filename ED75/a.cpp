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
    cin>>t;

    for(int test=0;test<t;test++){
    	string s;
    	cin>>s;

    	int n = s.size();
    	int i=0,j=0;
    	set<char> ans;
    	while(i<n){
    		while(j<n && s[j]==s[i])j++;
    		if((j-i)%2==1){
    			ans.insert(s[i]);
    		}
    		i=j;
    	}

    	for(set<char>::iterator asd = ans.begin();asd!=ans.end();asd++){
    		cout<<*asd;
    	}
    	cout<<endl;
    }

}
