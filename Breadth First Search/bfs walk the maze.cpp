#include<stdio.h>
int n;
int a[30][30];  // 扩大数组
int path[30][2];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void print_path(int k){
  for(int i=0;i<k;i++){
    printf("%d,%d->",path[i][0],path[i][1]);  // 修正：正确打印坐标对
  }
  printf("%d,%d\n",path[k][0],path[k][1]);  // 最后一个不加箭头
}

void f(int x,int y,int k){
  path[k][0]=x;
  path[k][1]=y;
  
  if(x==n-1 && y==n-1){  // 修正：从 (0,0) 到 (n-1,n-1)
    print_path(k);
    return;
  }
  
  a[x][y]=0;  // 标记已访问
  
  for(int i=0;i<4;i++){
    int tx=x+dx[i];
    int ty=y+dy[i];
    if(tx>=0 && ty>=0 && tx<n && ty<n && a[tx][ty]==1){  // 判断是否可走
      
      f(tx,ty,k+1);
        a[tx][ty]=1;
        path[k+1][0]=0;
        path[k+1][1]=0;
    }
  }
  
 // a[x][y]=1;  // 回溯恢复
}

int main(){
  scanf("%d",&n);
  
  // 初始化迷宫全部为 1（可走）
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j]=1;
    }
  }
  
  f(0,0,0);
  getchar();
  getchar();
  return 0;
}