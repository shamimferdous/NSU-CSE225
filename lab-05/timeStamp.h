#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

class timeStamp
{
private:
    int second;
    int minute;
    int hour;

public:
    timeStamp();
    timeStamp(int, int, int);
    bool operator==(timeStamp);
    bool operator!=(timeStamp);
    bool operator<(timeStamp);
    bool operator>(timeStamp);
    friend ostream &operator<<(ostream &, timeStamp &);
};

#endif // TIMESTAMP_H_INCLUDED