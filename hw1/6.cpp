#include<iostream>
using namespace std;
template <class T>
class Queue {
public:
	Queue(int size = 10);
	bool IsEmpty();
	bool IsFull();
	int size();
	T& Front();
	T& Rear();
	void Push(T x);
	void Pop();
private:
	T* queue;
	int front, rear, capacity;
	int count;
};

template <class T>
Queue<T>::Queue(int size) {
	if (size < 1) throw "Queue capacity must be >0";
	queue = new T[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template <class T>
int Queue<T>::size() {
	return count;
}

template <class T>
bool Queue<T>::IsEmpty() {
	return (size() == 0);
}

template <class T>
bool Queue<T>::IsFull() {
	return (size() == capacity);
}

template <class T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Underflow!!!!";
	cout << "Removing " << queue[front] << endl;
	front = (front + 1) % capacity;
	count--;
}

template <class T>
void Queue<T>::Push(T item) {
	if (IsFull()) throw "Overflow!!!!";
	cout << "Inserting " << item << endl;
	rear = (rear + 1) % capacity;
	queue[rear] = item;
	count++;
}

template <class T>
inline T& Queue<T>::Front() {
	if (IsEmpty()) throw "IsEmpty!!!";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() {
	if (IsEmpty()) throw "IsEmpty!!!";
	return queue[(rear + 1) % capacity];
}

int main() {
	Queue<string> q(3);
	q.Push("a");
	q.Push("b");
	q.Push("c");

	if (q.IsFull()) cout << "q is full!\n";

	q.Pop();
	q.Pop();

	cout << q.size() << endl;

	q.Pop();
	if (q.IsEmpty()) cout << "q is empty!\n";
	//q.Pop();
}
