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

	//��ʼ��˳���
	void clear() {
		delete[] Array;
		listSize = curr = 0;
		Array = new E[maxSize];
		listSize = curr = 0;
	}
	//β���뷨����һ��Ԫ��
	void append(char m) {
		int i;
		if (listSize < maxSize) {

			Array[listSize] = m;
			listSize++;
			curr++;
		}
			
			else
				cout << "˳�������" << endl;
		
}
	//���˳���ĳ���
	void currSize() {
		cout<<"��ǰ˳�����Ϊ:"<<listSize<< endl;
	}
	//�ж�˳����Ƿ�Ϊ��
	void FullorEmpty() {
		if (listSize == 0)
			cout << "��ǰ˳���Ϊ��" << endl;
		else
			cout << "��ǰ˳���Ϊ��" << endl;
	}
	//���˳���ĵ�i��Ԫ��
	void find() {
		int i;
			cout << "��������鿴�ĵ�i��Ԫ�أ�" << endl;
			cin >> i;
			if (i >= 1 && i <= listSize)
				cout << "��"<<i<<"��Ԫ��Ϊ��"<<Array[i - 1] << endl;
			else
				cout << "���볬��˳���Χ" << endl;
	}
	//�����ǰԪ�ص�λ��
	void currposition() {
		cout << "currλ��Ԫ��Ϊ��" << curr << endl;
	}
	//����λ�ò���Ԫ��
	void insert() {
		char m;
		int n;
		int i;
		cout << "�����������Ԫ��:\n�����λ��:" << endl;
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
	//���˳�������
	void content() {
		int i;
		cout << "��ǰ˳�������" << endl;
		for (i = 0; i < listSize; i++) {
			cout << Array[i] << endl;
		}
	}
	//ɾ��˳���ĵ�i��Ԫ��
	void remove(){
		int n;
		int i;
		cout << "������ɾ����Ԫ��λ��:" << endl;
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
			cout << "��λ�ó�����Χ" << endl;
	}
	//˳����ӳ�
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