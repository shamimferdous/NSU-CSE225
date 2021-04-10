#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED
const int max_items = 10;

class FullStack
{
};

class EmptyStack
{
};
template <class T>
class StackType
{

private:
    int top;
    T info[max_items];

public:
    StackType();
    bool isFull();
    bool isEmpty();
    void Push(T);
    void Pop();
    T Top();
};

#endif // STACKTYPE_H_INCLUDED