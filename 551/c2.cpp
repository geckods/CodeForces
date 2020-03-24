#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int l;
    string s;
    cin>>l;
    cin>>s;

    int leftcount[l];
    int rightcount[l];

    if(s[l-1]=='(' || s[l-2]=='('||s[0]==')'||s[1]==')'){
    	cout<<":("<<endl;
    	return 0;
    }

    int effectivecount=0;
    int quesno=0;
    for(int i=0;i<l;i++){
        if(s[i]=='(')effectivecount++;
        if(s[i]==')')effectivecount--;
        if(s[i]=='?')quesno++;
    }

    int a = (quesno-effectivecount)/2;
    int b = quesno-a;


    char ans[l+1];

    for(int i=0;i<l;i++){
        if(s[i]=='?'){
            if(a>0){
                ans[i]='(';
                a--;
            }
            else{
                ans[i]=')';
            }
        }
        else{
            ans[i]=s[i];
        }
    }

    int count=0;
    for(int i=0;i<l;i++){
        if(ans[i]=='(') count++;
        else count--;
        if(count<0 || i<l-1 && count==0){
            cout<<":("<<endl;
            return 0;
        }
    }

//    cout<<ans<<endl;

    if(count==0){
        ans[l]=0;
        cout<<ans<<endl;
    }
    else{
        cout<<":("<<endl;
        return 0;
    }
}