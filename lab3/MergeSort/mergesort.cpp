/****************
* @ File: mergesort
* @ Author: 杜佳润 (201830060183)
* @ Date: 2019-11-4
* @ Description：MergeSort 
****************/
#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;
void merge(int a[], int temp[], int left, int right) {//排序实现
	if (left == right) return;
	int mid = (right + left) / 2;
	merge(a, temp, left, mid);
	merge(a, temp, mid + 1, right);
	for (int i = left; i <= right; i++)
		temp[i] = a[i];
	int i1 = left;
	int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1)
			a[curr] = temp[i2++];
		else if (i2 > right)
			a[curr] = temp[i1++];
		else if (temp[i1] <= temp[i2])
			a[curr] = temp[i1++];
		else a[curr] = temp[i2++];
	}
}


void test1(int a[], int a1[], int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random100.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < r+1; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	merge(a, a1, l, r);//开始排序
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[], int a1[], int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random1000.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < r+1; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	merge(a, a1, l, r);//开始排序
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[], int a1[], int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random10000.txt");//导入已经生成好的随机数序列
	for (int i = 0; i < r+1; i++) {
		in >> a[i];//将文本数据导入数组
	}
	in.close();//结束导入
	QueryPerformanceCounter(&time_start);//开始计时
	merge(a, a1, l, r);//开始排序
	//for (int i = 0;i < 10000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 10000 datas:" << run_time << "us" << endl;
}



int main() {
	int* a,*a1;
	int* b,*b1;
	int* c,*c1;
	a = new int[100];
	a1 = new int[100];
	b = new int[1000];
	b1 = new int[1000];
	c = new int[10000];
	c1 = new int[10000];
	test1(a, a1, 0, 99);
	test2(b, b1, 0, 999);
	test3(c, c1, 0, 9999);
	
}