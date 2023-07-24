#include "insertion.h"

class quick {
public:
    quick(vector<int> v_) : v(v_) {}

    vector<int> sort() {
        quick_sort_partation(0, v.size() - 1);
        return v;
    }

    vector<int> sort_print() {
        quick_sort_partation_print(0, v.size() - 1);
        return v;
    }

    void quick_sort_partation_print(int front, int rear) {
        // TODO :
        if (front >= rear)    return;
        int i = front;
        int j = rear;
        int key = v[front];
        cout << i << "-" << j << " : \n";
        while (i != j) {
            while (v[j] > key && i < j) {
                j--;
            }
            while (v[i] <= key && i < j) {
                i++;
            }
            if (i < j) {
                int temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
        v[front] = v[i];
        v[i] = key;
        print_v();
        quick_sort_partation_print(front, i - 1);
        quick_sort_partation_print(j + 1, rear);

        return;
    }

    void quick_sort_partation(int front, int rear) {
        // TODO :
        if (front >= rear)    return;
        int i = front;
        int j = rear;
        int key = v[front];
        while (i != j) {
            while (v[j] > key && i < j) {
                j--;
            }
            while (v[i] <= key && i < j) {
                i++;
            }
            if (i < j) {
                int temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
        v[front] = v[i];
        v[i] = key;
        quick_sort_partation(front, i - 1);
        quick_sort_partation(j + 1, rear);

        return;
    }

    void print_v() {
        for (auto vi : v) {
            cout << vi << ",";
        }
        cout << endl;
    }

public:
    vector<int> v;
};