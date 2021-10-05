/****************
* @ File: heapsort
* @ Author: �ż��� (201830060183)
* @ Date: 2019-11-4
* @ Description��HeapSort
****************/
#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;
class heap {//Construct the heap
private :
	int *Heap;
	int maxsize;
	int n;
	void siftdown(int pos) {
		while (!isLeaf(pos)) {
			int lc = 2 * pos + 1;
			int rc = 2 * pos + 2;
			if (rc < n && Heap[rc] > Heap[lc])
			lc = rc;
			if (Heap[pos] > Heap[lc]) return;
			swap(Heap, pos, lc);
			pos = lc;
		}
}
public:
	void swap(int a[], int i, int j) {
		int p;
		p = a[i];
		a[i] = a[j];
		a[j] = p;
	}
	heap(int* h, int num, int max) {
		Heap = h;
		n = num;
		maxsize = max;
		buildHeap();
	}
	int size()const { return n; }
	bool isLeaf(int pos)const { return (pos >= n / 2) && (pos < n); }
	void buildHeap() {
		for (int i = n / 2 - 1; i >= 0; i--)
			siftdown(i);
	}
	int removefirst() {
		if (n <= 0) cout << "Heap is empty" << endl;
		swap(Heap, 0, --n);
		if (n != 0) siftdown(0);
		return Heap[n];
	}
};
void heapsort(int a[], int n) {//Heapsort
	int maxval;
	heap H(a, n, n);
	for (int i = 0; i < n; i++)
		maxval = H.removefirst();
}
void test1(int a[],int n) {
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
	heapsort(a, n);//��ʼ����
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
	heapsort(a, n);//��ʼ����
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
	heapsort(a, n);//��ʼ����
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
	test1(a,100);
	test2(b, 1000);
	test3(c, 10000);
}