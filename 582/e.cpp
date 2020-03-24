#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int categorize(string a){
	if(a[0]==a[1])return 0;
	else if (a[1]==a[0]+1 || a[1]==a[0]-2){
		return 1;
	}
	else{
		return 2;
	}
}

char otherchar(char a, char b){
	unordered_set<char> mySet;
	mySet.insert('a');
	mySet.insert('b');
	mySet.insert('c');
	mySet.erase(mySet.find(a));
	mySet.erase(mySet.find(b));
	return *mySet.begin();
}

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

    string s,t;
    cin>>s;
    cin>>t;

    cout<<"YES"<<endl;

    int cat1=categorize(s);
    int cat2=categorize(t);

    int m1=min(cat1,cat2);
    int m2=max(cat1,cat2);

    if(m1>0 && m1==m2){//both in same direction, use other direction
    	if(m1==1){
    		for(int i=0;i<n;i++){
	    		cout<<"cba";
	    	}
    	}
    	else{
    		for(int i=0;i<n;i++){
	    		cout<<"abc";
	    	}    		
    	}
    }
    else{
    	if(m1==0){ //one of them doesn't matter, use the other direction
    		if(m2==1){
	    		for(int i=0;i<n;i++){
		    		cout<<"cba";
		    	}
    		}
    		else{
	    		for(int i=0;i<n;i++){
		    		cout<<"abc";
		    	}   			
    		}
    	}
    	else{
    		//m1>0, m1!=m2 -> opposite directions
    		//three cases -> inward common, outward common, and line common
    		if(s[1]==t[1]){//inward common
    			for(int i=0;i<n;i++){
    				cout<<s[1];
    			}
    			for(int i=0;i<n;i++){
    				cout<<s[0]<<t[0];
    			}
    		}
    		else if (s[0]==t[0]){
    			//outward common
    			for(int i=0;i<n;i++){
    				cout<<s[1]<<t[1];
    			}
    			for(int i=0;i<n;i++){
    				cout<<s[0];
    			}
    		}
    		else{
    			for(int i=0;i<n;i++){
    				cout<<s[0];
    			}
				char oc = otherchar(s[0],s[1]);
    			for(int i=0;i<n;i++){
    				cout<<oc<<s[1];
    			}
    			//line common
    		}
    	}
    }
    cout<<endl;
}