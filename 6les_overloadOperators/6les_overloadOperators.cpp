
#include <iostream>
using namespace std;

//class Point {
//    int x;
//    int y;
//
//public:
//    Point()
//    {
//        x = y = 0;
//    }
//
//    Point(int value)
//    {
//        this->x = value;
//        this->y = value;
//    }
//
//    Point(int x, int y)
//    {
//        this->x = x;
//        this->y = y;
//    }
//
//    void print() const {
//        cout << "x: " << x << " / y: " << y << endl;
//    }
//
//    Point plus(const Point& other) const {
//        Point res(this->x + other.x, this->y + other.y);
//        return res;
//    }
//
//    Point minus(const Point& other) const {
//        Point res(this->x - other.x, this->y - other.y);
//        return res;
//    }
//
//    // overloads operator
//    // void operator[symbol operator](){}
//
//#pragma region mathOperands
//
//    Point operator +(const Point& other) const {
//        Point res(this->x + other.x, this->y + other.y);
//        return res;
//    }
//
//    Point operator -(const Point& other) const {
//        Point res(this->x - other.x, this->y - other.y);
//        return res;
//    }
//
//    Point operator *(const Point& other) const {
//        Point res(this->x * other.x, this->y * other.y);
//        return res;
//    }
//
//    Point operator /(const Point& other) const {
//        if (other.x == 0 || other.y == 0) {
//            cout << "Error: division by zero!" << endl;
//            return Point();
//        }
//
//        Point res(this->x / other.x, this->y / other.y);
//        return res;
//    }
//
//#pragma endregion
//
//#pragma region Binary operators
//
//    Point& operator +=(const Point& other) {
//        this->x += other.x;
//        this->y += other.y;
//        return *this;
//    }
//
//#pragma endregion
//
//#pragma region uno operators
//
//    Point operator-() const {
//        return Point(-x, -y);
//    }
//
//    Point& operator =(const Point& other) {
//        if (this != &other) {
//            this->x = other.x;
//            this->y = other.y;
//        }
//        return *this;
//    }
//
//#pragma endregion
//
//#pragma region logic operators
//
//    bool operator >(const Point& other) const {
//        return ((this->x + this->y) > (other.x + other.y));
//    }
//
//    bool operator <(const Point& other) const {
//        return ((this->x + this->y) < (other.x + other.y));
//    }
//
//    bool operator >=(const Point& other) const {
//        return ((this->x + this->y) >= (other.x + other.y));
//    }
//
//    bool operator <=(const Point& other) const {
//        return ((this->x + this->y) <= (other.x + other.y));
//    }
//
//    bool operator ==(const Point& other) const {
//        return ((this->x == other.x) and (this->y == other.y));
//    }
//    bool operator !=(const Point& other) const {
//        //return ((this->x != other.x) or (this->y != other.y));
//        return !(*this == other);
//    }
//
//#pragma endregion
//};



class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int hours,int minutes,int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    explicit Time(int seconds)
    {
         hours = seconds / 3600;
         minutes = seconds / 60 % 60;
         this->seconds = seconds%60;
    }


    Time operator +(const Time& other) {
        Time res(this->timeToSeconds()+other.timeToSeconds());
        return res;
    }
    Time operator -(const Time& other) {
        Time res(this->timeToSeconds()-other.timeToSeconds());
        return res;
    }
    Time operator *(const Time& other) {
        Time res(this->timeToSeconds()*other.timeToSeconds());
        return res;
    }
    Time operator /(const Time& other) {
        if (other.timeToSeconds()==0)
        {
            cout << "dont divide by 0" << endl;
            return Time();
        }
        Time res(this->timeToSeconds()/other.timeToSeconds());
        return res;
    }

    bool operator >(const Time& other) const {
        return ((this->timeToSeconds()) > (other.timeToSeconds()));
            }
    bool operator <(const Time& other) const {
        return ((this->timeToSeconds()) < (other.timeToSeconds()));
            }
    bool operator <=(const Time& other) const {
        return ((this->timeToSeconds()) <= (other.timeToSeconds()));
            }
    bool operator >=(const Time& other) const {
        return ((this->timeToSeconds()) >= (other.timeToSeconds()));
            }
    bool operator ==(const Time& other) const {
                return ((this->timeToSeconds()) == (other.timeToSeconds()));
            }
            bool operator !=(const Time& other) const {
                //return ((this->x != other.x) or (this->y != other.y));
                return (this->timeToSeconds() != other.timeToSeconds());
            }

    void secondsToTime(int time) {
        hours = time / 3600;
        minutes = time / 60 % 60;
        seconds = time % 60;
    }    

    int timeToSeconds()const {
        return hours * 3600 + minutes*60 + seconds;
    }
    void addOneSec() {
        int s= timeToSeconds();
        s=(s+1)%86400;
        secondsToTime(s);
    }
    void print() const {
        if (hours < 10)
            cout << "0";
        cout << hours << ":";

        if (minutes < 10)
            cout << "0";
        cout << minutes << ":";

        if (seconds < 10)
            cout << "0";
        cout << seconds << endl;
    }
};


int main()
{
    Time t1(11, 59, 59);
    Time t2(333);
    //Time t3;

    //t1.print();
    //t1.addOneSec();
    //t1.print();
    //t2.print();
    //t3.print();
    Time fortest1(2, 2, 2);
    Time fortest2(1, 1, 1);

    Time res= fortest1 + fortest2;
    cout << "==============" << endl;
    res.print();
    Time res1 = fortest1 - fortest2;
    cout << "==============" << endl;
    res1.print();
    Time res2 = fortest1 * fortest2;
    cout << "==============" << endl;
    res2.print();
    Time res3 = fortest1 / fortest2;
    cout << "==============" << endl;
    res3.print();
    if (fortest1>fortest2)
    {
        cout << "f1>f2" << endl;
    }  
    cout << "==============" << endl;
    if (fortest1<fortest2)
    {
        cout << "f1<f2" << endl;
    }  
    else
    {
        cout << "f2>f1" << endl;
    }
    cout << "==============" << endl;
    if (fortest1>=fortest2)
    {
        cout << "f1>=f2" << endl;
    }  
    cout << "==============" << endl;
    if (fortest1<=fortest2)
    {
        cout << "f1<=f2" << endl;
    }  
    else
    {
        cout << "f2>=f1" << endl;
    }
    cout << "==============" << endl;
    if (fortest1==fortest2)
    {
        cout << "f1==f2" << endl;
    }  
    else
    {
        cout << "f2!=f1" << endl;
    }
    cout << "==============" << endl;
    if (fortest1!=fortest2)
    {
        cout << "f1!=f2" << endl;
    }  
    else
    {
        cout << "f2==f1" << endl;
    }
    cout << "==============" << endl;












    //int a = 5, b = 4;

    //cout << a + b << endl;
    //cout << a - b << endl;
    //cout << a * b << endl;

    //Point p1(5, 3);
    //Point p2(7, 8);
    //Point res;

    //res = p1 + p2;
    //cout << "res: ";
    //res.print();

    //res = p1 - p2;
    //cout << "res: ";
    //res.print();

    //res = p1 * p2;
    //cout << "res: ";
    //res.print();

    //res = p1 / p2;
    //cout << "res: ";
    //res.print();

    //res = p1.plus(p2);
    //cout << "plus: ";
    //res.print();

    //res = p1.minus(p2);
    //cout << "minus: ";
    //res.print();

    //cout << "point1: ";
    //p1.print();

    //cout << "point2: ";
    //p2.print();

    //p1 += p2;

    //cout << "After += " << endl;

    //cout << "point1: ";
    //p1.print();

    //cout << "point2: ";
    //p2.print();

    //res = -p1;

    //cout << "res: ";
    //res.print();

    //cout << "======================================" << endl;

    //cout << "point1: ";
    //p1.print();

    //cout << "point2: ";
    //p2.print();

    //cout << "res: ";
    //res.print();

    //cout << "======================================" << endl;

    //p1 = p2;

    //cout << "After =" << endl;

    //cout << "point1: ";
    //p1.print();

    //cout << "point2: ";
    //p2.print();

    //cout << "======================================" << endl;

    //if (p1 > p2)
    //    cout << "p1 > p2" << endl;
    //else if (p1 < p2)
    //    cout << "p1 < p2" << endl;
    //else
    //    cout << "p1 = p2" << endl;

    //if (p1 >= p2)
    //    cout << "p1 >= p2" << endl;

    //if (p1 <= p2)
    //    cout << "p1 <= p2" << endl;
    //if (p1 == p2)
    //    cout << "p1 == p2" << endl;
    //else
    //    cout << "p1!=p2" << endl;

    //if (p1 != p2)
    //    cout << "p1 != p2" << endl;
    //else
    //    cout << "p1==p2" << endl;


    return 0;
}
