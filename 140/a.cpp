#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	double ax,ay,bx,by,cx,cy;

   	cin>>ax>>ay;
   	cin>>bx>>by;
   	cin>>cx>>cy;

   	if((ax==bx && bx==cx)||(ay==by && by==cy) ||(bx-ax)/(by-ay) == (cx-bx)/(cy-by) /*|| (bx-ax)/(by-ay) == (-1)*(cx-bx)/(cy-by)*/){
   		cout<<"TOWARDS"<<endl;
   	}
   	else{

   		if(ay==by){
   			if(ax>bx){
   				if(cy>ay){
   					cout<<"RIGHT"<<endl;
   				}
   				else{
   					cout<<"LEFT"<<endl;
   				}
   			}
   			else{
   				if(cy>ay){
   					cout<<"LEFT"<<endl;
   				}
   				else{
   					cout<<"RIGHT"<<endl;
   				}   				
   			}
   		}
   		else if (ax==bx){
   			if(ay>by){
   				if(cx>ax){
   					cout<<"LEFT"<<endl;
   				}
   				else{
   					cout<<"RIGHT"<<endl;
   				}
   			}
   			else{
   				if(cx>ax){
   					cout<<"RIGHT"<<endl;
   				}
   				else{
   					cout<<"LEFT"<<endl;
   				}
   			}
   		}
   		else if (ax>bx){
   			if(ay>by){
   				if(cy>by){
   					cout<<"RIGHT"<<endl;
   				}
   				else{
   					cout<<"LEFT"<<endl;
   				}
   			}
   			else{
   				if(cy>by){
   					cout<<"RIGHT"<<endl;
   				}
   				else{
   					cout<<"LEFT"<<endl;
   				}
   			}
   		}
   		else{
   			if(ay>by){
   				if(cy>by){
   					cout<<"LEFT"<<endl;
   				}
   				else{
   					cout<<"RIGHT"<<endl;
   				}
   			}
   			else{
   				if(cy>by){
   					cout<<"LEFT"<<endl;
   				}
   				else{
   					cout<<"RIGHT"<<endl;
   				}

   			}
   		}

   	}

}
