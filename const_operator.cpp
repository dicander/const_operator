//
// Created by Marcus Dicander on 2021-05-27.
//

#include <iostream>

using namespace std;

struct simple{
    void operator[](int n) {
        cout << "non-const operator called with " << n << endl;
    }
    void operator[](int n) const {
        cout << "const operator called with " << n << endl;
    }
};

struct advanced{
    advanced& operator[](int n) {
        cout << "non-const operator called with " << n << endl;
        return *this;
    }

    const advanced& operator[](int n) const {
        cout << "const operator called with " << n << endl;
        return *this;
    }
};


void first() {
    simple m_widget;
    const simple i_widget;
    m_widget[1];
    i_widget[2];
}

void second() {
    advanced m_adv;
    const advanced i_adv;
    m_adv[3] = m_adv[4];
    m_adv[5] = i_adv[6];
    i_adv[7];
}


int main() {
    first();
    second();
}