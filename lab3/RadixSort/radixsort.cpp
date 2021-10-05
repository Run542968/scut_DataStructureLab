/****************
* @ File: radixsort
* @ Author: 杜佳润 (201830060183)
* @ Date: 2019-11-4
* @ Description：RadixSort 
****************/

#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

void radixsort(int a[],int n) {//排序实现
	int k = 5;
	int r = 10;
	int* b = new int[n];
	int* cnt = new int[r];
	int j;
	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r) {
		for (j = 0; j < r; j++) cnt[j] = 0;
	
	for (j = 0; j < n; j++) cnt[(a[j] / rtoi) % r]++;
	for (j = 1; j < r; j++) cnt[j] = cnt[j - 1] + cnt[j];
	for (j = n - 1; j >= 0; j--)
		b[--cnt[(a[j] / rtoi) % r]] = a[j];
	for (j = 0; j < n; j++) a[j] = b[j];
}
	delete []b;
	delete []cnt;
}

void test1(int a[], int n) {//100输入数据测试
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
	radixsort(a, n);//开始排序
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[], int n) {//1000输入数据测试
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
	radixsort(a, n);//开始排序
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//结束计时
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[], int n) {//10000输入数据测试
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
	radixsort(a, n);//开始排序
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