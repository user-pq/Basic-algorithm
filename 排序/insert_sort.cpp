/**
插入排序：
N个数
0 - 0 有序
0 - 1 有序 如果0位置大于1位置，交换位置
0 - 2 有序 此时0-1有序，位置2属于新增数， 判断位置2与1位置大小，位置1大于2则交换位置，交换后位置1大于位置0，则位置1和位置0交换位置
..
..
0 - N-1 有序 此时0-N-1有序  N位置属于新增数 如果N-1位置存在数且小于N位置的数 交换！
直到 0 - N-1 有序
*/

#include <iostream>


void Swap(int &a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Print(const int *arr, const int& num)
{
    for(int i=0; i<num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertSort(int *arr, const int& num)
{
    if(arr == NULL || num < 2)
    {
        return ;
    }
    else
    {
        for(int i=0; i < num; i++)
        {
            int new_num_index = i; 
            while(new_num_index - 1 >=0 && arr[new_num_index - 1] > arr[new_num_index])
            {
                Swap(arr[new_num_index - 1], arr[new_num_index]);
                new_num_index--;
            }
        }
    }
}

int main()
{
    int arr[10] = {5,3,1,6,7,8,4,9,0,2};
    Print(arr, 10);
    InsertSort(arr,10);
    Print(arr,10);
    return 0;
}