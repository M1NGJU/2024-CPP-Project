#ifndef HEART_H
#define HEART_H

class Heart {
private:
    int value;

public:
    Heart(int initialValue = 50) : value(initialValue) {}

    void increase(int amount) {
        value += amount;
    }

    void decrease(int amount) {
        value -= amount;
    }

    int getValue() const {
        return value;
    }
};

#endif
