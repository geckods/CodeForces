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

    //I will need a fenwick tree I believe

    //bool islegitleft
    //bool islegitright
    //int statusleft
    //int statusright
    //

    //i need to store the text (char arr, 10^6)
    //map[status]->count

    //totalsum

    //segtree for overallmax
    //segtree for overall min

    //store the lowest it goes on the left, on the right from here

    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<char> t;
    for(int i=0;i<n+1;i++){
    	t.push_back('0');
    }

    int leftmin=0;
    int rightmin=0;
    int pointer=0;

    int leftsum=0;
    int totsum=0;

    for(int i=0;i<n;i++){
    	if(s[i]=='R'){
    		if(t[pointer]=='('){
    			leftmin++;
    		}
    		else if (t[pointer]==')'){
    			leftmin--;
    		}
    		pointer++;
    		if(t[pointer]=='('){
    			leftsum++;
    			rightmin--;
    		}
    		else if (t[pointer]==')'){
    			leftsum--;
    			rightmin++;
    		}
    	}
    	else if(s[i]=='L'){
    		if(pointer==0)continue;
    		if(t[pointer]=='('){
    			leftsum--;
    			rightmin--;
    		}
    		else if (t[pointer]==')'){
    			leftsum++;
    			rightmin++;
    		}
    		pointer--;
    		if(t[pointer]=='('){
    			leftmin++;
    		}
    		else if (t[pointer]==')'){
    			leftmin--;
    		}

    	}
    	else if(s[i]=='('){
    		if(t[pointer]==')'){
    			leftsum+=2;
    			totsum+=2;
    		}
    		else if (t[pointer]!='('){
    			leftsum+=1;
    			totsum+=1;
    		}
    		t[pointer]='(';
    	}
    	else if(s[i]==')'){
    		if(t[pointer]=='('){
    			leftsum-=2;
    			totsum-=2;
    		}
    		else if (t[pointer]!=')'){
    			leftsum-=1;
    			totsum-=1;
    		}
    		t[pointer]=')';
    	}
    	else{
    		if(t[pointer]=='('){
    			leftsum--;
    			totsum--;
    		}
    		else if (t[pointer]==')'){
    			leftsum++;
    			totsum++;
    		}
    		t[pointer]=0;
    	}
    	leftmin=max(leftmin,0);
    	rightmin=max(rightmin,0);
    }