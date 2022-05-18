#include <bits/stdc++.h>

using namespace std;

int maxNum, minNum;
int arr[100];

void maxNumMinNum(int i, int j)
{
    int maxNum1, minNum1 , mid;
    if (i == j)
    {
        maxNum = minNum = arr[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (arr[i] > arr[j])
            {
                maxNum = arr[i];
                minNum = arr[j];
            }
            else
            {
                maxNum = arr[j];
                minNum = arr[i];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxNumMinNum(i, mid);
            maxNum1 = maxNum;
            minNum1 = minNum;
            maxNumMinNum(mid + 1, j);
            if (maxNum < maxNum1)
                maxNum = maxNum1;
            if (minNum > minNum1)
                minNum = minNum1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    // int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxNum = arr[0];
    minNum = arr[0];
    maxNumMinNum(0, n);
    cout << "Max number is:" << maxNum<<endl;
    cout << "Min number is:" << minNum<<endl;
    return 0;
}