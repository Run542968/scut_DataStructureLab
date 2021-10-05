#include<iostream>
#include<string>
using namespace std;
//学生类
class Student {
private:
	int k;//关键码
	string name;//姓名
	string state;//状态
public:
	Student() {
		k = -1;//-1代表空关键码
		name = " ";//空姓名
		state = "empty";//状态为空
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

//建立哈希表
void buildHashtable(Student *a[], int n) {
	for (int i = 0;i < n;i++) {
		a[i] = new Student();
	}
}
//探查函数P
int p(int k, int i) {
	int perm[10] = { 9,5,7,2,1,0,8,6,4,3 };
	return perm[i-1];
}
//哈希函数
int h(int k) {
	return k % 10;
}
//插入数据
void hashInsert(Student *a[], int k, string name) {
	int home;
	int pos = home = h(k);
	for (int i = 1;a[pos]->getK() != -1;i++) {
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
//检索
void hashSearch(Student *a[], int k) {
	int home;
	int pos = home = h(k);
	for (int i = 1;(k != a[pos]->getK()) && ("empty" != a[pos]->getState());i++) {
		pos = (home + p(k, i)) % 10;
	}
	if (k == a[pos]->getK())
		cout  << "关键值:" << a[pos]->getK() << '\t' << "状态:" << a[pos]->getState() << '\t' << "姓名:" << a[pos]->getName() << endl;
	else cout << "k not in hash table" << endl;
}
//删除
void hashDelete(Student *a[], int k) {
	int home;
	int pos = home = h(k);
	for (int i = 1;(k != a[pos]->getK()) && (-1 != a[pos]->getK());i++) {
		pos = (home + p(k, i)) % 10;
	}
	if (k == a[pos]->getK())
	{
		a[pos]->setK(-1);
		a[pos]->setName(" ");
		a[pos]->setState("tombstone");//设置墓碑

	}
	else cout << "k not in hash table" << endl;

}
int main() {
	Student* student[10];
	cout << "向表中增加元素" << endl;
	buildHashtable(student, 10);
	hashInsert(student, 15, "王二");
	hashInsert(student, 7, "风筝");
	hashInsert(student, 22, "李四");
	hashInsert(student, 17, "张三");
	hashInsert(student, 897, "麻子");
	hashInsert(student, 27, "判官");
	cout << "当前哈希表(-1代表该位置为空)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "第" << i << "个槽位:" << '\t' << "关键值:" << student[i]->getK() << '\t' << "状态:" << student[i]->getState() << '\t' << "姓名:" << student[i]->getName() << endl;
	}
	cout << "删除关键码为17的张三" << endl;
	hashDelete(student, 17);
	cout << "当前哈希表(-1代表该位置为空)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "第" << i << "个槽位:" << '\t' << "关键值:" << student[i]->getK() << '\t' << "状态:" << student[i]->getState() << '\t' << "姓名:" << student[i]->getName() << endl;
	}
	cout << "检索关键码为27的判官" << endl;
	hashSearch(student, 27);
	cout << "当前哈希表(-1代表该位置为空)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "第" << i << "个槽位:" << '\t' << "关键值:" << student[i]->getK() << '\t' << "状态:" << student[i]->getState() << '\t' << "姓名:" << student[i]->getName() << endl;
	}
}