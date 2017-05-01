#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int abs(int i)
{
    if(i<0)
        return (-1)*i;
    else
        return i;
}

void srch(int ar[],int key,int first,int last)
{   //cout<<"Subtracting the key with every element of the array \n";
    /*int min = ar[0]-key;
    int e;
    int pos = 0;
    for(int i=0;i<size;i++)
    {
        if(min<0)
            min=(-1)*min;
        e= ar[i]-key;
        if(e<min)
        {

        min=e;
        pos = i;
        }

    }
    if(min==0)
    {
        cout<<"the element is present on "<<pos+1<<" position ";
    }
    else
    {
        cout<<"the element is not present in the array \n the nearest element is "<<ar[pos]<<" on "<<pos+1<<" position";
    }

    int mid = (first + last)/2;
    int min = ar[mid]-key;
    int e = ar[mid];
    static int pos=0;
    if(first>last)
    {
        int div = key - e ;
        if(div<min)
            min = div;
        min= abs(min);
        cout<<"The nearest element is "<<e;

    }
    else
    {


            if(e == key)
            {
                cout<<"the element is found in the array";
                return;
            }
            else if(key < e)
            {

                    srch(ar,key,first,mid-1);
            }
            else
                srch(ar,key,mid,last);
    }
    cout<<"\nfunction called\t press enter to continue";
    getch();*/


    int middle,e;
    middle = (first+last)/2;
    int min = ar[first] - key;
    min = abs(min);
    while (first <= last)
    {
      if (ar[middle] < key)
      {
          first = middle + 1;
          e = ar[middle]-key ;
          e = abs(e);
          if(e<min)
            min = e;
      }
      else if (ar[middle] == key)
      {
            printf("%d found at location %d.\n",key, middle+1);
            break;
      }
      else
            last = middle - 1;
            e = ar[middle]-key ;
            e = abs(e);
            if(e<min)
                min = e;

      middle = (first + last)/2;
   }
   if (first > last)
   {
        printf("Not found! %d is not present in the list.\n", key);
        if(abs(key-ar[middle])>abs(key-ar[middle+1]))
            cout<<"Te nearest element is "<<ar[middle+1];
        else
            cout<<"the nearest element is"<<ar[middle];

   }
}
int main()
{   int ar[]={12,23,34,45,56};
    int s = 5;
    int k;
    int f = 0 ;
    int l = s-1;

    cout<<"\nPlz enter a key to be searched:= ";
    cin>>k;

    srch(ar,k,f,l);
    cout<<"\nEnd";
    getch();
}
