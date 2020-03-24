#include <bits/stdc++.h>
using namespace std;


void printx(int* row,int size, int check){
	for(int i=0;i<size;i++){
		if(row[i]==check){
			cout<<i+1<<" ";
			return;
		}
	}
}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,m;
    cin>>n>>m;

    int mainarr[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>mainarr[i][j];
    	}
    }

    for(int a=9;a>=0;a--){
    	int bitarr[n][m];
    	int rowcondition[n];


    	bool wearedone=false;
    	int onecount=0;

    	for(int i=0;i<n;i++){
	    	bool hasone = false;
    		bool haszero = false;
    		for(int j=0;j<m;j++){
    			bitarr[i][j]=(mainarr[i][j]/(int)pow(2,a))%2;
    			if(bitarr[i][j]==1){
    				hasone=true;
    			}
    			else{
    				haszero=true;
    			}
    		}

    		if(hasone&&haszero){
    			rowcondition[i]=2;
    			wearedone=true;
    		}
    		else if (hasone){
    			rowcondition[i]=1;
    			onecount++;
    		}
    		else{
    			rowcondition[i]=0;
    		}
    	}

    	if(wearedone){
    		cout<<"TAK"<<endl;
    		if(onecount%2==1){
    			for(int i=0;i<n;i++){
    				if(rowcondition[i]==1){
	    				printx(bitarr[i],m,1);
	    			}
	    			else{
	    				printx(bitarr[i],m,0);	    				
	    			}
    			}
    		}
    		else{
    			bool firsttwodone=false;
    			for(int i=0;i<n;i++){
    				if(rowcondition[i]==1){
	    				printx(bitarr[i],m,1);
	    			}
	    			else if (rowcondition[i]==0){
	    				printx(bitarr[i],m,0);
	    			}
	    			else{
	    				if(!firsttwodone){
		    				printx(bitarr[i],m,1);
		    				firsttwodone=true;
	    				}
	    				else{
	    					printx(bitarr[i],m,0);
	    				}
	    			}
    			}
    		}
    		return 0;
    	}
    	else{
    		if(onecount%2==1){
    			cout<<"TAK"<<endl;
    			for(int i=0;i<n;i++){
    				cout<<1<<" ";
    			}
    			return 0;
    		}
    		else{
    		}
    	}
    }
    cout<<"NIE"<<endl;
}
