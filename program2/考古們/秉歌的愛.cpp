#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 26;

int number[maxn];
string code_list[maxn], Data, encode;


struct Node {   
    int id, value;
    Node *lson, *rson;
};

struct cmp {
    bool operator() (Node *a, Node *b) {
        return a -> value > b -> value;
    }
};

void get_encode(Node *cur, string record) {
    if (cur -> id != -1) {
        code_list[cur -> id] = record;
    }
    else {
        get_encode(cur -> lson, record + "0");
        get_encode(cur -> rson, record + "1");
    }
}
 
void decode(Node *root) {
    cout << "decode result:";
    Node *cur = root;
    for (int i = 0; i < encode.size(); i++) {
        if (encode[i] == '0') {
            cur = cur -> lson;
        }
        else {
            cur = cur -> rson;
        }
        if (cur -> id != -1) {
            cout << char(cur -> id + 'a');
            cur = root;
        }
    }
    cout << "\n";
}

void output() {
    cout << "Enter characters: " << Data << "\n";
    cout << "encoding result: ";
    for (int i = 0; i < Data.size(); i++) {
        cout << code_list[ Data[i] - 'a'];
        encode += code_list[ Data[i] - 'a'];
    }
    cout << "\n";
    cout << "code list {\n";
    int WPL = 0;
    for (int i = 0; i < 26; i++) {
        cout << "   " << char (i + 'a') << ": " << code_list[i] << "\n";
        WPL = WPL + code_list[i].size() * number[i];
    }
    cout << "}\n";
    cout << "WPL:" << WPL << "\n";
}

int main() {
    cin >> Data;

    for (int i = 0; i < Data.size(); i++) {
        number[Data[i] - 'a']++;        
    }
    
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (int i = 0; i < 26; i++) {
        if (number[i] == 0) continue;
        Node *leaf = new Node;
        leaf -> value = number[i];
        leaf -> id = i;
        leaf -> lson = leaf -> rson = NULL;
        pq.push(leaf);
    }   

    while (pq.size() > 1) {
        Node *cur = new Node, *a, *b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        cur -> value = a -> value + b -> value;
        cur -> id = -1;
        cur -> lson = a;
        cur -> rson = b;
        pq.push(cur);
    }
    Node *root = pq.top();
    get_encode(root, "");
    output();
    decode(root); 
}
