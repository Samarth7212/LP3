// Write a program for analysis of quick sort by using deterministic and randomized 
// variant

#include <iostream>

class Assignment5
{
public:
    static void print(int arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    static void swap(int i, int j, int arr[])
    {
        if (i != j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    static int partitionInd(int arr[], int start, int end)
    {
        int pivot = arr[start];
        int i = start + 1;
        int j = end;
        while (i < j)
        {
            while (pivot >= arr[i] && i <= end - 1)
            {
                i++;
            }
            while (pivot < arr[j] && j >= start + 1)
            {
                j--;
            }
            if (i < j)
            {
                swap(i, j, arr);
            }
        }
        swap(start, j, arr);
        return j;
    }

    static void quickSort(int arr[], int start, int end)
    {
        if (start < end)
        {
            int pi = partitionInd(arr, start, end);
            quickSort(arr, start, pi - 1);
            quickSort(arr, pi + 1, end);
        }
    }

    static void main()
    {
        int arr[] = {6, 3, 5, 0, 1, 10, 3, -3};
        int length = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, length - 1);
        print(arr, length);
    }
};

int main()
{
    Assignment5 obj;
    obj.main();
    return 0;
}
