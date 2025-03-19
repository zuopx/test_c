/*排序是算法之母*/

#include "/home/percy/project/c/test_c/utils.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

template <typename T> class Sort
{
  public:
    virtual vector<T> sort(vector<T> &nums) = 0; // 纯虚函数

    void swap(vector<T> &nums, int i, int j)
    {
        T tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

// 冒泡排序
template <typename T> class BubbleSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        for (int i = nums.size(); i > 1; --i)
        {
            for (int j = 0; j < i - 1; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    this->swap(nums, j, j + 1);
                }
            }
        }

        return nums;
    }
};

// 选择排序
template <typename T> class SelectSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int minIdx = i;
            for (int j = i; j < nums.size(); ++j)
            {
                if (nums[j] < nums[minIdx])
                {
                    minIdx = j;
                }
            }
            this->swap(nums, i, minIdx);
        }

        return nums;
    }
};

// 插入排序
template <typename T> class InsertSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            int j = 0;
            while (j < i && val > nums[j])
            {
                ++j;
            }

            for (int k = i; k > j; --k)
            {
                nums[k] = nums[k - 1];
            }
            nums[j] = val;
        }

        return nums;
    }
};

// 合并排序
template <typename T> class MergeSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        mergeSort(nums, 0, nums.size());
        return nums;
    }

    void mergeSort(vector<T> &nums, int start, int end)
    {
        if (end - start < 2)
        {
            return;
        }

        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        merge(nums, start, mid, end);
    }

    void merge(vector<T> &nums, int start, int mid, int end)
    {
        vector<T> sortNums;
        int i = start, j = mid;
        while (i < mid || j < end)
        {
            if (j >= end || (i < mid && nums[i] < nums[j]))
            {
                sortNums.push_back(nums[i]);
                ++i;
            }
            else
            {
                sortNums.push_back(nums[j]);
                ++j;
            }
        }
        for (i = start; i < end; ++i)
        {
            nums[i] = sortNums[i - start];
        }
    }
};

// 快速排序
template <typename T> class QuickSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        quickSort(nums, 0, nums.size());
        return nums;
    }

    void quickSort(vector<T> &nums, int start, int end)
    {
        if (end - start < 2)
        {
            return;
        }

        int partitionIdx = this->partition(nums, start, end);
        quickSort(nums, start, partitionIdx);
        quickSort(nums, partitionIdx + 1, end);
    }

    int partition(vector<T> &nums, int start, int end)
    {
        int povit = nums[start]; // 选择支点后，把支点置换到start位置

        int i = start + 1;
        int j = start + 1; // 把小于povit的数置换到j之前，j永远表示下一个待检查的数或大于povit的数
        while (i < end)
        {
            if (nums[i] < povit)
            {
                this->swap(nums, i, j);
                ++j;
            }
            ++i;
        }
        this->swap(nums, start, j - 1);
        return j - 1;
    }

    void swap(vector<T> &nums, int i, int j)
    {
        T tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

// 堆排序
template <typename T> class HeapSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
        for (int i = nums.size() / 2 - 1; i >= 0; --i) // 4 -> 1; 5 -> 1
        {
            heapify(nums, nums.size(), i);
        }

        for (int i = nums.size() - 1; i > 0; --i)
        {
            this->swap(nums, 0, i);
            heapify(nums, i, 0);
        }

        return nums;
    }

    void heapify(vector<T> &nums, int len, int i)
    {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < len && nums[left] > nums[largest])
        {
            largest = left;
        }
        if (right < len && nums[right] > nums[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            this->swap(nums, largest, i);
            heapify(nums, len, largest);
        }
    }

    void swap(vector<T> &nums, int i, int j)
    {
        T tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

// 计数排序
template <typename T> class CountSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
    }
};

// 桶排序
template <typename T> class BucketSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
    }
};

// 基数排序
template <typename T> class RadixSort : public Sort<T>
{
  public:
    vector<T> sort(vector<T> &nums)
    {
    }
};

int main(int argc, char const *argv[])
{
    // Sort<int> *s = new BubbleSort<int>();
    // Sort<int> *s = new SelectSort<int>();
    // Sort<int> *s = new InsertSort<int>();
    // Sort<int> *s = new MergeSort<int>();
    // Sort<int> *s = new QuickSort<int>();
    Sort<int> *s = new HeapSort<int>();
    vector<int> nums{11, 18, 4, 16, 17, 5, 20, 19, 8, 6, 2, 3, 14, 15, 9, 1, 7, 12, 13, 10};
    cout << s->sort(nums) << endl;

    if (argc <= 1)
    {
        return 0;
    }

    mt19937 gen = mt19937(random_device()());
    uniform_int_distribution dist(1, 100);
    for (int i = 0; i < 1000; ++i)
    {
        vector<int> vec(dist(gen));

        iota(vec.begin(), vec.end(), 1);
        shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
        s->sort(vec);
        if (!is_sorted(vec.begin(), vec.end()))
        {
            cout << vec << endl;
            exit(1);
        }
    }

    cout << "done!" << endl;
    return 0;
}


/*
以上排序可分为四类：
暴力类：冒泡排序、选择排序、插入排序
分值类：归并排序、快速排序
数据结构类：堆排序
桶类：计数排序、桶排序、基数排序

基数排序 vs 计数排序 vs 桶排序
    这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异：
    基数排序：根据键值的每位数字来分配桶；
    计数排序：每个桶只存储单一键值；
    桶排序：每个桶存储一定范围的数值；
*/
