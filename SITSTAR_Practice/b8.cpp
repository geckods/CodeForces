#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    ll n = s.length();
    int evenArr[26];
    int oddArr[26];
    for(int i=0;i<26;i++){
    	evenArr[i]=oddArr[i]=0;
    }

    for(int i=0;i<s.length();i++){
    	if(i%2==0){
    		evenArr[s[i]-'A']++;
    	}
    	else{
    		oddArr[s[i]-'A']++;
    	}
    }

    bool works=true;
    int eOdd=0;
    int oOdd=0;

    int theEOdd=-1;
    int theOOdd=-1;

    for(int i=0;i<26;i++){
    	eOdd+=evenArr[i]&1;
    	if(evenArr[i]&1)theEOdd=i;
    	oOdd+=oddArr[i]&1;
    	if(oddArr[i]&1)theOOdd=i;
    }

    if((n&1)==0){
    	// even length string
    	for(int i=0;i<26;i++){
    		if(evenArr[i]!=oddArr[i]){
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}

    	string temp;
    	for(int i=0;i<26;i++){
    		for(int j=0;j<evenArr[i];j++){
    			temp+=('A'+i);
    		}
    	}

    	for(int i=0;i<temp.length();i++){
    		cout<<temp[i]<<temp[temp.length()-i-1];
    	}
    	cout<<endl;
    }
    else{
	    if(((n/2)&1)&&(eOdd>0 || oOdd>1)){
	        cout<<"NO"<<endl;
	        return 0;
	    }

	    if((!((n/2)&1))&&(eOdd>1 || oOdd>0)){
	        cout<<"NO"<<endl;
	        return 0;
	    }


	    string evenPal;
	    for(int i=0;i<26;i++){
	        // if(i==theEOdd)continue;
	        for(int j=0;j<evenArr[i]/2;j++){
	            evenPal += ('A'+i);
	        }
	    }

	    if(theEOdd!=-1)evenPal += ('A'+theEOdd);

	    for(int i=25;i>=0;i--){
	        // if(i==theEOdd)continue;
	        for(int j=0;j<evenArr[i]/2;j++){
	            evenPal += ('A'+i);
	        }
	    }

	    string oddPal;
	    for(int i=0;i<26;i++){
	        // if(i==theOOdd)continue;
	        for(int j=0;j<oddArr[i]/2;j++){
	        	// cerr<<i<<" "<<j<<endl;
	            oddPal += ('A'+i);
	        }
	    }

	    if(theOOdd!=-1)oddPal += ('A'+theOOdd);

	    for(int i=25;i>=0;i--){
	        // if(i==theOOdd)continue;
	        for(int j=0;j<oddArr[i]/2;j++){
	            oddPal += ('A'+i);
	        }
	    }

	    // cout<<evenPal<<" "<<oddPal<<endl;
	    // cout<<"HI"<<endl;

	    for(int i=0;i<oddPal.length();i++){
	    	cout<<evenPal[i]<<oddPal[i];
	    }
	    cout<<evenPal[evenPal.length()-1]<<endl;
    }


}