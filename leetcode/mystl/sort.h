#include <vector>

namespace my
{
    template <typename T>
    void quicksort(std::vector<T> &nums)
    {
        auto _partition = [&](int left, int right) -> int
        {
            int pivot = left;

            while (left < right)
            {
                while (left < right && nums[left] <= nums[pivot])
                    left++;
                while (left < right && nums[right - 1] > nums[pivot])
                    right--;
                if (left < right - 1)
                    std::swap(nums[left], nums[right - 1]);
            }

            std::swap(nums[left - 1], nums[pivot]);

            return left - 1;
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
    void heapsort(std::vector<T> &nums) {
    };
}