#include <bits/stdc++.h>
using namespace std;
int n;


bool belongs(char** board,int a, int b){
	if(a<=0 || a >= n-1 || b<=0 || b >= n-1){
		return false;
	}

	if(board[a-1][b]=='#'||board[a+1][b]=='#'||board[a][b]=='#'||board[a][b+1]=='#'||board[a][b-1]=='#'){
		return false;
	}

	return true;
}

int canputcount(char** board, int a, int b){
	int count = 0;

	if(belongs(board,a,b)) count++;
	if(belongs(board,a+1,b)) count++;
	if(belongs(board,a-1,b)) count++;
	if(belongs(board,a,b+1)) count++;
	if(belongs(board,a,b-1)) count++;

	return count;
}

void puthere(char** board, int a, int b){
	board[a][b]='#';
	board[a-1][b]='#';
	board[a+1][b]='#';
	board[a][b-1]='#';
	board[a][b+1]='#';
}

void coverhere(char** board, int a, int b){
	if(belongs(board,a,b)){
		puthere(board,a,b);
	}
	else if(belongs(board,a+1,b)){
		puthere(board,a+1,b);
	}
	else if(belongs(board,a-1,b)){
		puthere(board,a-1,b);
	}
	else if(belongs(board,a,b+1)){
		puthere(board,a,b+1);
	}
	else if(belongs(board,a,b-1)){
		puthere(board,a,b-1);
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);

    cin>>n;

    char** board = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
    	board[i] = (char*)malloc(sizeof(char)*n);
    }

    int dotcount=0;

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>board[i][j];
    		if(board[i][j]=='.') dotcount++;
    	}
    	getchar();
    }

    if(dotcount%5!=0){
    	cout<<"NO"<<endl;
    	return 0;
    }

    int canput;
    while(dotcount>0){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if(board[i][j]=='.'){
	    			canput = canputcount(board,i,j);
	    			if(canput==0){
	    				cout<<"NO"<<endl;
	    				return 0;
	    			}
	    			else if (canput==1){
	    				coverhere(board,i,j);
	    				dotcount -= 5;
	    			}
	    		}
    		}
    	}
    }
    cout<<"YES"<<endl;
}