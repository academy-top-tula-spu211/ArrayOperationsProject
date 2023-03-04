#include <iostream>

using namespace std;

void ArrayPrint(int array[], int size);
void ArrayRotateToLeft(int array[], int size, int steps);
void ArrayRotateToRight(int array[], int size, int steps);
void ArrayReverse(int array[], int size);
void ArrayReverseSubArray(int array[], int size, int index, int subsize);


void ArraySortSelect(int array[], int size);
void ArraySortBubble(int array[], int size);
void ArraySortShacker(int array[], int size);

void ArraySortQuick(int array[], int size);

void ArraySortHeap(int array[], int size);

int main()
{
    srand(time(nullptr));
    
    const int size{ 20 };

    int array[size]{};

    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;

    ArrayPrint(array, size);

    //ArrayRotateToLeft(array, size, 124);
    //ArrayRotateToRight(array, size, 56);

    /*for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }*/
    
    ArraySortQuick(array, size);

    
    ArrayPrint(array, size);

}

template <typename T>
void ArrayPrint(T array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void ArraySortSelect(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (array[minIndex] > array[j])
                minIndex = j;
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void ArraySortBubble(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isSort = true;
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
            {
                isSort = false;
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        if (isSort)
            break;
    }
}

void ArraySortShacker(int array[], int size)
{
    int top = 0;
    int bottom = size - 1;
    bool isSort;

    while (top <= bottom)
    {
        isSort = true;
        for (int i = bottom; i > top; i--)
            if (array[i] < array[i - 1])
            {
                isSort = false;
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        if (isSort)
            break;
        top++;

        isSort = true;
        for (int i = top; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                isSort = false;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        if (isSort)
            break;
        bottom--;
    }

}

void ArrayRotateToLeft(int array[], int size, int steps)
{
    steps %= size; // steps = steps % size;

    for (int step = 0; step < steps; step++)
    {
        int temp = array[0];
        for (int i = 1; i < size; i++)
            array[i - 1] = array[i];
        array[size - 1] = temp;
    }
}

void ArrayRotateToRight(int array[], int size, int steps)
{
    steps %= size;
    for (int step = 0; step < steps; step++)
    {
        int temp = array[size - 1];
        for (int i = size - 2; i >= 0; i--)
            array[i + 1] = array[i];
        array[0] = temp;
    }
}

void ArrayReverse(int array[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}


void SortQuickReq(int array[], int begin, int end)
{
    int pivot = array[(begin + end) / 2];
    int left{ begin };
    int right{ end };

    do
    {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        if (left <= right)
        {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);

    if (begin < right) SortQuickReq(array, begin, right);
    if (left < end) SortQuickReq(array, left, end);
}


void ArraySortQuick(int array[], int size)
{
    SortQuickReq(array, 0, size - 1);
}


void Heapify(int array[], int size, int indexParent)
{
    int indexLeft = 2 * indexParent + 1;
    int indexRight = 2 * indexParent + 2;

    int indexLagest = indexLeft;
    if (indexRight < size && array[indexLagest] < array[indexRight])
        indexLagest = indexRight;

    if (indexLagest < size && array[indexLagest] > array[indexParent])
    {
        swap(array[indexLagest], array[indexParent]);
        Heapify(array, size, indexLagest);
    }
}

void ArraySortHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(array, size, i);

    for (int isize = size - 1; isize >= 0; isize--)
    {
        swap(array[0], array[isize]);
        Heapify(array, isize, 0);
    }
}