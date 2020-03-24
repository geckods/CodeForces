#include <bits/stdc++.h>
using namespace std;

/*Too much thinking, not in the mood. Taking lite for now*/

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //If you get two zeroes, the snake is either completely in there or not in there at all
    //If you query every column and every row, that should be enough. 
    //while querying every row, if you get two rows with odd anwers, the head and tail lie in those two rows
    // if you get no rows with odd answers, then it should be the one with minimum

    int headrow,tailrow,headcol,tailcol;

    int n;
    cin>>n;

    int rows[n];
    int cols[n];

    int response;

    int oddrows[2];
    int oddrowscount;

    for(int i=0;i<n;i++){
    	cout<<"? 1 1 1 "<<i+1<<endl;
    	fflush(stdout);
    	cin>>response>>>endl;
    	if(response%2==1){
    		oddrows[oddrowscount++]=i;
    	}
    	rows[i]=response;
    }

    int oddcols[2];
    int oddcolscount;

    for(int i=0;i<n;i++){
    	cout<<"? 1 1 "<<i+1<<" 1 "<<endl;
    	fflush(stdout);
    	cin>>response>>>endl;
    	if(response%2==1){
    		oddcols[oddcolscount++]=i;
    	}
    	cols[i]=response;
    }

    if(oddrowscount==0){
    	int minrow=INT_MAX;
    	for(int i=0;i<n;i++){
    		if(rows[i]<minrow) minrow=rows[i];
    	}

    	int asd
    }

   
	cout<<"? "<<oddrows[0]<<" "<<oddcols[0]<<" "<<oddrows[0]<<" "<<oddcols[0]<<" "<<endl;
	fflush(stdout);

}