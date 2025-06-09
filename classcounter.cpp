#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    // پیش افزایش (++prefix)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // پس افزایش (postfix++)
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    // سربارگذاری عملگر <<
    friend ostream& operator<<(ostream& os, const Counter& c) {
        os << c.count;
        return os;
    }
};

int main() {
    Counter c(5);

    cout << "Original: " << c << endl;
    cout << "Prefix ++: " << ++c << endl;
    cout << "After prefix: " << c << endl;
    cout << "Postfix ++: " << c++ << endl;
    cout << "After postfix: " << c << endl;
return 0;
}
