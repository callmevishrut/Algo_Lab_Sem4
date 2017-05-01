#include<stdio.h>
#include<stdlib.h>
#define MAX 150

int minCoins( int a[], int N, int S ){

int set[MAX];
int *min = (int *)malloc(sizeof(int)*(S+1));
int i,j;
for(i=0;i<=S;i++)
    min[i]= MAX;
int k;
min[0]=0;
for(i=1;i<=S;i++)
{
    for(j=0,k=0;j<N;j++,k++)
    {
        if(i>=a[j])
        {
            set[k]=a[j];
            if(min[i-a[j]]+1<min[i])
            min[i] = min[i-a[j]]+1;
        }
    }
}

if(min[S]== MAX)
    return -1;

printf("")
return min[S];
}


int main()
{
    int a[]={10,30,50};
    int size = sizeof(a)/sizeof(a[0]);
    int d = minCoins(a,size,100);
    printf("%d",d);
    return 0;
}
