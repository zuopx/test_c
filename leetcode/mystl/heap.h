#include <vector>

namespace my
{
    // 优先队列
    template <typename T>
    class PriorityQueue
    {
    public:
        PriorityQueue()
        {
        }

        PriorityQueue(bool reversed)
        {
            this->reversed = reversed;
        }

        ~PriorityQueue()
        {
            m_heap.clear();
        }

        void push(const T &val)
        {
        }

        void pop()
        {
        }

        T top()
        {
        }

        bool empty()
        {
            return m_heap.empty();
        }

        size_t size()
        {
            return m_heap.size();
        }

        void clear()
        {
            m_heap.clear();
        }

    private:
        Heap<T> m_heap;
        bool reversed = false;
    };

    template <typename T>
    class Heap
    {
    public:
        Heap()
        {
        }

        Heap(bool reversed)
        {
            this->reversed = reversed;
        }

        ~Heap()
        {
            vector.clear();
        }

        void push(const T &val)
        {
            vector.push_back(val);
        }

        void pop()
        {
            if (vector.size() == 1)
            {
                vector.clear();
                return;
            }

            std::swap(vector.front(), vector.back());
            vector.pop_back();
        }

        T top()
        {
            return vector[0];
        }

        bool empty()
        {
            return vector.empty();
        }

        size_t size()
        {
            return vector.size();
        }

        void clear()
        {
            vector.clear();
        }

        bool cmp(const T &a, const T &b)
        {
            return reversed ? a > b : a < b;
        }

    private:
        std::vector<T> vector;
        bool reversed = false;
    };
}