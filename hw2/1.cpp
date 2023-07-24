#include<iostream>
using namespace std;
template<typename T> struct Node
{
	Node<T>* nxt;
	T val;
	Node() {
		nxt = NULL;
	}
};
template<typename T> class Queue {
public:
	int size = 0;
	Node<T>* head, * tail;
	Queue() {
		head = new Node<T>;
		head->nxt = NULL;
		tail = head;
	}
	void push(T val) {
		size++;
		Node<T>* add;
		add = new Node<T>;
		add->val = val;
		add->nxt = NULL;
		tail->nxt = add;
		tail = tail->nxt;
	}
	void pop() {
		if (size == 0)	cout << "Queue Is Empty!!!!!\n";
		else
		{
			cout << "Number " << (head->nxt)->val << " has been popped.\n";
			size--;
			head = head->nxt;
			print();
		}
		
	}
	void front() {
		if (size == 0)	cout << "Queue Is Empty!!!!!\n";
		else cout << "the first element is " << (head->nxt)->val << "\n";
	}
	void back() {
		if (size == 0) cout << "Queue Is Empty!!!!!\n";
		else cout << "the last element is " << tail->val << "\n";
	}
	void size_q() {
		cout << "the size of the queue is " << size << "\n";
	}
	void print() {
		Node<T>* tmp = head;
		if (size == 0)	cout << "Queue Is Empty!!!!!\n";
		else
		{
			cout << "Queue: ";
			while (tmp != tail) {
				cout << (tmp->nxt)->val << " ";
				tmp = tmp->nxt;
			}
			cout << "\n";
		}
	}
};

int main() {
	Queue<int> q;
	cout << "Do what???\n";
	cout << "1. Insert\n2. Pop\n3. Front number\n4. Back number\n5. Size\n6. Print queue\n7. Quit\n\n";
	int flag = 1;
	while (flag) {
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			int m;
			cout << "Insert value: ";
			cin >> m;
			q.push(m);
			q.print();
			break;
		case 2:
			q.pop();
			break;
		case 3:
			q.front();
			break;
		case 4:
			q.back();
			break;
		case 5:
			q.size_q();
			break;
		case 6:
			q.print();
			break;
		case 7:
			flag = 0;
			cout << "Bye bye!!!";
			break;
		default:
			cout << "Please input number 1 to 7 !!!\n";
			break;
		}
		cout << "\n";
	}
}