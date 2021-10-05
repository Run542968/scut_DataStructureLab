#include<iostream>
using namespace std;
class LList {
private:
	LList* head;        //表头指针
	LList* tail;        //表尾指针
	LList* curr;        //当前元素指针
	int  size;          //链表大小
	
	void removeall() {  //返回空结点到空闲存储区
		while (head != nullptr) {
			curr = head;
			head = head->next;
			delete curr;
	}
	}
public:
	LList* next;
	char element;

	 void print() {  //打印链表内容
		 LList* s=head;
		 cout <<"当前链表有"<<size<<"个元素"<<'\n'<<"链表成员为:" << endl;
		 while (s) {
			 cout << s->element << endl;
			 s = s->next;
		 }
		 s = NULL;
		 delete s;
	 }
	 void initial() {    //初始化链表
		 curr = tail = head = new LList;
			 curr=tail=head=NULL;
		 size = 0;
	 }
	 void clear() {   //清空链表
		 removeall();
		 initial();
	 }
	 //采用尾插入法插入元素
	 void append(const char it) {
		 LList* s;
		 s = new LList;
			 s->element=it;
			 if (head == NULL)
				 curr = head = s;
			 else
			 tail->next = s;
			 tail = s;
			 tail->next = NULL;
			 size++;
			 s = new LList;
			 delete s;
		
	 }
	 //判断链表是否为空
	 void FullorEmpty() {
		 if (size == 0)
			 cout << "当前链表为空" << endl;
		 else
			 cout << "当前链表不为空" << endl;
	 }
	 //输出链表的第i个元素
	 void find() {
		 int m;
		 int i;
		 LList* s=head;
		 cout << "请输入想要输出的元素位置" << endl;
			 cin >> i;
			 if (i <= size && i >= 1)
				 for (m = 1; m <= i; m++) {
					 if (i == m)
						 cout <<"该位置元素为:"<< s->element << endl;
					 s = s->next;
				 }
			 else
				 cout << "超出范围" << endl;
	 }
	 //输出元素的位置
	 void Position() {
		 LList* s=head;
		 char m;
		 int i;
		 cout << "请输入你想查看位置序号的元素" << endl;
		 cin >> m;
		 for (i = 1; i <= size; i++) {
			 if (m == s->element) {
				 cout <<"该元素位置为:"<< i << endl;
				 break;
			 }
			 else
				 s = s->next;
		 }
		 s = NULL;
		 delete s;
	 }
//在第i个位置插入元素
	 void insert() {
		 char m;
		 int  i;
		 int t;
		 LList* s = new LList;
		 cout << "请输入想要插入的元素：" << '\n' << "想要插入的位置：" << endl;
		 cin >> m >> i;
		 s->element=m;
		 for (t = 2; t < i; t++) {
			 if (i <= (size+1))
				 curr = curr->next;
			 else
				 cout << "超出范围" << endl;
		 }
		 cout << curr->element;
		 if (i == 1) {
			 s->next = head;
			 head = s;
			 size++;
		 }
		 else
			 if (i == (size+1)) {
				 tail->next = s;
				 tail = tail->next;
				 tail->next = nullptr;
				 size++;
			 }
			 else
			 {
				 s->next = curr->next;
				 curr->next = s;
				 size++;
			 }
		 s = NULL;
		 delete s;
	 }
	 //删除链表的第i个元素
	 void remove() {
		 int i;
		 int m;
		 curr = head;
		 LList* s=nullptr;
		 cout << "请输入想删除的第i个元素:" << endl;
		 cin >> i;
		 for (m = 2; m < i; m++) {
			 if (i <= size) {
				 curr = curr->next;
			 }
			 else
				 cout << "超出范围" << endl;
		 }		 
		 if (i == 1) {
			 s = head;
			 head = head->next;
		 }
		 else
			 if (i == size) {
				 s = tail;
				 tail = curr;
				 tail->next = nullptr;
			 }
			 else
				 if (i != size)
		 {
			 s = curr->next;
			 curr->next = curr->next->next;
		 }
		 size--;
		 delete s;
	 }
};
int main() {
	LList it;
	it.initial();
	it.append('a');
	it.append('b');
	it.append('c');
	it.append('d'); 
	it.append('e');
	it.print();
	it.FullorEmpty();
	it.find();
	it.Position();
	it.insert();
	it.remove();
	it.print();
}