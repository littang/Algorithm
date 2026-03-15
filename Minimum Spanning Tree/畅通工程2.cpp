/*某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
输入
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
当N为0时，输入结束，该用例不被处理。
输出
对每个测试用例，在1行里输出最小的公路总长度。
样例输入 Copy
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
样例输出 Copy
3
5*/

#include<stdio.h>
#define maxn 110
int parent[maxn];
typedef struct{
    int s,e,l;
}road;

void sortt(road *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j].l>a[j+1].l){
                road temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void orign(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
}

int find (int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unionn(int r1,int r2){
    parent[r2]=r1;
}

int main(){
    int n;
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        int m=n*(n-1)/2;
        road a[m];

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].l);
        }

        sortt(a,m);

        orign(n);

        int sum=0;
        int num=0;

        for(int i=0;i<m;i++){
            int u=a[i].s;
            int v=a[i].e;
            int ru=find(u);
            int rv=find(v);
            if(ru!=rv){
                unionn(ru,rv);
                sum+=a[i].l;
                num++;
                if(num==n)break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
    
}