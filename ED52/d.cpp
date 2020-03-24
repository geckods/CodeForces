#include <bits/stdc++.h>
using namespace std;


int rookjump(int a,int b, int x, int y){
  if (a==x && b==y) return 0;
  if (a==x || b==y) return 1;
  return 2;
}

int offsets[8][2] = {{-2,-1},{-2,1},{-1,2},{-1,-2},{1,-2},{1,2},{2,-1},{2,1}};

int bishopjump(int a, int b, int x, int y){
  int origin = (a+b)%2;
  int target = (x+y)%2;

  if (origin!=target) return INT_MAX/2;
  if (a==x && b==y) return 0;
  if ((a+b)==(x+y) || (a-b)==(x-y)) return 1;
  return 2;
}

int inbounds(int a, int b, int n){
  return (a>=0 && b>=0 && a<n && b<n);
}

int knight_neighbors(int a, int b, int n, int arr[8][2]){
  int count=0;

  for(int i=0;i<8;i++){
    if(inbounds(a+offsets[i][0],b+offsets[i][1],n)){
      arr[count][0] = a+offsets[i][0];
      arr[count][1] = b+offsets[i][1];
      count++;
    }
  }

  return count;
}
  

int knightjump(int a, int b, int x, int y,int n){

  int max = n*n;
  queue <int*> myqueue;
  int init[] = {a,b,0};

  myqueue.push(init);

  int neighborcount,curra,currb,currdepth;
  int neighbors[8][2];
  int* curr;
  int* z;

  while(!myqueue.empty()){
    curr = myqueue.front();
    myqueue.pop();

    curra=curr[0];
    currb=curr[1];
    currdepth=curr[2];

    if (currdepth==max){
      return INT_MAX/2;
    }
    if (curra==x&&currb==y) {
      return currdepth;
    }

    neighborcount = knight_neighbors(curra,currb,n,neighbors);
 
    for(int i=0;i<neighborcount;i++){
      z = (int*)malloc(sizeof(int)*3);
      z[0] = neighbors[i][0];
      z[1] = neighbors[i][1];
      z[2] = currdepth+1;
      myqueue.push(z);
    }
  }
  return INT_MAX/2;
}


void find(int i, int arr[],int n, int nextlocation[]){
  for(int j=0;j<n*n;j++){
    if(i==arr[j]){
      nextlocation[0] = j/n;
      nextlocation[1] = j%n;
      return;
    }
  }
}

void min(int a[],int n,int targ[]){
  int minnum = a[0];
  int minind = 0;
  for (int i=1;i<n;i++){
    if (a[i]<minnum){
      minnum = a[i];
      minind = i;
    }
  }

  targ[0] = minnum;
  targ[1] = minind;
}

void minswitch(int a[], int b[],int n,int targ[]){
  int minnum = a[0];
  int minind = 0;
  int minswitch=b[0];

  for (int i=1;i<n;i++){
    if ((a[i]<minnum)||(a[i]==minnum && b[i]<minswitch)){
//      cout<<"HI"<<(a[i]==minnum && b[i]<minswitch)<<endl;
      minnum = a[i];
      minind = i;
      minswitch = b[i];
    } 
  }

  targ[0] = minnum;
  targ[1] = minind;
}

int thecheck(int a,int b,int x,int y){
  return (b>a && y>x);
}

int main(){
  int n,t;
  cin>>n;

  int arr[n*n];

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>t;
      arr[i*n+j] = t-1;
    }
  }

  int rbk[n*n+1][3][2] = {0};
  int currlocation[2];
  int nextlocation[2];
  int rookpath,bishoppath,knightpath;
  int rooktocompare[3],bishoptocompare[3],knighttocompare[3];
  int rooktocompareswitch[3],bishoptocompareswitch[3],knighttocompareswitch[3];
  int rookmin[2],bishopmin[2],knightmin[2];
  int temparr[3],tempmin[2];

  find(0,arr,n,currlocation);

  for(int i=1;i<n*n+1;i++){
    find(i,arr,n,nextlocation);

    rookpath = rookjump(currlocation[0],currlocation[1],nextlocation[0],nextlocation[1]);
    bishoppath = bishopjump(currlocation[0],currlocation[1],nextlocation[0],nextlocation[1]);
    knightpath=knightjump(currlocation[0],currlocation[1],nextlocation[0],nextlocation[1],n);

//    cout<<currlocation[0]<<"\t"<<currlocation[1]<<"\t"<<nextlocation[0]<<"\t"<<nextlocation[1]<<endl;
//    cout<<rookpath<<"\t"<<bishoppath<<"\t"<<knightpath<<"\t"<<endl;
//    rooktocompare = {rbk[i-1][0][0] + rookpath,rbk[i-1][1][0] + bishoppath+1,rbk[i-1][2][0] + knightpath+1};
    rooktocompare[0] = rbk[i-1][0][0] + rookpath;
    rooktocompare[1] = rbk[i-1][1][0] + bishoppath+1;
    rooktocompare[2] = rbk[i-1][2][0] + knightpath+1;

    rooktocompareswitch[0] = rbk[i-1][0][0];
    rooktocompareswitch[1] = rbk[i-1][1][0]+1;
    rooktocompareswitch[2] = rbk[i-1][2][0]+1;

//   cout<<rooktocompare[0]<<"\t"<<rooktocompare[1]<<"\t"<<rooktocompare[2]<<"\t"<<endl<<endl;
//    bishoptocompare = {rbk[i-1][1][0] + bishoppath,rbk[i-1][0][0] + rookpath+1,rbk[i-1][2][0] + knightpath+1};
    bishoptocompare[0] = rbk[i-1][1][0] + bishoppath;
    bishoptocompare[1] = rbk[i-1][0][0] + rookpath+1;
    bishoptocompare[2] = rbk[i-1][2][0] + knightpath+1;
    bishoptocompareswitch[0] = rbk[i-1][1][0];
    bishoptocompareswitch[1] = rbk[i-1][0][0]+1;
    bishoptocompareswitch[2] = rbk[i-1][2][0]+1;


//    knighttocompare = {rbk[i-1][2][0] + knightpath,rbk[i-1][0][0] + rookpath+1,rbk[i-1][1][0] + bishoppath+1};
    knighttocompare[0] = rbk[i-1][2][0] + knightpath;
    knighttocompare[1] = rbk[i-1][0][0] + rookpath+1;
    knighttocompare[2] = rbk[i-1][1][0] + bishoppath+1;
    knighttocompareswitch[0] = rbk[i-1][2][0];
    knighttocompareswitch[1] = rbk[i-1][0][0]+1;
    knighttocompareswitch[2] = rbk[i-1][1][0]+1;

    //for rook
    minswitch(rooktocompare,rooktocompareswitch,3,rookmin);
    
    rbk[i][0][0] = rookmin[0];
    rbk[i][0][1] = rbk[i-1][rookmin[1]][1];
    if(rookmin[1]>0) rbk[i][0][1]++;

    //for bishop
    minswitch(bishoptocompare,bishoptocompareswitch,3,bishopmin);
    rbk[i][1][0] = bishopmin[0];
    if(bishopmin[1] == 0) rbk[i][1][1] = rbk[i-1][1][1];
    if(bishopmin[1] == 1) rbk[i][1][1] = rbk[i-1][0][1];
    if(bishopmin[1] == 2) rbk[i][1][1] = rbk[i-1][2][1];

    if(bishopmin[1]>0) rbk[i][1][1]++;
    
    //for knight
    minswitch(knighttocompare,knighttocompareswitch,3,knightmin);
    rbk[i][2][0] = knightmin[0];

    if(knightmin[1] == 0) rbk[i][2][1] = rbk[i-1][2][1];
    if(knightmin[1] == 1) rbk[i][2][1] = rbk[i-1][0][1];
    if(knightmin[1] == 2) rbk[i][2][1] = rbk[i-1][1][1];
    if(knightmin[1]>0) rbk[i][2][1]++;


    cout<<i<<endl;
    for(int j=0;j<3;j++){
      cout<<rbk[i][j][0]<<" "<<rbk[i][j][1]<<endl;
    }
    cout<<endl;

    for(int j=0;j<3;j++){
      temparr[j] = rbk[i][j][0];
    }

    min(temparr,3,tempmin);

    for(int j=0;j<3;j++){
      if (j==tempmin[1]) continue;
      if (thecheck(tempmin[0],rbk[i][j][0],rbk[i][tempmin[1]][1],rbk[i][j][1])){
        rbk[i][j][0] = tempmin[0]+1;
        rbk[i][j][1] = rbk[i][tempmin[1]][1]+1;
      }
    }

    currlocation[0] = nextlocation[0];
    currlocation[1] = nextlocation[1];
  }

  int anstocompare[3] = {rbk[n*n][0][0],rbk[n*n][1][0],rbk[n*n][2][0]};
  int ans[2];
  min(anstocompare,3,ans);  

  cout<<ans[0]<<" "<<rbk[n*n][ans[1]][1]<<endl;
}
    
