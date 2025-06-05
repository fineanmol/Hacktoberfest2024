#include <iostream>
using namespace std;

class Array
{

private:
    int *A;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void create()
    {
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
    }

    // ~Array()
    // {
    //     delete[] A;
    //     cout << "Array destroyed" << endl;
    }

    void Append(struct Array *arr, int x)
    {
        if (arr->length < arr->size)
            arr->A[arr->length++] = x;
    }

    void Insert(struct Array *arr, int index, int x)
    {
        int i;
        if (index >= 0 && index <= arr->length)
        {
            for (i = arr->length; i > index; i--)
                arr->A[i] = arr->A[i - 1];
            arr->A[index] = x;
            arr->length++;
        }
    }

    int Delete(struct Array *arr, int index)
    {
        int x = 0;
        int i;
        if (index >= 0 && index < arr->length)
        {
            x = arr->A[index];
            for (i = index; i < arr->length - 1; i++)
                arr->A[i] = arr->A[i + 1];
            arr->length--;
            return x;
        }
        return 0;
    }

    void shiftArray(int arr[], int n, int k)
    {
        int temp[k];

        // Store the last k elements in a temporary array
        for (int i = n - k, j = 0; i < n; i++, j++)
        {
            temp[j] = arr[i];
        }

        // Shift the remaining elements to the right
        for (int i = n - 1; i >= k; i--)
        {
            arr[i] = arr[i - k];
        }

        // Copy the temporary array to the beginning of the original array
        for (int i = 0; i < k; i++)
        {
            arr[i] = temp[i];
        }
    }
};

int main()
{

    Array arr(10);
    arr.create();
    arr.display();

    return 0;
}
