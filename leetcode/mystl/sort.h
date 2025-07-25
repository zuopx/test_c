#include <vector>

namespace my
{
    template <typename T>
    void quicksort(std::vector<T> &nums)
    {
        /*
        最原始朴素的双指针分区法
        auto _partition = [&](int left, int right) -> int
        {
            int pivot = left;

            while (left < right - 1)
            {
                while (left < right - 1 && nums[left] <= nums[pivot])
                    left++;
                while (left < right - 1 && nums[right - 1] >= nums[pivot])
                    right--;
                if (left < right - 1 && nums[left] > nums[pivot] && nums[right - 1] < nums[pivot])
                    std::swap(nums[left], nums[right - 1]);
            }

            left = pivot;
            while (left < right - 1 && nums[left] <= nums[pivot])
                left++;

            if (nums[left] > nums[pivot])
            {
                std::swap(nums[left - 1], nums[pivot]);
                return left - 1;
            }
            else
            {
                std::swap(nums[left], nums[pivot]);
                return left;
            }
        };
        */

        // 双指针分区，较难理解，核心点在于理解 空位的使用
        auto _partition = [&](int left, int right) -> int
        {
            // 选择左端元素作为基准值，同时将left视为空位
            T pivot = nums[left];

            // 双指针向中间移动，将数组分为两部分
            while (left < right)
            {
                // 从右向左找到第一个小于基准值的元素
                while (left < right && nums[right] >= pivot)
                {
                    --right;
                }
                // 退出循环时，要么nums[right] < pivot，要么right == left（空位）；总之right右侧的元素都大于等于pivot

                // 将找到的小元素放到左端空位，此时right为空位
                nums[left] = nums[right];

                // 从左向右找到第一个大于基准值的元素
                while (left < right && nums[left] <= pivot)
                {
                    ++left;
                }
                // 退出循环时，要么nums[left] > pivot，要么left == right（空位）；总之left左侧的元素都小于等于pivot

                // 将找到的大元素放到右端空位，此时left为空位
                nums[right] = nums[left];
            }

            // 将基准值放到正确的位置
            nums[left] = pivot;

            return left;
        };

        std::function<void(int, int)> _quicksort;
        _quicksort = [&](int left, int right)
        {
            if (right - left < 1)
                return;
            int pivot = _partition(left, right);
            _quicksort(left, pivot - 1);
            _quicksort(pivot + 1, right);
        };

        _quicksort(0, nums.size() - 1);
    };

    /*
    template <typename T>
    void quicksort(std::vector<T> &nums)
    {
        // 单指针分区，较易理解
        auto _partition = [&](int left, int right) -> int
        {
            // 选择左边界元素作为基准值
            T pivot = nums[left];

            // 遍历分区范围内的所有元素
            for (int i = left + 1; i < right; i++)
            {
                // 将小于基准值的元素移动到左侧
                if (nums[i] < pivot)
                {
                    nums[left] = nums[i];
                    left++; // left始终作为一个空位，left左侧的元素都小于pivot
                    // 当nums[i]小于pivot时，将nums[i]放到left位置，left向右移动一位
                    // 这个时候i成了空位，通过将nums[left]放到i位置，于是left又成了空位
                    // left永远小于或等于i：i都起始值比left大；每循环一次，i都加1，而left不一定会加
                    nums[i] = nums[left];
                }
            }

            // 将基准值放到正确的位置
            nums[left] = pivot;
            return left;
        };

        std::function<void(int, int)> _quicksort;
        _quicksort = [&](int left, int right)
        {
            if (right - left < 2)
                return;
            int pivot = _partition(left, right);
            _quicksort(left, pivot);
            _quicksort(pivot + 1, right);
        };

        _quicksort(0, nums.size());
    };
    */

    template <typename T>
    void insertsort(std::vector<T> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--)
            {
                std::swap(nums[j], nums[j - 1]);
            }
        }
    };

    template <typename T>
    void heapsort(std::vector<T> &nums)
    {
        std::function<void(int, int)> heapify;
        heapify = [&](int i, int end)
        {
            int left = i * 2 + 1, right = i * 2 + 2;

            int largest = i;
            if (left < end && nums[left] > nums[i])
                largest = left;
            if (right < end && nums[right] > nums[largest])
                largest = right;

            if (largest != i)
            {
                std::swap(nums[i], nums[largest]);
                heapify(largest, end);
            }
        };

        int end = nums.size();
        for (int i = end / 2; i >= 0; i--)
            heapify(i, end);
        for (int i = end - 1; i >= 0; i--)
        {
            std::swap(nums[0], nums[i]);
            heapify(0, i);
        }
    };
}