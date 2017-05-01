/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package quicksort;

/**
 *
 * @author 9915103205
 */
public class QuickSort {
    //Last element as the pivot
    int partition(int arr[], int low, int high)
    {   
        int pivot = arr[high];
        int i = (low-1); // index of the smaller element
        for(int j=low;j<=high-1;j++)
        {   //if the current element is smaller than or equal to pivot
            if(arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return i+1;
        
    }
    void sort(int arr[], int low , int high)
    {
        if(low < high)
        {
            int pi = partition(arr, low ,high);
            sort(arr,low,pi-1);
            sort(arr,pi+1,high);
            
        }
    }
    static void printarr(int arr[])
    {
        int n = arr.length;
        for(int i= 0; i <n ; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    
    public static void main(String[] args) {
        int arr[] = {10, 12, 7, 64, 5,1,34,4,21};
        int n = arr.length;
        long tStart = System.nanoTime();
        
         
        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n-1);
        long tEnd = System.nanoTime();
        long tRes = tEnd - tStart;
        
        System.out.print("The time elapsed is "+tRes+"\n");
        System.out.println("sorted array");
        printarr(arr);
    }
}
