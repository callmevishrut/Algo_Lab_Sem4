
#include<iostream>
using namespace std;
int main()
{
    int ar[2][100], n, w, i, curw, used[100], maxi = -1, totalprofit = 0;
    //input number of objects
    cout << "Enter number of objects: ";
    cin >> n;
    //input max weight of knapsack
    cout << "Enter the weight of the knapsack: ";
    cin >> w;
    /* ar's first row is to store weights
     second row is to store profits */
    for (i = 0; i < n; i++)
    {
        cout<<"Please enter the weight of "<<i+1<<"th object\n";
        cin >> ar[0][i];
        cout<<"Please enter the profit of "<<i+1<<"th object\n";
        cin >> ar[1][i];
    }
    for (i = 0; i < n; i++)
    {

        used[i] = 0;
    }
    curw = w;
    //loop until knapsack is full
    while (curw >= 0)
    {
        maxi = -1;
        //loop to find max profit object
        for (i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((maxi == -1) || (((float) ar[1][i]
                    / (float) ar[0][i]) > ((float) ar[1][maxi]
                    / (float) ar[0][maxi]))))
            {
                maxi = i;
            }
        }
        used[maxi] = 1;
        //decrease current wight
        curw -= ar[0][maxi];
        //increase total profit
        totalprofit += ar[1][maxi];
        if (curw >= 0)
        {
            cout << "\nAdded object " << maxi + 1 << " Weight: "
                    << ar[0][maxi] << " Profit: " << ar[1][maxi]
                    << " completely in the bag, Space left: " << curw;
        }
        else
        {
            cout << "\nAdded object " << maxi + 1 << " Weight: "
                    << (ar[0][maxi] + curw) << " Profit: "
                    << (ar[1][maxi] / ar[0][maxi]) * (ar[0][maxi]
                            + curw) << " partially in the bag, Space left: 0"
                    << " Weight added is: " << curw + ar[0][maxi];
            totalprofit -= ar[1][maxi];
            totalprofit += ((ar[1][maxi] / ar[0][maxi]) * (ar[0][maxi]
                    + curw));
        }
    }
    //print total worth of objects filled in knapsack
    cout << "\nBags filled with objects worth: " << totalprofit;
    return 0;
}
