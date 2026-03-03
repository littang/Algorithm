#include<stdio.h>
int a[10][10];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void f(int x,int y,int k,int n){
  a[x][y]=k;
  if(k==n*n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j==0)printf("%d",a[i][j]);
        else printf("\t%d",a[i][j]);
      }
      printf("\n");
    }
  }
  int tx,ty;
  for(int i=0;i<4;i++){
      tx=x+dx[i];
      ty=y+dy[i];
      if(tx>=0&&ty>=0&&tx<n&&ty<n&&a[tx][ty]==0){
        f(tx,ty,k+1,n);
    }
  }
}

int main(){
  int n;
  scanf("%d",&n);
  f(0,0,1,n);
  getchar();
  getchar();
  return 0;
}