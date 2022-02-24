#include<iostream>
#include<cstdlib>
#include<time.h>
const int BUFSIZE = 10;
const int ITERATIONS = 50;
using namespace std;
double getProb();
int* generateData(int* &inbuf, int &count);
void processData(int* &outbuf, int &count, int &total);
int main()
{
	int *fillbuffer = new int[BUFSIZE];
	int fillcnt = 0; int *processbuffer = NULL; int processcnt = 0;
	int tcount = 0;
	for (int i = 0; i<ITERATIONS; i++)
	{
		int *temp;
		if (getProb() <= 0.40)
		{
			temp = generateData(fillbuffer, fillcnt);
			if (temp != NULL) processbuffer =
				temp;
		}
		if (getProb() <= 0.60)
			processData(processbuffer, processcnt, tcount);
		cout << fillcnt << '\t' << processcnt << endl;
	}
	cout << "Total value: " << tcount << endl;
	system("pause");
	return 0;
}
double getProb()
{
	double rand_no;
	srand(time(0));
	rand_no = rand() % 10 + 1;
	return rand_no;
}
int* generateData(int* &inbuf, int &count)
{
	int rand_integer;
	rand_integer = rand() % 9 + 1;
	inbuf[count] = rand_integer + inbuf[count];
	count++;
	int size = sizeof(inbuf);
	if (size > BUFSIZE)
	{
		count = 0;
		int buffer[BUFSIZE];
		inbuf = buffer;
		return inbuf;
	}
	else
		return NULL;

}
void processData(int* &outbuf, int &count, int &total)
{
	if (outbuf == NULL)
		return;
	else
	{
		total = total + outbuf[count];
		count++;
	}
	if (count == BUFSIZE)
	{
		count = 0;
		delete[] outbuf;
		outbuf = NULL;
	}

}