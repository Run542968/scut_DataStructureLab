#include<iostream>
#include<string>
using namespace std;

class IntNode {//�����ڲ����
public:
	char it;
	int weight;
	string code;
	IntNode* lt;
	IntNode* rt;
};
class HuffTree {//����HuffTree
private:
	int length;
	int size = 0;
public:
	int *str;
	IntNode *element;
	IntNode* root;
	HuffTree() {};
	HuffTree(int len) {
		length = len;
	}
	~HuffTree() {}
	void SetNodeArray() {//�����ֵ������
		element = new IntNode[length];
	}
	void insertNode(char s[], int a[]) {//������ĸ��Ƶ�β������ֵ��
		for (int i = 0; i < length; i++) {
			element[i].it = s[i];
			element[i].weight = a[i];
			element[i].lt = element[i].rt = NULL;
		}
		element[0].code = "010";
		element[1].code = "00";
		element[2].code = "01100";
		element[3].code = "0111";
		element[4].code = "1";
		element[5].code = "01101";
	}
	void create_string() {//�����ַ�����
		str = new int[length];
	}
	void append(int b) {//β���뷨���ַ������в���·��ֵ
			str[size] = b;
			size++;
			for (int i = 0; i < size; i++) {
				cout << str[i]<<" ";
			}
	}

	void print() {//�������Ľӿ�
		cout << "˳���������������" << endl;
		print1(root,8);
		cout <<'\n'<<"���������룺"<< endl;
		print2(root,8);
	}
	void print1(IntNode* root, int b) {//˳�������������
		if (root == NULL)
			return;
				cout<< root->weight<<"  ";
		print1(root->lt, 0);
		print1(root->rt, 1);

	}
	void print2(IntNode *root,int b) {//�ҵ��������������
		if (root== NULL) 
			return;	
		if (root ->it!= NULL) {
			cout<< root->it << ":" <<root->code<< endl;
		}
			print2(root->lt,0);
		print2(root->rt,1);

	}
	void sort() {//����С�����˳������Ƶ��
		IntNode temp;
		int i ;
		for(i=0;i<length;i++)
			for (int j = i; j >0; j--) {
				if(element[j].weight<element[j-1].weight)
				{
					temp = element[j];
					element[j] = element[j - 1];
					element[j - 1] = temp;

				}
			}
	}
	void create_IntNode1() {//�����һ���ڲ����
		IntNode *s;
			s = new IntNode;
			s->weight = element[0].weight + element[1].weight;
			s->lt = &element[0];
			s->rt = &element[1];
			s->it = NULL;
			s->code = " ";
			root = s;
			s = NULL;
			delete s;
	}
	void create_IntNode2() {//���������ڲ���㼰�����
		IntNode* s;
		for (int i = 2; i < length; i++) {
			s = new IntNode;
			s->weight = root->weight + element[i].weight;
			if (root->weight < element[i].weight) {
				s->lt = root;
				s->rt = &element[i];
				s->it = NULL;
				s->code = " ";
			}
			else
			{
				s->rt = root;
				s->lt = &element[i];
				s->it = NULL;
				s->code = " ";
			}

			root = s;
		}
		s = NULL;
		delete s;

	}
	void print3(char a) {//����
		string s1;
		for (int i = 0; i < length; i++) {
			if (element[i].it == a)
				s1 += element[i].code;
		}cout << s1;
	}
	void insert(char b[]) {//�������
		char a;
		int i;
		cout << "������ABCDEF��ɵ�6������" << endl;
			for (i = 0; i < length; i++) {
				cin >> a;
				print3(a);
			}

	}
};
int main() {
	char b[6];
	char s[] = {"ABCDEF"};
	int a[] = {7,9,2,6,32,3};
	HuffTree it(6);
	it.create_string();
	it.SetNodeArray();
	it.insertNode(s,a);
	it.sort();
	it.create_IntNode1();
	it.create_IntNode2();
	it.print();
	it.insert(b);

}