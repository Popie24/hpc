#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;


void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

#pragma omp parallel sections
    {
#pragma omp section
        {

            mergeSort(arr, low, mid);
        }
#pragma omp section
        {
            mergeSort(arr, mid + 1, high);
        }
    }
    merge(arr, low, mid, high);
}

void printFunc(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {3, 4, 5, 2, 3, 8, 6, 5, 9, 7, 5, 3, 2, 5, 6, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
   

    cout << "unsorted arr : \n";
    printFunc(arr, len);
    cout << "sorted arr : \n";
	#pragma omp parallel
    {

        mergeSort(arr, 0, len);
    }
  
    printFunc(arr, len);


    return 0;
}
