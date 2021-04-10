#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
template <class T>
class SortedType
{
    struct Node
    {
        T info;
        Node *next;
    };

public:
    SortedType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(T);
    void DeleteItem(T);
    void RetrieveItem(T &, bool &);
    void ResetList();
    void GetNextItem(T &);

private:
    Node *info;
    int length;
    Node *currentLocation;
};
#endif // SORTEDTYPE_H_INCLUDED