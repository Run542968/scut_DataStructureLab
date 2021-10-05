/****************
* @ File: intsertsort
* @ Author: 杜佳润 (201830060183)
* @ Date: 2019-11-4
* @ Description：InsertSort
****************/
#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

void swap(int a[], int i, int j) {//函数实现
	int p;
	p = a[i];
	a[i] = a[j];
	a[j] = p;
}
void insert(int a[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1])
				swap(a, j, j - 1);
		}
	}
}

void test1(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random100.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < n; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	insert(a, n);//开始排序
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random1000.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < n; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	insert(a, n);//开始排序
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random10000.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < n; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	insert(a, n);//开始排序
	//for (int i = 0;i < 10000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 10000 datas:" << run_time << "us" << endl;
}

int main() {
	int* a;
	int* b;
	int* c;
	a = new int[100];
	b = new int[1000];
	c = new int[10000];
	test1(a, 100);
	test2(b, 1000);
	test3(c, 10000);

}