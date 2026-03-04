#include<stdio.h>

int a[20][20];
int path[20][2];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

void print(int k){
  printf("(%d,%d)",path[0][0]+1,path[0][1]+1);
  for(int i=1;i<=k;i++){
    printf("->(%d,%d)",path[i][0]+1,path[i][1]+1);
  }
  return;
}

void f(int x,int y,int k,int n){
  if(a[x][y]==0){
    path[k][0]=x;
    path[k][1]=y;
    a[x][y]=1;
  }
  int tx,ty;
  for(int i=0;i<n;i++){
    tx=x+dx[i];
    ty=y+dy[i];
    if(tx>=0&&ty>=0&&tx<n&&ty<n&&a[tx][ty]!=1){
      f(tx,ty,k+1,n);
    }
  }
   if(x==n-1&&y==n-1){
    path[k][0]=x;
    path[k][1]=y;
    print(k);
    return;
  }
  return;
}

int main(){
  int n;
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&a[i][j]);
    }
  }


  f(0,0,0,n);
  getchar();
  getchar();
  return 0;
}