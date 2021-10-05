/****************
* @ File: radixsort
* @ Author: �ż��� (201830060183)
* @ Date: 2019-11-4
* @ Description��RadixSort 
****************/

#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

void radixsort(int a[],int n) {//����ʵ��
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

void test1(int a[], int n) {//100�������ݲ���
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
	radixsort(a, n);//��ʼ����
	//for (int i = 0;i < 100;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 100 datas:" << run_time << "us" << endl;
}
void test2(int a[], int n) {//1000�������ݲ���
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
	radixsort(a, n);//��ʼ����
	//for (int i = 0;i < 1000;i++)
		//cout << a[i] << '\t';
	QueryPerformanceCounter(&time_over);//������ʱ
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << "The time of 1000 datas:" << run_time << "us" << endl;
}
void test3(int a[], int n) {//10000�������ݲ���
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
	radixsort(a, n);//��ʼ����
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