/*
    ring_stack
    Alex Koch 2018

    Last-in-first-out ring stack

    Objects can be continously pushed onto the stack with the last one always
    being on 'top'. Once more ojects than the size of the array can store are pushed 
    onto the stack then the newest elements simply overwrite the oldest.

    In order to extract all the elements in order one must loop over all the elements in order
    a number of times equal to the 'size_' of the stack.
*/

template<typename T> class ring_stack
{
private:
    T * container_;
    uint32_t top_, shift_ increment_;
public:
    ring_stack(unsigned bits) : shift_{ uint32_t(32 - bits) }, 
                                increment_{ uint32_t( pow(2, 32) / pow(2, bits) ) }, 
                                container_{ new T[ uint32_t( pow(2, bits) ) ] } 
                                { 
                                    top_ = increment_; // offset top to 1
                                    container_[0] = nullptr; // set the first element to nullptr so that it can be checked if the array has been filled yet
                                }
    bool empty() { return container_[0] == nullptr && top_ == 1; }
    bool full() { return container_[0] != nullptr; } // Container is filled only once the 0th element has been overwritten via a push() call
    uint16_t size() 
    { 
        if(container_[0] == nullptr)
        {
            return top_ >> shift_;
        }
        return max_size;
    }
    uint32_t max_size() { return pow(32 - shift_, 2); }
    T & top() { return container_[top_ >> increment_]; }
    void push(const T element) 
    {
        container_[top_ >> shift_] = element;
        top_ += increment_;
    }
    // emplace?
    void pop() 
    {
        top_ -= increment_; // Deincrement as this is a LIFO queue
    }
    // swap?
}
