#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
    string cs;
    cin>>cs;
    string as;
    cin>>as;

    int nc=0;
    int cc=0;
    int ac=0;
    int bc=0;

    for(int i=0;i<n;i++){
    	cs[i]-='0';
    	as[i]-='0';

    	if(!cs[i]&&!as[i]) nc++;
    	else if (!cs[i]&&as[i])ac++;
    	else if (cs[i]&&!as[i])cc++;
    	else bc++;
    }

//    cout<<nc<<" "<<ac<<" "<<cc<<" "<<bc<<endl;

    int clown=0;
    int acrobat=0;
    int toaddjusta;

    int sola;
    int solb;//just cs in partition 1
    int solc;//just as in partition 1
    int sold;//boths in partition 1


    for(int i=0;i<=cc+bc;i++){
    	//see if you can put i clowns in the first set
    	clown=i;
    	for(int j=0;j<=min(i,cc);j++){
    		//let j be the number of clown-only
    		//i-j is the number of boths in the clown
    		//bc-(i-j)

    		acrobat=bc-(i-j);//from the both category, in partition two
    		if(acrobat<0) continue;

    		toaddjusta=i-(acrobat);//just as, in partition two
    		if(toaddjusta<0 || toaddjusta>ac) continue;

    		solb=j;
    		solc=ac-toaddjusta;
    		sold=i-j;

    		sola=(n/2)-(solb+solc+sold);


    		if(sola<0 || sola>nc) continue;
    		if(solb<0 || solb>cc) continue;
    		if(solc<0 || solc>ac) continue;
    		if(sold<0 || sold>bc) continue;

    		int z=0;

    		if(solb+sold != (ac-solc)+(bc-sold)) continue;
//    		cout<<i<<" "<<j<<endl;
//    		cout<<sola<<" "<<solb<<" "<<solc<<" "<<sold<<endl;

    		while(sola+solb+solc+sold>0){
    			if(!cs[z]&&!as[z]&&sola>0){
    				cout<<z+1<<" ";
    				sola--;
    			}
		    	else if(!cs[z]&&as[z] && solc>0){
		    		cout<<z+1<<" ";
		    		solc--;
		    	}
		    	else if (cs[z]&&!as[z]&&solb>0){
		    		cout<<z+1<<" ";
		    		solb--;
		    	}
    			else if(cs[z]&&as[z]&&sold>0){
    				cout<<z+1<<" ";
    				sold--;
    			}
    			z++;
    		}
    		cout<<endl;
    		return 0;

//    		cout<<i<<" "<<j<<endl;
    	}
    }
    cout<<-1<<endl;
}