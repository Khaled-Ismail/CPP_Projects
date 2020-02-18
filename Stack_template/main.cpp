#include <iostream>

using namespace std;

template <class T>
class stack{
	int size;
	T * stk;
	int topElementIdx;

public:
	stack(int size){
		this->size = size;
		stk = new T[size];
		topElementIdx = -1;
	}

	T pop(){
		if(topElementIdx < 0)
			throw "Stack Underflow!";
		return stk[topElementIdx--];
	}

	void push(T element){
		if (topElementIdx == size - 1)
			throw "Stack Overflow!";
		stk[++topElementIdx] = element;
	}

	void displayStk(){
		for(int i = topElementIdx; i >= 0 ; i--){
			cout << stk[i] << " ";
		}
		cout << endl;
	}

	void dispaly(){
		cout << "Stack size: "<< size << endl <<
				"Top element position: "<< topElementIdx + 1 << endl <<
				"Stack occupation percentage: " << ((topElementIdx + 1) / (float) size) * 100 << "%"<< endl <<
				"Stack Elements, Top -> Bottom:" << endl;
				displayStk(); ;
	}
};

int main(){

	int size = 5;

	stack<int> s(size);

	try{
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		s.push(6);
		s.push(5);
	}
	catch(string s){
		cout << "Error: " << s << endl;
	}
	s.dispaly();


	return 0;
}

