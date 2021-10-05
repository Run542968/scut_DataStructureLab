/****************
* @ File: quicksort
* @ Author: �ż��� (201830060183)
* @ Date: 2019-11-4
* @ Description��QuickSort
****************/
#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

inline void swap(int a[], int i, int j) {//����ʵ��
	int p;
	p = a[i];
	a[i] = a[j];
	a[j] = p;
}
inline int findpivot(int a[], int left, int right) {
	return (left + right) / 2;
}
inline int partition(int a[], int l, int r, int& pivot) {
	do {
		while (a[++l] < pivot);
		while (l < r && pivot < a[--r]);
		swap(a, l, r);
	} while (l < r);
	return l;
}
void quick(int a[], int left, int right) {
	if (right <= left) return;
	int indexpivot = findpivot(a, left, right);
	swap(a, indexpivot, right);
	int k = partition(a, left - 1, right, a[right]);
	swap(a, right, k);
	quick(a, left, k - 1);
	quick(a, k + 1, right);

}

void test1(int a[], int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random100.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < r + 1; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	quick(a,l, r);//��ʼ����
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[],int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random1000.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < r + 1; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	quick(a,l, r);//��ʼ����
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[],int l, int r) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random10000.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < r + 1; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	quick(a,l, r);//��ʼ����
	//for (int i = 0;i < 10000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
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
	test1(a, 0, 99);
	test2(b, 0, 999);
	test3(c, 0, 9999);
}