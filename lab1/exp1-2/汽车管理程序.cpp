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
	//按时间顺序排序
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
	//插入汽车信息
	void insert(Data A[]) {
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		int test;
		cout << "请输入汽车信息:" << endl;
		for (int i = size; i < 50; i++)
		{
			cout << "输入0停止添加:" << endl;
			cin >> test;
			if (test == 0)
				break;
			else {
				cout << "请输入车牌号:"; cin >> Carnumber;
				cout << "请输入车品牌:"; cin >> brand;
				cout << "请输入车的颜色:"; cin >> color;
				cout << "请输入车的型号:"; cin >> model;
				cout << "请输入车的生产日期:"; cin >>date;
				A[i].Carnumber = Carnumber;
				A[i].brand = brand;
				A[i].color = color;
				A[i].model = model;
				A[i].date = date;
				size++;
			}
		}
	}
	//函数插入数据
	void append(Data A[], int Carnumber, string brand, string color, string model, string date, int i) {
		A[i - 1].Carnumber = Carnumber;
		A[i - 1].brand = brand;
		A[i - 1].color = color;
		A[i - 1].model = model;
		A[i - 1].date = date;
		size++;
	}
	//输入本地信息
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
		cout << size<<"个" ;
	}
	//输出数组信息
	void print(Data A[]) {
		for (int i = 0; i < size; i++) {
			cout << "汽车牌号：" << A[i].Carnumber << "  " << "汽车品牌:" << A[i].brand << "  " << "汽车颜色:" << A[i].color << "  " << "汽车型号:" << A[i].model << '\n' <<
				"生产日期:" << A[i].date << endl;
		}
	}
	//查找并显示汽车信息
	void find(Data A[]) {
		int i;
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		cout << "请输入车牌号:"; cin >> Carnumber;
		for ( i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber) {
				cout<< "汽车牌号：" << A[i].Carnumber << "  " << "汽车品牌:" << A[i].brand << "  " << "汽车颜色:" << A[i].color << "  " << "汽车型号:" << A[i].model << '\n' << "生产日期:"
					<< A[i].date << endl;
			}
		}	
	}
	//删除汽车信息
	void remove(Data A[]) {
		int i;
		int Carnumber;
		cout << "请输入删除车牌号:"; cin >> Carnumber;
		for (i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber && i != size - 1)
				break;
		}
		for (int j = i; j < size-1; j++) {
			A[j] = A[j + 1];
				}
		size--;
				

	}
	//修改汽车信息
	void change(Data A[]) {
		int i;
		int Carnumber;
		string brand;
		string color;
		string model;
		string date;
		cout << "请输入要修改的汽车车牌号:"; cin >> Carnumber;
		for ( i = 0; i < size; i++) {
			if (Carnumber == A[i].Carnumber && i != size - 1)
				break;
		}
		cout << "请重新想要修改的汽车信息:" << endl;
		cout << "请输入车牌号:"; cin >> Carnumber;
		cout << "请输入车品牌:"; cin >> brand;
		cout << "请输入车的颜色:"; cin >> color;
		cout << "请输入车的型号:"; cin >> model;
		cout << "请输入车的生产日期:"; cin >> date;
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
		cout << "**********欢迎使用汽车信息管理系统**********" << endl;
		cout << "**请根据以下提示信息，选择你所要进行的操作**" << endl;
		cout << "* 1.输入本地汽车信息     2.查看所有汽车信息*" << endl;
		cout << "* 3.查找汽车信息         4.删除汽车信息    *" << endl;
		cout << "* 5.插入汽车信息         6.修改汽车信息    *" << endl;
		cout << "* 7.排序汽车信息         8.退出信息系统    *" << endl;
		cout << "             请输入功能选项:";
		cin >> i;
		if (i == 1) {
			a.input(it);
			cout << "本地信息已输入" << endl;
			cout << endl;
		}
		else
			if (i == 2)
				a.print(it);
			else
				if (i == 3) {
					cout << "查找不到信息即会自动返回初界面"<<endl;
					a.find(it);
							cout<<endl;
				}
				else
					if (i == 4){
						{
							a.remove(it);
							cout << "             删除已完成" << endl;
							cout << endl;
						}
					}
					else
						if (i == 5) {
							a.insert(it);
							cout << "             插入已完成" << endl;
							cout << endl;
						}
						else
							if (i == 6) {a.change(it);
								cout << "             修改已完成" << endl;
								cout << endl;
							}
							else
								if (i == 7) {a.sort(it);
									cout << "             排序已完成" << endl;
								}
								else
									if (i == 8) {
										cout << "             系统成功退出" << endl;
										m = 0;
									}
	}

}