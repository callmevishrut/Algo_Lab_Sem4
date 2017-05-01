/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package insertionsort;

import java.io.*;
 
 
class InsertionSort {
 
     
 
    public static void main(String[] args) {
 
            String inpstring = "";
            InputStreamReader input = new InputStreamReader(System.in);
            BufferedReader reader = new BufferedReader(input);
 
            try
            {
                  System.out.print("Enter a Number Elements for INSERTION SORT:");
                  inpstring = reader.readLine();
 
                  long max = Long.parseLong(inpstring);
                  long[] arrElements = new long[100];
                  for (int i = 0; i < max; i++)
                  {
                        System.out.print("Enter [" + (i + 1) + "] Element: ");
                        inpstring = reader.readLine();
                        arrElements[i] = Long.parseLong(inpstring);
                  }
                 
 
                  for(int i = 1; i < max; i++)
                  {
                        int j = i;
                        while(j > 0)
                        {
                              if(arrElements[j-1] > arrElements[j])
                              {
                                    long temp = arrElements[j - 1];
                                    arrElements[j - 1] = arrElements[j];
                                    arrElements[j] = temp;
                                    j--;
                              }
                              else
                                    break;
                        }
      
                        System.out.print("After iteration " + i + ": ");
                        for(int k = 0; k < max; k++)
                              System.out.print(arrElements[k] + " ");
 
                        System.out.println("/*** " + i + " numbers from the begining of the array are input and they are sorted ***/");
                  }
 
 
                  System.out.println("The numbers in ascending orders are given below:");
                  for (int i = 0; i < max; i++)
                  {
                        System.out.println(arrElements[i]);
                  }
 
            }
            catch (Exception e)
            {
                  e.printStackTrace();
            }
    }
}