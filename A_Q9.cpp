/*#include<iostream>
using namespace std;

int countzero(int ar[3][3],int r,int c)
{
    int count = 0;
    int i,j=0;
    while((i<r) && (j<c))
    {
        if(ar[i][j] < 0)
            j++;
        else if(ar[i][j]>0)
            i++;
        else
        {
            int k = i;
            while((k < r) && ar[k][j]==0)
            {
                count++;
                k++;


            }
            j++;
        }
    }
    return count;
}

int main()
{
        int ar[3][3]={{-3,0,4},{-2,-1,0},{0,0,1}};
        int row = 3;
        int col = 3;
        int c = countzero(ar,row,col);
        cout<<"The total no. of zeros in the above array is "<<c;
        return 0 ;
}
*/
#include <stdio.h>
#define R 4
#define C 4
static int max = -1;
/* A function to find the index of first index of 1 in a boolean array arr[] */
int first(bool arr[], int low, int high)
{   if(high >= low)
{     // get the middle index
    int mid = low + (high - low)/2;
    // check if the element at middle index is first 1
    if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
    return mid;
    // if the element is 0, recur for right side
    else if (arr[mid] == 0)
    return first(arr, (mid + 1), high);
    else // If element is not first 1, recur for left side
    return first(arr, low, (mid -1));   }
    return -1; }
     // The main function that returns index of row with maximum number of 1s.
      int rowWithMax1s(bool mat[R][C])
      {     int max_row_index = 0;// Initialize max values
      // Traverse for each row and count number of 1s by finding the index
      // of first 1
      int i, index;
      for (i = 0; i < R; i++)
      {        index = first (mat[i], 0, C-1);
      if (index != -1 && C-index > max)
      {            max = C - index;
      max_row_index = i;
      }
      }       return max; }
      /* Driver program to test above functions */
      int main()
      {     bool mat[R][C] = { {0, 0, 0, 1},         {0, 1, 1, 1},         {1, 1, 1, 1},         {0, 0, 0, 0}     };
      printf("NO. of ones in the array %d \n", rowWithMax1s(mat));
      return 0;
      }
