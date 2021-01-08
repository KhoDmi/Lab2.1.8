#include<stdlib.h>;     
#include<iostream>;
#include <fstream>;
#include <limits>;
#include"cmath";
#include <cassert>;
#include <typeinfo>;



#include"ODList.h";
#include"File.h"

using namespace std;


int intInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			finalnumd = finalnum;
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return intInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		cout << "Wrong input, try again\n";
		return intInpCheck();
	}
	if (doubleCheck == 0)
	{
		if (negativCheck == 1)
			return -finalnum;
		return finalnum;
	}
}
double doubleInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return doubleInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		finalnumd = finalnum / pow(10, (i - point - 1));
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
	if (doubleCheck == 0)
	{
		finalnumd = finalnum;
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
}
int answerCheck()
{
	int check = 0;
	do
	{
		cout << "Input your answer (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = cin.get();
		if (answer == 'y') check = 1;
		if (answer == 'n') check = -1;
	} while (check == 0);
	return check;
}


class MyException
{

public:

	MyException(string err)
	{
		ex_mes = err;
	}

	const char* getErr()
	{

		return ex_mes.c_str();
	}

private:
	string ex_mes;
};




int main()
{
	ODList<int> the_intlist;
	ODList<int>::iterator list_intiter;



	the_intlist.add_front(1);

	the_intlist.add_front(3);

	the_intlist.print();
	
	the_intlist.Shell();

	the_intlist.print();

	the_intlist.Shellgr();

	the_intlist.print();

	the_intlist.remove_front();


	//char* fname1 = _strdup("C:/Users/Lenovo/source/repos/Project2.1.8/text.bin");

	//File file1(fname1, ios::in | ios::out | ios::binary | ios::trunc );

	//bool l = file1.IsAllRight();

	//string n = "523k";
	//file1.WriteAsText(n);
	//file1.SetPointerPosition(0);
	//char s[2];
	//file1.ReadString(s, 1);
	//cout << s<<"   ";


	//char* fname2 = _strdup("C:/Users/Lenovo/source/repos/Project2.1.8/text.txt");

	//File file2(fname2, ios::in | ios::out | ios::trunc);

	//
	//file2.file << 'f' <<10;

	//file2.SetPointerPosition(0);

	//string b;
	//file2.file >> b;

	//cout << b;

	//getchar();

	return 0;
}