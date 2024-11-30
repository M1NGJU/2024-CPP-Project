#ifndef HEART_H
#define HEART_H

class Heart {
private:
    int value;

public:
    Heart(int initial_value = 50) : value(initial_value) {}

    void increase(int amount) {
        value += amount;
    }

    void decrease(int amount) {
        value -= amount;
    }

    int getValue() const {
        return value;
    }

    void setValue(int new_value) {
        value = new_value;
    }
};

#endif