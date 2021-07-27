#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==============================



// ==============================

void task2() {
    vector<int> arr = { 1, 1, 3, 4, 5, 6, 6, 7, 8, 9, 10 };
    sort(arr.begin(), arr.end());
    int result;
    result = unique(arr.begin(), arr.end()) - arr.begin();
    cout << result;
}

// ==============================

class Card {
public:
    enum suit {
        worms = 'w',
        baptize = 'b',
        peaks = 'p',
        tambourine = 't'
    };
    enum Number {
        two = '2',
        three = '3',
        four = '4',
        five = '5',
        six = '6',
        seven = '7',
        eight = '8',
        nine = '9',
        ten = '10',
        jack = '10',
        queen = '10',
        king = '10',
        ace = '11',
        ace_1 = '1'
    };

    bool map_position{}; // вверх лицом - false, рубашкой - true

    void flip() {
        if (map_position) {
            map_position = false;
        }
        else if (map_position == false) {
            map_position = true;
        }
    }
    int getValue(Number n) {
        return n;
    }
};

class Hand : public Card {
    int h_size{};
public:
    vector<Card> collection;
    void Add(Card c) {
        collection.push_back(c);
    }
    void Clear() {
        collection.clear();
    }
    int getValue(Number n) {
        if (Card::getValue(n) < 10)
            return n;
    }
};

// ==============================

int main()
{
    task2();
}
