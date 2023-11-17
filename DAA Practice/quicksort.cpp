#include <iostream>
#include <vector>

/*
Worst Case Time complexity: O(n2)

Best Case – This case occurs when the pivot is the middle element or near to middle element of the array.
Recurrence :
F(n) = 2F(n/2)

Time Complexity for the best and average case: O(N*logN)

Space Complexity: O(1) + O(N) auxiliary stack space.

*/

using namespace std;

class QuickSort
{
public:
    int partition(vector<int> &arr, int lo, int hi)
    {
        int pivot = arr[lo];
        int i = lo, j = hi;

        while (i < j)
        {
            while (arr[i] <= pivot && i <= hi - 1)
                i++;
            while (arr[j] > pivot && j >= lo + 1)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[lo], arr[j]);
        return j;
    }

    void qs(vector<int> &arr, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int pivotIndex = partition(arr, lo, hi);
        qs(arr, lo, pivotIndex - 1);
        qs(arr, pivotIndex + 1, hi);
    }

    vector<int> quickSort(vector<int> arr)
    {
        qs(arr, 0, arr.size() - 1);
        return arr;
    }

    QuickSort(vector<int> arr)
    {
        int n = arr.size();
        cout << "Before Using quick Sort: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr = quickSort(arr);
        cout << "After Using quick sort: "
             << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    QuickSort obj = QuickSort(arr);
    return 0;
}