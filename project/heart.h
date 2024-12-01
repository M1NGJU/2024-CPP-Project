#ifndef HEART_H
#define HEART_H

class Heart {
    int value;

public:
    Heart(int initialValue) : value(initialValue) {}

    int getValue() const { return value; }
    void increase(int amount) { value += amount; }
    void decrease(int amount) { value -= amount; }
};

#endif // HEART_H
