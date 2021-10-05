#include<iostream>
#include<string>
using namespace std;

class Data {
private:
	int size = 0;
public:
	int Carnumber;
	string brand;
	string color;
	string model;
	string date;
	Data() {};
	~Data() {};
	//��ʱ��˳������
	void sort(Data A[]) {
		Data temp;
		for (int i = 1; i < size; i++) {
			for (int j = size - 1; j > 0; j--) {
				if (A[j].date < A[j - 1].date)
				{
					temp = A[j];
					A[j] = A[j - 1];
					A[j - 1] = temp;
				}
				
			}
		}
	}
	//����������Ϣ
	void insert(Data A[]) {
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		int test;
		cout << "������������Ϣ:" << endl;
		for (int i = size; i < 50; i++)
		{
			cout << "����0ֹͣ���:" << endl;
			cin >> test;
			if (test == 0)
				break;
			else {
				cout << "�����복�ƺ�:"; cin >> Carnumber;
				cout << "�����복Ʒ��:"; cin >> brand;
				cout << "�����복����ɫ:"; cin >> color;
				cout << "�����복���ͺ�:"; cin >> model;
				cout << "�����복����������:"; cin >>date;
				A[i].Carnumber = Carnumber;
				A[i].brand = brand;
				A[i].color = color;
				A[i].model = model;
				A[i].date = date;
				size++;
			}
		}
	}
	//������������
	void append(Data A[], int Carnumber, string brand, string color, string model, string date, int i) {
		A[i - 1].Carnumber = Carnumber;
		A[i - 1].brand = brand;
		A[i - 1].color = color;
		A[i - 1].model = model;
		A[i - 1].date = date;
		size++;
	}
	//���뱾����Ϣ
	void input(Data it[]) {
		append(it, 1111, "dazhong", "black", "GB1111", "1999.12.10", 1);
		append(it, 1112, "fengtian", "black", "GB1112", "1998.2.10", 2);
		append(it, 1113, "dazhong", "white", "GB1113", "1999.3.7", 3);
		append(it, 1114, "dongfeng", "blue", "GB1114", "1997.7.10", 4);
		append(it, 1115, "hongqi", "green", "GB1115", "1975.1.10", 5);
		append(it, 1116, "sanling", "white", "GB1116", "2000.5.15", 6);
		append(it, 1117, "sanling", "blue", "GB1117", "1999.12.1", 7);
		append(it, 1118, "dazhong", "black", "GB1118", "2005, 5, 4", 8);
		append(it, 1119, "fengtian", "white", "GB1119", "2001.6.10", 9);
		append(it, 1120, "dazhong", "black", "GB1111", "1996.7.5", 10);
		cout << size<<"��" ;
	}
	//���������Ϣ
	void print(Data A[]) {
		for (int i = 0; i < size; i++) {
			cout << "�����ƺţ�" << A[i].Carnumber << "  " << "����Ʒ��:" << A[i].brand << "  " << "������ɫ:" << A[i].color << "  " << "�����ͺ�:" << A[i].model << '\n' <<
				"��������:" << A[i].date << endl;
		}
	}
	//���Ҳ���ʾ������Ϣ
	void find(Data A[]) {
		int i;
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		cout << "�����복�ƺ�:"; cin >> Carnumber;
		for ( i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber) {
				cout<< "�����ƺţ�" << A[i].Carnumber << "  " << "����Ʒ��:" << A[i].brand << "  " << "������ɫ:" << A[i].color << "  " << "�����ͺ�:" << A[i].model << '\n' << "��������:"
					<< A[i].date << endl;
			}
		}	
	}
	//ɾ��������Ϣ
	void remove(Data A[]) {
		int i;
		int Carnumber;
		cout << "������ɾ�����ƺ�:"; cin >> Carnumber;
		for (i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber && i != size - 1)
				break;
		}
		for (int j = i; j < size-1; j++) {
			A[j] = A[j + 1];
				}
		size--;
				

	}
	//�޸�������Ϣ
	void change(Data A[]) {
		int i;
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		cout << "������Ҫ�޸ĵ��������ƺ�:"; cin >> Carnumber;
		for ( i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber && i != size - 1)
				break;
		}
		cout << "��������Ҫ�޸ĵ�������Ϣ:" << endl;
		cout << "�����복�ƺ�:"; cin >> Carnumber;
		cout << "�����복Ʒ��:"; cin >> brand;
		cout << "�����복����ɫ:"; cin >> color;
		cout << "�����복���ͺ�:"; cin >> model;
		cout << "�����복����������:"; cin >> date;
		A[i].Carnumber = Carnumber;
		A[i].brand = brand;
		A[i].color = color;
		A[i].model = model;
		A[i].date = date;

	}
};

int main() {
	int i;
	Data a;
	Data it[50];
	int m = 1;
	while (m != 0) {
		cout << "**********��ӭʹ��������Ϣ����ϵͳ**********" << endl;
		cout << "**�����������ʾ��Ϣ��ѡ������Ҫ���еĲ���**" << endl;
		cout << "* 1.���뱾��������Ϣ     2.�鿴����������Ϣ*" << endl;
		cout << "* 3.����������Ϣ         4.ɾ��������Ϣ    *" << endl;
		cout << "* 5.����������Ϣ         6.�޸�������Ϣ    *" << endl;
		cout << "* 7.����������Ϣ         8.�˳���Ϣϵͳ    *" << endl;
		cout << "             �����빦��ѡ��:";
		cin >> i;
		if (i == 1) {
			a.input(it);
			cout << "������Ϣ������" << endl;
			cout << endl;
		}
		else
			if (i == 2)
				a.print(it);
			else
				if (i == 3) {
					cout << "���Ҳ�����Ϣ�����Զ����س�����"<<endl;
					a.find(it);
							cout<<endl;
				}
				else
					if (i == 4){
						{
							a.remove(it);
							cout << "             ɾ�������" << endl;
							cout << endl;
						}
					}
					else
						if (i == 5) {
							a.insert(it);
							cout << "             ���������" << endl;
							cout << endl;
						}
						else
							if (i == 6) {a.change(it);
								cout << "             �޸������" << endl;
								cout << endl;
							}
							else
								if (i == 7) {a.sort(it);
									cout << "             ���������" << endl;
								}
								else
									if (i == 8) {
										cout << "             ϵͳ�ɹ��˳�" << endl;
										m = 0;
									}
	}

}