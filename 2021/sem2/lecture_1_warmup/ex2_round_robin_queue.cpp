#include <array>
#include <initializer_list>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <utility>


template<typename T, int N>
class RoundRobinQueue
{
public:
    RoundRobinQueue() = default;

    RoundRobinQueue(std::initializer_list<T> lst)
    {
        for (const T& t : lst)
            push(t);
    }

    RoundRobinQueue(const RoundRobinQueue&) = default;
    RoundRobinQueue& operator=(const RoundRobinQueue&) = default;

    RoundRobinQueue(RoundRobinQueue&& rhs) noexcept
        : data(std::move(rhs.data))
        , start_ix(rhs.start_ix)
        , final_ix(rhs.final_ix)
    {
        rhs = RoundRobinQueue();
    }

    RoundRobinQueue& operator=(RoundRobinQueue&& rhs) noexcept
    {
        if (this != &rhs)
        {
            data = std::move(rhs);
            start_ix = rhs.start_ix;
            final_ix = rhs.final_ix;

            rhs = RoundRobinQueue();
        }
        return *this;
    }

    ~RoundRobinQueue() = default;

    bool empty() const
    {
        return start_ix == final_ix && !data[start_ix].has_value();
    }

    bool full() const
    {
        return start_ix == final_ix && data[start_ix].has_value();
    }

    T pop()
    {
        if (empty())
            throw std::runtime_error("pop from empty queue");

        T res = std::move(data[start_ix].value());
        data[start_ix].reset();
        start_ix = next_ix(start_ix);
        return res;
    }

    void push(T item)
    {
        if (full())
            throw std::runtime_error("push to full queue");

        data[final_ix].emplace(std::move(item));
        final_ix = next_ix(final_ix);
    }

private:
    static int next_ix(const int ix)
    {
        return (ix + 1) % N;
    }

    std::array<std::optional<T>, N> data;
    int start_ix = 0;
    int final_ix = 0;
};

int main()
{

    try
    {
        RoundRobinQueue<std::string, 3> rrs;
        rrs.push("alesha");
        rrs.push("dobrynia");
        rrs.push("ilya");

        while (true)
            std::cout << rrs.pop() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


