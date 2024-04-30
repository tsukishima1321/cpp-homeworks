#include <stdio.h>
#include <stdlib.h>

/**
 * TODO:
 * In this file, you will write two functions:
 *
 * 1. reverse_arr: will take in two inputs a char* array and the number of
 * elements in the array. It's responsible for reversing the input array. You
 * should be modifying this array in place. Meaning that you shouldn't returning
 * anything from this function.
 *
 * 2. swap: will take in two elements from the array and swap them. Returns
 * nothing.
 *
 * Example:
 * Given an array ["hello", "my", "name", "is"], after calling reverse_arr
 * will result in ["is", "name", "my", "hello"]
 */

void swap(char **front, char **end)
{
    char *mid = *front;
    *front = *end;
    *end = mid;
}

void reverse_arr(char **arr, int num)
{
    for (int i = 0; i < num / 2; i++)
    {
        char **front = arr + i;
        char **end = arr + num - i - 1;
        swap(front, end);
    }
}

int main(int argc, char **argv)
{
    int num_elements = atoi(argv[1]);
    char *arr[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        arr[i] = argv[i + 2];
    }

    if (argc == 1)
    {
        int num = 4;
        char *test_arr[4] = {"Hello", "From", "SUSY", "BAKA"};
        for (int i = 0; i < num; i++)
        {
            printf("word: %s\n", test_arr[i]);
        }
        char **arr = &test_arr[0];
        reverse_arr(arr, num);
        for (int i = 0; i < num; i++)
        {
            printf("word: %s\n", test_arr[i]);
        }
    }
    if (argc > 1)
    {
        int num = num_elements;
        char **test_arr = arr;
        for (int i = 0; i < num; i++)
        {
            printf("word: %s\n", test_arr[i]);
        }
        reverse_arr(test_arr, num);
        for (int i = 0; i < num; i++)
        {
            printf("word: %s\n", test_arr[i]);
        }
    }
    system("pause");
}