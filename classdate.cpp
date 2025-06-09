#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // سربارگذاری عملگر <
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    // سربارگذاری عملگر >
    bool operator>(const Date& other) const {
        return other < *this;
    }

    // سربارگذاری عملگر ==
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // سربارگذاری عملگر <=
    bool operator<=(const Date& other) const {
        return !(*this > other);
    }

    // سربارگذاری عملگر >=
    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    // سربارگذاری عملگر << برای نمایش تاریخ
    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};

int main() {
    Date d1(15, 6, 2023);
    Date d2(20, 6, 2023);

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    if (d1 < d2) {
        cout << "d1 is earlier than d2" << endl;
    } else if (d1 > d2) {
        cout << "d1 is later than d2" << endl;
    } else {
        cout << "d1 and d2 are the same date" << endl;
    }

    return 0;
}
