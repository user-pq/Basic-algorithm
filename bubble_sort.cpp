/**
冒泡排序：
N个数
第一次(0~N-1)：0位置 和 1位置作比较，如果0位置比1位置大，交换位置，1位置和2位置作比较，如果1位置比2位置大，交换位置， 一波下来，最大的将在最后面（N-1位置的数）
第二次(0~N-2)：0位置 和 1位置作比较，如果0位置比1位置大，交换位置，1位置和2位置作比较，如果1位置比2位置大，交换位置， 一波下来，最大的将在最后面（N-2位置的数）
...
...
N==0时结束
*/

#include <iostream>


void Swap(int &a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Print(int *arr, int num)
{
    for(int i=0; i<num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void BubbleSort(int *arr, int num)
{
    if(arr == NULL || num < 2)
    {
        return;
    }
    else
    {
        for(int end = num-1; end >= 0; end--)
        {
            for(int i = 0; i < end; i++)
            {
                if(arr[i] > arr[i+1])
                {
                    Swap(arr[i], arr[i+1]);
                }
            }
        }
    }
}

int main()
{
    int arr[10] = {5,3,1,6,7,8,4,9,0,2};

    Print(arr, 10);
    BubbleSort(arr,10);
    Print(arr,10);
    return 0;
}