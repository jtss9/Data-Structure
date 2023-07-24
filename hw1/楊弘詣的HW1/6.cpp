#include<iostream>
#include<vector>
using namespace std;
class Bag{
	public:
		int variable;
		void push(int a){
			variable=a;
		}
		void dele(){
			variable=0;
		}
};
class Queue: public Bag{
	vector<int> bags;
	public:
		void push(int a){
			bags.push_back(a);
		}
		void pop(){
			bags.erase(bags.begin(),bags.begin()+1);
		}
		int back(){
			return bags.back();
		}
		int front(){
			return bags.front();
		}
		int size(){
			return bags.size();
		}
		bool empty(){
			return bags.empty();
		}
};
int main(){
	return 0;
}
