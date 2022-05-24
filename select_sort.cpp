/***
选择排序
数组： 0 ~ N-1
从 0~N-1 找到一个最小值 放在0位置(与0位置的数交换位置)
从 1~N-1 找到一个最小值 放在1位置(与1位置的数交换位置)
...
从 N-2~N-1 找到一个最小值 放在N-2的位置
*/

#include <iostream>


void Swap(int &a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}


void SelectSort(int *arr, int num)
{
    if(arr == NULL || num < 2)
    {
        return;
    }
    for(int i = 0; i < num; i++)
    {
        int min_value_index = i;  //最小值所在的位置
        for(int j = i + 1; j < num; j++)
        {
            min_value_index = arr[j] < arr[min_value_index] ? j : min_value_index;
        }
        Swap(arr[min_value_index], arr[i]);
    }
}


void Print(int *arr, int num)
{
    for(int i=0; i<num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[10] = {5,3,1,6,7,8,4,9,0,2};

    Print(arr, 10);
    SelectSort(arr,10);
    Print(arr,10);
    return 0;
}