#pragma once
template <class T1, class T2>
class Pair
{
  private:
    T1 first;
    T2 second;

  public:
    Pair(T1 first, T2 second) : first(first), second(second) {}
    Pair(const Pair<T1, T2>& another)
    {
      this->first = another.GetFirst();
      this->second = another.GetSecond();
    }
    Pair() {}

    public:
      T1 GetFirst() const { return first; }
      T2 GetSecond() const { return second; }
      bool operator == (const Pair<T1, T2> another)
      {
        return this->first == another.GetFirst() && this->second == another.GetSecond();
      }
};