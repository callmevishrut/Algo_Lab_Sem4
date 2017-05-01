#include<iostream>
using namespace std;
int max(int a,int b){if(a>b)return a; else return b; }
int knapsack(int W, int wt[], int val[], int n) // n size of the resulting array , wt ->weight array, val -> value array, W -> capacity of the knapsack
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}
int main()
{
    int q,t,e,v;
    int *val,*wt;
    val=new int[1024];
    wt=new int[1024];
    cout<<"How many object types\n";
    cin>>q;
    t=0;
    e=0;
    do
    {
        cout<<"Enter the value of object "<<t<<"\n";
        cin>>val[t];
        cout<<"Enter the weight of object "<<t<<"\n";
        cin>>wt[t];
        t++;
    }while(t<q);
    do
    {
        cout<<"how many instances more(apart from the one already added) of object "<<e<<"?\n";
        cin>>v;
        while(v>0)
        {
            t++;
            val[t]=val[e];
            wt[t]=wt[e];
            v--;
        }
        e++;
    }while(e<q);
    int w;
    cout<<"\nEnter the capacity of knapsack\n";
    cin>>w;
    int totalprofit = knapsack( w, wt, val, t);
    cout<<"\n\t\tThe total profit which can be earned is :"<<totalprofit;
    return 0;
}










