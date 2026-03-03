#include<stdio.h>
int array[10];
int a[10];
void print(int aa[10]){
  for(int i=0;i<10;i++){
    if(aa[i]!=0){
      printf("%5d",aa[i]);
    }
  }
  printf("\n");
  return;
}
void dfs(int n,int k){
  if(k==n){
    print(array);
  }
  for(int i=1;i<=n;i++){
    if(a[i]==0){
      array[k]=i;
      a[i]=1;
      dfs(n,k+1);
      a[i]=0;
    }
  }
}
int main(){
  int n;
  scanf("%d",&n);
  dfs(n,0);
  getchar();
  getchar();
  return 0;
}