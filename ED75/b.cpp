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

    int q;
    cin>>q;

    for(int test=0;test<q;test++){
    	int n;
    	cin>>n;

    	vector<string> myVec;
    	string s;
    	
    	int lenpar=0;
    	int onec=0;

    	for(int i=0;i<n;i++){
    		cin>>s;
    		myVec.push_back(s);
    		lenpar+=(s.length()%2);
    		for(int j=0;j<s.length();j++){
    			if(s[j]=='1')onec++;
    		}
    	}

    	if(onec%2==1 && lenpar==0){
    		cout<<n-1<<endl;
    	}
    	else{
    		cout<<n<<endl;    		
    	}
    }
}

