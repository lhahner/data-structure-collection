#include <stdlib.h>
#include <stdio.h>

#define SIZE 14

void heapify(int array[], int i);
void swap(int *a, int *b);
void print(int array[]);

void main()
{
    int array[SIZE] = {13, 10, 8, 5, 32, 11, 3, 19, 22, 24, 8, 30, 31, 17};
    print(array);
    // Build heap (rearrange array)
    for (int i = SIZE; i >= 0; i--)
    {
        heapify(array, i);
    }
    print(array);
}

// heapify by geeksforgeeks
void heapify(int array[], int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < SIZE && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < SIZE && array[r] > array[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, largest);
    }
}

void swap(int *a, int *b)
{
    int *tmp = a;
    *a = *b;
    *b = *tmp;
}

void print(int array[])
{
    printf("--------------------------------------\n");
    int split = (SIZE / 2) - 1;
    int j = 1;
    int largest = 0;
    for (int i = 0; i <= split; i++)
    {
        printf("%d \n", array[i]);

        while (j <= (i + 1) * 2)
        {
            if (j == SIZE)
            {
                return;
            }

            printf("\n %d \n", array[j]);
            j++;
        }
    }
    printf("--------------------------------------\n");
}

/**
 * @todo Swap the largest element on top of the heap tree.
 * @deprecated Recursive version is more efficient.
 */
void ____heapify(int array[])
{
    int *ptr;
    int split = (SIZE / 2) - 1;
    int j = 1;
    int largest = 0;
    for (int i = 0; i <= split; i++)
    {

        while (j <= (i + 1) * 2)
        {
            if (j == SIZE)
            {
                return;
            }
            if (array[i] < array[j] && largest < array[j])
            {
                printf("1. large: %d, index: %d\n", array[j], j);
            }
            else if (array[i] > array[j] && largest < array[i])
            {
                printf("2. large: %d, index: %d\n", array[i], i);
            }
            j++;
        }
    }
}
