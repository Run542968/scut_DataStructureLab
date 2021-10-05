#include<iostream>
using namespace std;
const int initial = 10;
template <typename E>
class Alist {
private:
	int maxSize;
	int listSize;
	int curr;


public:
	E* Array;
	Alist(int size = initial) {    //Constructor
		maxSize = size;
		listSize = curr = 0;
		Array = new char[maxSize];
	}
	~Alist() {       //Destructor
		delete[] Array;
	}

	//初始化顺序表
	void clear() {
		delete[] Array;
		listSize = curr = 0;
		Array = new E[maxSize];
		listSize = curr = 0;
	}
	//尾插入法插入一个元素
	void append(char m) {
		int i;
		if (listSize < maxSize) {

			Array[listSize] = m;
			listSize++;
			curr++;
		}
			
			else
				cout << "顺序表已满" << endl;
		
}
	//输出顺序表的长度
	void currSize() {
		cout<<"当前顺序表长度为:"<<listSize<< endl;
	}
	//判断顺序表是否为空
	void FullorEmpty() {
		if (listSize == 0)
			cout << "当前顺序表为空" << endl;
		else
			cout << "当前顺序表不为空" << endl;
	}
	//输出顺序表的第i个元素
	void find() {
		int i;
			cout << "请输入想查看的第i个元素：" << endl;
			cin >> i;
			if (i >= 1 && i <= listSize)
				cout << "第"<<i<<"个元素为："<<Array[i - 1] << endl;
			else
				cout << "输入超出顺序表范围" << endl;
	}
	//输出当前元素的位置
	void currposition() {
		cout << "curr位置元素为：" << curr << endl;
	}
	//任意位置插入元素
	void insert() {
		char m;
		int n;
		int i;
		cout << "请输入想插入元素:\n插入的位置:" << endl;
		cin >> m >> n;
		if (n != (curr + 1) && n >= 0 && n <= listSize) {
			for (i = listSize; i >= n; i--) {
				Array[i] = Array[i - 1];
			}
			Array[n - 1] = m;
			listSize++;
			curr++;
		}
		else
			append(m);

	}
	//输出顺序表内容
	void content() {
		int i;
		cout << "当前顺序表内容" << endl;
		for (i = 0; i < listSize; i++) {
			cout << Array[i] << endl;
		}
	}
	//删除顺序表的第i个元素
	void remove(){
		int n;
		int i;
		cout << "请输入删除的元素位置:" << endl;
		cin >>n;
		if (n >= 0 && n <=listSize) {
			for (i = n; i < listSize; i++) {
				Array[i - 1] = Array[i];
			}
			Array[listSize - 1] = NULL;
			listSize--;
			curr--;
		}
		else
			cout << "该位置超出范围" << endl;
	}
	//顺序表延长
	void buildArray2() {
		int i;
        E* Array2;
		Array2 = new char[maxSize+10];
		for (i = 0; i < listSize; i++) {
			Array2[i] = Array[i];
		}
		delete[]Array;
		Array = new char[maxSize];
		}
	
};

	int main() {
		Alist<char> it;
		it.append('a');
		it.append('b');
		it.append('c');
		it.append('d');
		it.append('e');
		it.content();
	    it.currSize();
		it.FullorEmpty();
		it.find();
		it.currposition();
		it.insert();
		it.currSize();
		it.remove();
		it.currSize();
		it.content();
	}