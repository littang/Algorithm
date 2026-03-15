/*省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
输入
测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M ( < 100 )；随后的 N
行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。
输出
对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
样例输入 Copy
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
样例输出 Copy
3
?*/

#include<stdio.h>

typedef struct{
    int s,e,c;
}road;
road a[5050];
int father[110];

void sortf(int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].c>a[j+1].c){
                road te=a[j];
                a[j]=a[j+1];
                a[j+1]=te;
            }
        }
    }
}

int find (int x){
    if(father[x]!=x){
        father[x]=find(father[x]);
    }
    return father[x];
}

void emerge(int r1,int r2){
    father[r2]=r1;
}

int main(){
int n,m;
    while(scanf("%d",&n)!=EOF&&n!=0){
        scanf("%d",&m);
    
        for(int i=0;i<m;i++){
            father[i]=i;
        }
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
        }
        sortf(n);
        int sum=0;
        int num=0;
        for(int i=0;i<n;i++){
            int s1=a[i].s;
            int e1=a[i].e;
            if(father[s1]!=father[e1]){
                emerge(s1,e1);
                sum+=a[i].c;
                num++;
            }
            if(num==m-1)break;
        }
        if(num==m-1)printf("%d\n",sum);
        else printf("?\n");
    }
    return 0;
}