#include<stdio.h>
int a[40];
void quik_sort(int left,int right,int mid){
    int i=left,j=right;
    int p=a[mid];
    if(i>=j)return ;
    while(i<=j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        //这里不用写等号
        if(i<=j){
            //这里要写等号，让i,j在到了a[mid]之后能继续错开
            int swap=a[i];
            a[i]=a[j];
            a[j]=swap;
            i++;j--;
            //这里要注意，i,j,还要继续移动的！！
        }
    }
    if(left<j)quik_sort(left,j,(left+j)/2);
    if(right>i)quik_sort(i,right,(i+right)/2);
    //这里的if判断是为了确保交换发生在至少两个数之间
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quik_sort(0,n-1,(n-1)/2);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}