#include <stdio.h>
typedef long int li;

/*
li traversetill(int x, int n, int a[], int b[]){
  li ans=0;
  int time=0,endtime;
  int z=1;

  for(int i=0;i<x;i++){
    if (z){
      ans += time*a[i/2];
      z = 0;
    }
    else{
      ans += time*b[i/2];
      z = 1;
    }
    time++;
  }

  endtime = time;
  printf("Z:%d\n",z);

//  while(time<n*2){
  if(z){
    for(int i=(time/2);i<n;i++){
      ans+= time*a[i];
//      printf("%d %d %d\n",time,a[i],ans);
      time++;
    }
    for(int i=n-1;i>=(endtime/2);i--){
      ans+= time*b[i];
//      printf("%d %d %d\n",time,b[i],ans);
      time++;
    }
    return ans;
  }
  else{
    for(int i=(time/2)+1;i<n;i++){
      ans+= time*b[i];
      time++;
    }
    for(int i=n-1;i>=(endtime/2)+1;i--){
      ans+= time*a[i];
      time++;
    }
    return ans;
  }
//  }
}
*/


li traversetill(int x, int n, int a[], int b[],li mem[]){
  li ans=0;
  int time=0,endtime;
  int z=1;

/*  for(int i=0;i<x+1;i++){
    if (z){
      ans += time*a[i];
      time++;
      ans += time*b[i];
      z = 0;
    }
    else{
      ans += time*b[i];
      time++;
      ans += time*a[i];
      z = 1;
    }
    time++;
  }
*/


  if (x==0){
    ans = mem[0] = b[0];
    z = 0;
  }
  else{
    if(x%2==1){
      ans = mem[x-1];
      ans += 2*x*b[x];
      ans += (2*x+1)*a[x];
      mem[x] = ans;
      time = 2*(x+1);
//      z=0;
    }
    else{
      ans = mem[x-1];
      ans += 2*x*a[x];
      ans += (2*x+1)*b[x];
      mem[x] = ans;
      time = 2*(x+1);
      z = 0;
    }
  }
  
  
  endtime = time;
//  printf("Z:%d\n",z);

//  while(time<n*2){
  if(z){
//    ans+= time*afor[time/2];
    for(int i=(time/2);i<n;i++){
      ans+= time*a[i];
//      printf("%d %d %d\n",time,a[i],ans);
      time++;
    }
    for(int i=n-1;i>=(endtime/2);i--){
      ans+= time*b[i];
//      printf("%d %d %d\n",time,b[i],ans);
      time++;
    }
    return ans;
  }
  else{
//    ans+=time*bfor[time/2];
    for(int i=(time/2);i<n;i++){
      ans+= time*b[i];
      time++;
    }
    for(int i=n-1;i>=(endtime/2);i--){
      ans+= time*a[i];
      time++;
    }
    return ans;
  }
//  }
}

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int b[n];


  int afor[n];
  int aback[n];
  int bfor[n];
  int bback[n];

  for(int i=0;i<n;i++){
    afor[i] = 0;
    bfor[i] = 0;
    for(int j=i;j<n;j++){
      afor[i]+= a[j];
      bfor[i]+= b[j];
    }
  }

/*
  for(int i=0;i<n;i++){
    printf("%d ",afor[i]);
  }
*/
  for(int i=n-1;i>=0;i--){
    aback[i] = 0;
    bback[i] = 0;
    for(int j=i;j>=0;j--){
      aback[i]+= a[j];
      bback[i]+= b[j];
    }
  }


  getchar();

  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    getchar();
  }

  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
    getchar();
  }

  li max=0;
  li temp;

  li mema[n];
  li memb[n];

  for(int i=0;i<n;i++){
    mema[i] = memb[i] = -1;
  }

  int time = 0;
  for(int i=0;i<n;i++){
    max += time*a[i];
    time++;
  }
  for(int i=n-1;i>=0;i--){
    max+= time*b[i];
    time++;
  }


  for(int i=0;i<n-1;i++){
    temp = traversetill(i,n,a,b,mema);
    //printf("%d %d\n",i,temp);
    if (temp>max) max = temp;
  }    
  
  printf("%ld\n",max);
}
