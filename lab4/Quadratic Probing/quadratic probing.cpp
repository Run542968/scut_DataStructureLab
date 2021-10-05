#include<iostream>
#include<string>
using namespace std;
//ѧ����
class Student {
private:
	int k;//�ؼ���
	string name;//����
	string state;//״̬
public:
	Student() {
		k = -1;//-1����չؼ���
		name = " ";//������
		state = "empty";//״̬Ϊ��
	};
	void setK(int n) {
		k = n;
	}
	int getK() { return k; }
	void setName(string t) {
		name = t;
	}
	string getName() { return name; }
	void setState(string f) {
		state = f;
	}
	string getState() {
		return state;
	}
};

//������ϣ��
void buildHashtable(Student* a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = new Student();
	}
}
//̽�麯��P
int p(int k, int i) {
	return i * i;
}
//��ϣ����
int h(int k) {
	return k % 10;
}
//��������
void hashInsert(Student* a[], int k, string name) {
	int home;
	int pos = home = h(k);
	for (int i = 1; a[pos]->getK() != -1; i++) {
		pos = (home + p(k, i)) % 10;
		if (k == a[pos]->getK())
			cout << "Duplicates not allowed" << endl;
	}
	if (a[pos]->getState() == "tombstone") {
		a[pos]->setK(k);
		a[pos]->setName(name);
		a[pos]->setState("full");
	}
	a[pos]->setK(k);
	a[pos]->setName(name);
	a[pos]->setState("full");
}
//����
void hashSearch(Student* a[], int k) {
	int home;
	int pos = home = h(k);
	for (int i = 1; (k != a[pos]->getK()) && ("empty" != a[pos]->getState()); i++) {
		pos = (home + p(k, i)) % 10;
	}
	if (k == a[pos]->getK())
		cout << "�ؼ�ֵ:" << a[pos]->getK() << '\t' << "״̬:" << a[pos]->getState() << '\t' << "����:" << a[pos]->getName() << endl;
	else cout << "k not in hash table" << endl;
}
//ɾ��
void hashDelete(Student* a[], int k) {
	int home;
	int pos = home = h(k);
	for (int i = 1; (k != a[pos]->getK()) && (-1 != a[pos]->getK()); i++) {
		pos = (home + p(k, i)) % 10;
	}
	if (k == a[pos]->getK())
	{
		a[pos]->setK(-1);
		a[pos]->setName(" ");
		a[pos]->setState("tombstone");//����Ĺ��

	}
	else cout << "k not in hash table" << endl;

}
int main() {
	Student* student[10];
	cout << "���������Ԫ��" << endl;
	buildHashtable(student, 10);
	hashInsert(student, 15, "����");
	hashInsert(student, 7, "����");
	hashInsert(student, 22, "����");
	hashInsert(student, 17, "����");
	hashInsert(student, 897, "����");
	hashInsert(student, 27, "�й�");
	cout << "��ǰ��ϣ��(-1�����λ��Ϊ��)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "��" << i << "����λ:" << '\t' << "�ؼ�ֵ:" << student[i]->getK() << '\t' << "״̬:" << student[i]->getState() << '\t' << "����:" << student[i]->getName() << endl;
	}
	cout << "ɾ���ؼ���Ϊ17������" << endl;
	hashDelete(student, 17);
	cout << "��ǰ��ϣ��(-1�����λ��Ϊ��)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "��" << i << "����λ:" << '\t' << "�ؼ�ֵ:" << student[i]->getK() << '\t' << "״̬:" << student[i]->getState() << '\t' << "����:" << student[i]->getName() << endl;
	}
	cout << "�����ؼ���Ϊ27���й�" << endl;
	hashSearch(student, 27);
	cout << "��ǰ��ϣ��(-1�����λ��Ϊ��)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "��" << i << "����λ:" << '\t' << "�ؼ�ֵ:" << student[i]->getK() << '\t' << "״̬:" << student[i]->getState() << '\t' << "����:" << student[i]->getName() << endl;
	}
}

