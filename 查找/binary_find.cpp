/**
二分查找法（前提：有序数组）
1、实现二分查找法
2、有序数组中找到>=num最左的位置
3、有序数组中找到<=num最右的位置
4、局部最小值问题


*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//1、二分查找
bool BinaryFind(const int *arr, const int& size, const int& num)
{
    int L = 0;
    int R = size - 1;
    while(L <= R)
    {
        int mid = (L + R)/2;
        if(arr[mid] > num)
        {
            R = mid - 1;
        }
        else if(arr[mid] < num)
        {
            L = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

//2、有序数组中找到>=num最左的位置
int MostLeftIndex(const int *arr, const int& size, const int& num)
{
    int index = -1;
    int L = 0;
    int R = size - 1;
    while(L <= R)
    {
        int mid = (L + R)/2;
        if(arr[mid] >= num)
        {
            index = mid;
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return index;
}


//3、有序数组中找到<=num最右的位置
int MostRightIndex(const int *arr, const int& size, const int& num)
{
    int index = -1;
    int L = 0;
    int R = size - 1;
    while(L <= R)
    {
        int mid = (L + R)/2;
        if(arr[mid] <= num)
        {
            index = mid;
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    return index;
}


//4、局部最小值
/*
局部最小
前提：
1、数组是无序的
2、任意两个相邻的位置不相等
场景：
1、 arr[0]   < arr[1]              -->  arr[0]   局部最小  //边界
2、 arr[N-2] > arr[N-1]            -->  arr[N-1] 局部最小  //边界
3、 arr[i-1] > arr[i] < arr[i+1]   -->  arr[i]   局部最小  //中间
*/

int LocalMinIndex(const int*arr, int num)
{   
    if(arr == NULL || num == 0)
    {
        return -1;
    }
    if(num == 1)
    {
        return 0;
    }
    if(num == 2)
    {
        return arr[0] > arr[1] ? 0 : 1;
    }
    if(arr[num - 2] > arr[num - 1])
    {
        return num - 1;
    }
    int result = -1;
    int L = 0;
    int R = num - 1;
    //while(L <= R)   // 当只剩两个数的时候 （L+R）/2 = L   此时 L-1 有问题
    while(L < R-1)    // 保证有三个数
    {
        int mid = (L + R) / 2;
        if(arr[mid] < arr[mid - 1]  && arr[mid] < arr[mid + 1])
        {
            result = mid;
            break;   // 只需要找到一个局部最小值即可
        }
        if(arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid])  // 递减
        {
            L = mid + 1;
        }
        if(arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])  // 递增
        {
            R = mid - 1;   
        }
        else
        {
            R = mid - 1;  //mid 位置是极大值点 随便往哪边都可以
        }
    }
    return result = arr[L] < arr[R] ? L : R;
}

// 创建一个数组发生器
int * MakeArray(const int& max_length, const int& max_value)
{
    srand(time(NULL));
    int value = rand()%max_value;
    int *arr = new int[max_length]; 
    for(int i = 0; i < max_length; i++)
    {
        int temp_value = rand()%max_value;
        if(temp_value != value)
        {
            arr[i] = temp_value;
            value = temp_value;
        }
    }
    return arr;
}

// 数组打印
void Print(const int *arr, const int& num)
{
    for(int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 检查
bool Check(const int *arr, const int& num, const int& index)
{
    if(arr == NULL)
    {
        return index == -1;
    }
    int L = index - 1;
    int R = index + 1;
    bool check_left = L >= 0? arr[L] > arr[index] : true;  
    bool check_right = R <= num? arr[R] > arr[index] : true;

    return check_left && check_right;
}

int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    if(BinaryFind(arr, 10, 8))
    {
        cout << "found!" << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }

    cout << "--------------------------" << endl;

    int arr_most_left[10] = {0,1,1,2,2,2,2,3,4,5};
    int most_num = 2;
    cout << MostLeftIndex(arr_most_left, 10, most_num) << endl;
    cout << MostRightIndex(arr_most_left, 10, most_num) << endl;

    cout << "--------------------------" << endl;


    //创建数组
    int max_length = 100;
    int max_value = 100;
    int *arr_local_min= MakeArray(max_length, max_value);
    int local_min_index = LocalMinIndex(arr_local_min, max_length);
    if(!Check(arr_local_min, max_length, local_min_index))
    {
        Print(arr_local_min, max_length);
        cout << local_min_index << endl;
    }
    else
    {
        cout << "success" << endl;
    }

    return 0;
}