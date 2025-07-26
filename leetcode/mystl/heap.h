#include <vector>

namespace my
{
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

        void set_reversed(bool reversed)
        {
            this->reversed = reversed;
        }

        void push(const T &val)
        {
            vector.push_back(val);
            int index = vector.size() - 1;
            while (index > 0)
            {
                int parent = (index - 1) / 2;
                if (cmp(vector[index], vector[parent]))
                {
                    std::swap(vector[index], vector[parent]);
                    index = parent;
                }
                else
                {
                    break;
                }
            }
        }

        void pop()
        {
            if (vector.empty())
            {
                return;
            }

            std::swap(vector.front(), vector.back());
            vector.pop_back();

            int index = 0;
            while (index < vector.size())
            {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                int largest = index;
                if (left < vector.size() && cmp(vector[left], vector[largest]))
                    largest = left;
                if (right < vector.size() && cmp(vector[right], vector[largest]))
                    largest = right;
                if (largest != index)
                {
                    std::swap(vector[index], vector[largest]);
                    index = largest;
                }
                else
                {
                    break;
                }
            }
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
            m_heap.set_reversed(reversed);
        }

        ~PriorityQueue()
        {
            m_heap.clear();
        }

        void put(const T &val)
        {
            m_heap.push(val);
        }

        T get()
        {
            T top = m_heap.top();
            m_heap.pop();

            return top;
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
    };
}