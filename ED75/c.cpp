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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	string s;
    	cin>>s;

    	queue<char> odd;
    	queue<char> even;

    	for(int i=0;i<s.length();i++){
    		if((s[i]-'0')%2==0){
    			even.push(s[i]);
    		}
    		else{
    			odd.push(s[i]);    			
    		}
    	} 

    	string ans;
    	for(int i=0;i<s.length();i++){
    		if(odd.size()==0 || (even.size()>0 && even.front()<odd.front())){
    			ans.push_back(even.front());
    			even.pop();
    		}
    		else{
    			ans.push_back(odd.front());
    			odd.pop();    			
    		}
    	}
    	cout<<ans<<endl;
    }
}