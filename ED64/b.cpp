#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> intpair;

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
	    int arr[26];
	    for(int i=0;i<26;i++){
	    	arr[i]=0;
	    }
	    string s;
	    cin>>s;

	    for(int i=0;i<s.length();i++){
	    	arr[s[i]-'a']++;
	    }

	    char newstr[s.length()+1];
	    int as=0;

	    for(int i=0;i<26;i+=2){
	    	for(int j=0;j<arr[i];j++){
	    		newstr[as++]=(char)(i+'a');
	    	}
	    }
	    for(int i=1;i<=25;i+=2){
	    	for(int j=0;j<arr[i];j++){
	    		newstr[as++]=(char)(i+'a');
	    	}
	    }

	    bool done = false;
	    for(int i=0;i<s.length()-1;i++){
	    	if(abs(newstr[i]-newstr[i+1])==1){
	    		cout<<"No answer"<<endl;
	    		done = true;
	    		break;
	    	}
	    }

	    newstr[s.length()]=0;

	    if(!done){
	    	cout<<newstr<<endl;
	    }
	}
}


