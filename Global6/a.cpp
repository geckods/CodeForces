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

    for(int test=0;test<n;test++){
    	string y;
    	cin>>y;

    	bool haszero=false;
    	bool haseven=false;
    	int sum=0;

    	for(int i=0;i<y.size();i++){
    		if(y[i]=='0' && !haszero){
    			haszero=true;
    			continue;
    		}
    		if((y[i]-'0')%2==0){
    			haseven=true;
    		}
    		sum+=y[i]-'0';
    	}

    	if((sum%3==0 && haszero && haseven) || sum==0){
    		cout<<"red"<<endl;
    	}
    	else{
    		cout<<"cyan"<<endl;
    	}
    }
}
