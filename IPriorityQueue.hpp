template <class T>
class IPriorityQueue
{
  public:
    virtual T Peek(const size_t i) const      = 0;
    virtual T PeekFirst() const               = 0;
    virtual T PeekLast() const                = 0;
    virtual void Enqueue(T item)              = 0;
    virtual T Dequeue()                       = 0;
};