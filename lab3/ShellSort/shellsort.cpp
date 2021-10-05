/****************
* @ File: shellsort
* @ Author: �ż��� (201830060183)
* @ Date: 2019-11-4
* @ Description��ShellSort
****************/
#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

void swap(int a[], int i, int j) {
	int p;
	p = a[i];
	a[i] = a[j];
	a[j] = p;
}
void insert(int a[], int n, int increment) {//����ʵ��
	for (int i = increment; i < n; i += increment) {
		for (int j = i; j >= increment; j -= increment) {
			if (a[j] < a[j - increment])
				swap(a, j, j - increment);
		}
	}
}
void shell(int a[], int n) {
	for (int i = n / 2; i >= 2; i /= 2)
		insert(a, n, i);
	insert(a, n, 1);
}

void test1(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random100.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < n; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	shell(a, n);//��ʼ����
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random1000.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < n; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	shell(a, n);//��ʼ����
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[], int n) {
	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	ifstream in("random10000.txt");//�����Ѿ����ɺõ����������
	for (int i = 0; i < n; i++) {
		in >> a[i];//���ı����ݵ�������
	}
	in.close();//��������
	QueryPerformanceCounter(&time_start);//��ʼ��ʱ
	shell(a, n);//��ʼ����
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
		test1(a, 100);
		test2(b, 1000);
		test3(c, 10000);

	}