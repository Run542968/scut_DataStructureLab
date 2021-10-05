#include<iostream>
using namespace std;
class LList {
private:
	LList* head;        //��ͷָ��
	LList* tail;        //��βָ��
	LList* curr;        //��ǰԪ��ָ��
	int  size;          //�����С
	
	void removeall() {  //���ؿս�㵽���д洢��
		while (head != nullptr) {
			curr = head;
			head = head->next;
			delete curr;
	}
	}
public:
	LList* next;
	char element;

	 void print() {  //��ӡ��������
		 LList* s=head;
		 cout <<"��ǰ������"<<size<<"��Ԫ��"<<'\n'<<"�����ԱΪ:" << endl;
		 while (s) {
			 cout << s->element << endl;
			 s = s->next;
		 }
		 s = NULL;
		 delete s;
	 }
	 void initial() {    //��ʼ������
		 curr = tail = head = new LList;
			 curr=tail=head=NULL;
		 size = 0;
	 }
	 void clear() {   //�������
		 removeall();
		 initial();
	 }
	 //����β���뷨����Ԫ��
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
	 //�ж������Ƿ�Ϊ��
	 void FullorEmpty() {
		 if (size == 0)
			 cout << "��ǰ����Ϊ��" << endl;
		 else
			 cout << "��ǰ����Ϊ��" << endl;
	 }
	 //�������ĵ�i��Ԫ��
	 void find() {
		 int m;
		 int i;
		 LList* s=head;
		 cout << "��������Ҫ�����Ԫ��λ��" << endl;
			 cin >> i;
			 if (i <= size && i >= 1)
				 for (m = 1; m <= i; m++) {
					 if (i == m)
						 cout <<"��λ��Ԫ��Ϊ:"<< s->element << endl;
					 s = s->next;
				 }
			 else
				 cout << "������Χ" << endl;
	 }
	 //���Ԫ�ص�λ��
	 void Position() {
		 LList* s=head;
		 char m;
		 int i;
		 cout << "����������鿴λ����ŵ�Ԫ��" << endl;
		 cin >> m;
		 for (i = 1; i <= size; i++) {
			 if (m == s->element) {
				 cout <<"��Ԫ��λ��Ϊ:"<< i << endl;
				 break;
			 }
			 else
				 s = s->next;
		 }
		 s = NULL;
		 delete s;
	 }
//�ڵ�i��λ�ò���Ԫ��
	 void insert() {
		 char m;
		 int  i;
		 int t;
		 LList* s = new LList;
		 cout << "��������Ҫ�����Ԫ�أ�" << '\n' << "��Ҫ�����λ�ã�" << endl;
		 cin >> m >> i;
		 s->element=m;
		 for (t = 2; t < i; t++) {
			 if (i <= (size+1))
				 curr = curr->next;
			 else
				 cout << "������Χ" << endl;
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
	 //ɾ������ĵ�i��Ԫ��
	 void remove() {
		 int i;
		 int m;
		 curr = head;
		 LList* s=nullptr;
		 cout << "��������ɾ���ĵ�i��Ԫ��:" << endl;
		 cin >> i;
		 for (m = 2; m < i; m++) {
			 if (i <= size) {
				 curr = curr->next;
			 }
			 else
				 cout << "������Χ" << endl;
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