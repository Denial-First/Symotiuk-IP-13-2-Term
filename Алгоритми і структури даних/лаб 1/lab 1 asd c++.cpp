
#include <iostream>
using namespace std;

void worst_bubble(int size, int* count_swaps, int* count_comps);
void best_bubble(int size, int* count_swaps, int* count_comps);
void output_stats(int count_swaps, int count_comps);
void sort_bubble(int size, int* count_swaps, int* count_comps, int els);
void sort_comb(int size, int* count_swaps, int* count_comps, int els);
void output_arr(int* arr, int size, int els);
void worst_comb(int size, int* count_swaps, int* count_comps);
void best_comb(int size, int* count_swaps, int* count_comps);

int main()
{
    srand(int(time(NULL)));
    int count_swaps = 0, count_comps = 0, size, els;

    cout << "Enter a number of elements: ";
    cin >> size;
    cout << endl;

    cout << "How many elements of array do you want to display: ";
    cin >> els;

    cout << "BUBBLE SORT:" << endl;
    cout << "The worst occasion: \n";
    worst_bubble(size, &count_swaps, &count_comps);
    output_stats(count_swaps, count_comps);
    cout << endl;

    cout << "The best occasion: \n";
    best_bubble(size, &count_swaps, &count_comps);
    output_stats(count_swaps, count_comps);
    cout << endl;

    cout << "Random occasion: \n";
    sort_bubble(size, &count_swaps, &count_comps, els);
    output_stats(count_swaps, count_comps);
    
    cout << "COMB SORT:" << endl;

    cout << "The worst occasion: \n";
    worst_comb(size, &count_swaps, &count_comps);
    output_stats(count_swaps, count_comps);
    cout << endl;

    cout << "The best occasion: \n";
    best_comb(size, &count_swaps, &count_comps);
    output_stats(count_swaps, count_comps);
    cout << endl;

    cout << "Random occasion: \n";
    sort_comb(size, &count_swaps, &count_comps, els);
    output_stats(count_swaps, count_comps);
}


void worst_bubble(int size, int* count_swaps, int* count_comps)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = size - i;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            *count_comps += 1;
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                *count_swaps += 1;
            }
        }
    }
}

void best_bubble(int size, int* count_swaps, int* count_comps)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            *count_comps += 1;
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                *count_swaps += 1;
            }
        }
    }
}

void output_stats(int count_swaps, int count_comps)
{
    cout << "Number of comparisons: " << count_comps << endl;
    cout << "Number of swaps: " << count_swaps << endl;
}

void sort_bubble(int size, int *count_swaps, int* count_comps, int els)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];
    
    for (int i = 0; i < size; i++)
        arr[i] = rand();

    cout << "Unsorted array: ";
    output_arr(arr, size, els);
    cout << endl;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            *count_comps += 1;
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                *count_swaps += 1;
            }
        }
    }
    
    cout << "Sorted array: ";
    output_arr(arr, size, els);
    cout << endl;
}

void sort_comb(int size, int* count_swaps, int* count_comps, int els)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand();

    cout << "Unsorted array: ";
    output_arr(arr, size, els);
    cout << endl;

    int step = size - 1;
    while (step >= 1)
    {
        for (int i = 0; i < size - step; i++)
        {
            *count_comps += 1;
            if (arr[i + step] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                *count_swaps += 1;
            }
        }
        step /= 1.247;
    }

    cout << "Sorted array: ";
    output_arr(arr, size, els);
    cout << endl;
}

void worst_comb(int size, int* count_swaps, int* count_comps)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = size - i;
    int step = size - 1;
    while (step >= 1)
    {
        for (int i = 0; i < size - step; i++)
        {
            *count_comps += 1;
            if (arr[i + step] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                *count_swaps += 1;
            }
        }
        step /= 1.247;
    }
}

void best_comb(int size, int* count_swaps, int* count_comps)
{
    *count_swaps = 0;
    *count_comps = 0;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i;
    int step = size - 1;
    while (step >= 1)
    {
        for (int i = 0; i < size - step; i++)
        {
            *count_comps += 1;
            if (arr[i + step] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                *count_swaps += 1;
            }
        }
        step /= 1.247;
    }
}

void output_arr(int* arr, int size, int els)
{
    for (int i = 0; i < els; i++)
        cout << arr[i] << " ";
    cout << endl;
}
