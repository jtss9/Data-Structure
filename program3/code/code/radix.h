#include "quick.h"
#include <math.h>

class radix {
public:
    radix(vector<int> v_) : v(v_) {
        // maybe ?
        int max = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > max)    max = v[i];
        }
        while (max) {
            max_digit++;
            max /= 10;
        }
    }

    vector<int> sort() {
        // TODO
        //First-pass:
        for (int i = 0; i < v.size(); i++) {
            int units = v[i] % 10;
            box[units].push_back(v[i]);
        }
        new_v();
        clear_box();

        //Second-pass:
        if (max_digit == 1) return v;
        for (int i = 0; i < v.size(); i++) {
            int tens = (v[i] / 10) % 10;
            box[tens].push_back(v[i]);
        }
        new_v();
        clear_box();

        //Third-pass:
        if (max_digit == 2) return v;
        for (int i = 0; i < v.size(); i++) {
            int hundreds = v[i] / 100;
            box[hundreds].push_back(v[i]);
        }
        new_v();
        clear_box();

        return v;
    }

    vector<int> sort_print() {
        // TODO
        //First-pass:
        cout << "First-pass:\n";
        for (int i = 0; i < v.size(); i++) {
            int units = v[i] % 10;
            box[units].push_back(v[i]);
        }
        new_v();
        print_format();
        clear_box();

        //Second-pass:
        if (max_digit == 1) return v;
        cout << "Second-pass:\n";
        for (int i = 0; i < v.size(); i++) {
            int tens = (v[i] / 10) % 10;
            box[tens].push_back(v[i]);
        }
        new_v();
        print_format();
        clear_box();

        //Third-pass:
        if (max_digit == 2) return v;
        cout << "Third-pass:\n";
        for (int i = 0; i < v.size(); i++) {
            int hundreds = v[i] / 100;
            box[hundreds].push_back(v[i]);
        }
        new_v();
        print_format();
        clear_box();

        return v;
    }

    // 可任意新增需要的 member funciton
    void new_v() {
        v.clear();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < box[i].size(); j++) {
                v.push_back(box[i][j]);
            }
        }
    }
    void clear_box() {
        for (int i = 0; i < 10; i++) {
            box[i].clear();
        }
    }

    void print_format() {
        for (int i = 0; i < 10; i++) {
            cout << i << " |";
            for (int j = 0; j < box[i].size(); j++) {
                cout << " --> " << box[i][j];
            }
            cout << "\n";
        }
        cout << "resulting chain: ";
        print_v();
        cout << "\n";
    }

    void print_v() {
        for (auto vi : v) {
            cout << vi << ",";
        }
        cout << endl;
    }

public:
    vector<int> v;
    // maybe ?
    vector<int> box[10];    //digit 0-9
    int max_digit = 0;
};