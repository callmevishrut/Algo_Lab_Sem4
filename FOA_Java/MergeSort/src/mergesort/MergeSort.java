/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mergesort;
import java.io.*;
import java.util.*;
import java.lang.*;
/**
 *
 * @author 9915103205
 */
public class MergeSort {

 static public void DoMerge(int [] numbers, int left, int mid, int right)
      {
        int [] temp = new int[25];
        int i, left_end, num_elements, tmp_pos;
    
        left_end = (mid - 1);
        tmp_pos = left;
        num_elements = (right - left + 1);
    
        while ((left <= left_end) && (mid <= right))
        {
            if (numbers[left] <= numbers[mid])
                temp[tmp_pos++] = numbers[left++];
            else
                temp[tmp_pos++] = numbers[mid++];
        }
    
        while (left <= left_end)
            temp[tmp_pos++] = numbers[left++];
 
        while (mid <= right)
            temp[tmp_pos++] = numbers[mid++];
 
        for (i = 0; i < num_elements; i++)
        {
            numbers[right] = temp[right];
            right--;
        }
    }
 
    static public void MergeSort_Recursive(int [] numbers, int left, int right)
    {
      int mid;
    
      if (right > left)
      {
        mid = (right + left) / 2;
        MergeSort_Recursive(numbers, left, mid);
        MergeSort_Recursive(numbers, (mid + 1), right);
    
        DoMerge(numbers, left, (mid+1), right);
      }
    }
 
 
    public static void main(String[] args)
      {
        int[] numbers = { 3, 8, 7, 5, 2, 1, 9, 6, 4 };
        int len = numbers.length;
 
        System.out.println("MergeSort By Recursive Method");
        long tStart = System.nanoTime();
        
        MergeSort_Recursive(numbers, 0, len - 1);
        long tEnd = System.nanoTime();
        long tElapsed = tEnd - tStart ;
        for (int i = 0; i < 9; i++)
            System.out.println(numbers[i]);
        System.out.print("The time needed for the merge sort to occur for 9 elements is "+ tElapsed);
    }
}
    /**
     * @param args the command line arguments
     */
   