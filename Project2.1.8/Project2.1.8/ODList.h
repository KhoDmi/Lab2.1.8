#pragma once

#include <iostream>
#include <fstream>;
#include <typeinfo>

#include"File.h"
using namespace std;




template <typename T>
class ODList
{
public:
	friend  File;
	class iterator;
	friend class iterator;
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



private:
	class Student;
	friend class Student;


	class Student
	{
	public:
		friend File;
		friend class ODList<T>;
		friend class iterator;
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


	public:

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

		File io;

		Student()
		{
			setf_s_t_names();
			setGroup();
			setMark();
			setIncome();
		}

		Student(T a) :val(a)
		{
			setf_s_t_names();
			setGroup();
			setIncome();
		}

		Student(char a, char b)
		{
		}

		Student(T a, int b, double c, string d) :val(a), group(b),income(c), f_s_t_names(d)
		{
		}


		void setf_s_t_names()
		{
			cout << "Input names"<<endl;
			cin >> f_s_t_names;
			
		}

		void setGroup()
		{
			cout << "input group"<<endl;
			group = intInpCheck();
		}

		void setMark()
		{

			do
			{
				do
				{
					cout << "Input mark" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> val;
				} while (cin.fail());
			} while (val < 0);

		}

		void setIncome()
		{
			cout << "input income" << endl;
			income = doubleInpCheck();
		}


		void getMark()
		{
			cout << "Mark is:" << val << endl;
		}

		T Mark()
		{
			return val;
		}

		void get()
		{
			cout << "fst is:" << f_s_t_names << endl;
			cout << "group is:" << group << endl;
			cout << "income is:" << income << endl;
		}

		~Student()
		{

		}

		double income;
		int group;
		string f_s_t_names;
		T val;
		Student* next;
	};




public:
	class iterator
	{
		friend class ODList<T>;
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


	public:
		iterator() :the_node(0) {}

		iterator(Student* ln) : the_node(ln) {}

		iterator(const iterator& it) : the_node(it.the_node) {}

		iterator& operator=(const iterator& it)
		{
			the_node = it.the_node;
			return *this;
		}


		bool operator == (const iterator& it) const
		{
			return (the_node == it.the_node);
		}


		bool operator!=(const iterator& it) const
		{
			return !(it == *this);
		}

		iterator operator++(int)
		{
			if (the_node == 0)
				throw "incremented an empty iterator";
			if (the_node->next == 0)
				throw "tried to increment too far past the end";

			the_node = the_node->next;
			return *this;
		}




		T& operator*() const
		{
			if (the_node == 0)
				throw "tried to dereference an empty iterator";
			if (the_node != 0)

				the_node->get();

			return the_node->val;
		}

	private:
		Student* the_node;
	};

private:
	Student* head;
	Student* tail;

	iterator head_iterator;
	iterator tail_iterator;

public:
	ODList()
	{
		head = tail = new Student(NULL, NULL, NULL, "0");
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
	}

	ODList(T node_val)
	{
		head = tail = new Student;
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
		add_front(node_val);
	}

	~ODList()
	{
		Student* node_to_delete = head;
		for (Student* cn = head; cn != tail;)
		{
			cn = cn->next;
			delete node_to_delete;
			node_to_delete = cn;
		}

		delete node_to_delete;
	}

	bool is_empty() { return head == tail; }


	iterator front() { return head_iterator; }
	iterator rear() { return tail_iterator; }


	bool operator == (const ODList& it) const
	{
		return (size() == it.size());
	}
	bool operator!=(const ODList& it) const
	{
		return !(it == *this);
	}
	void Shellnewvr4()
	{
		try
		{
			if (is_empty())
				throw MyException("tried to sort an empty list\n");
			T count = 0;
			string counts;
			double countd;
			int counti;
			int i = 0;
			int d = size();
			int n = d;
			d = d / 2;
			while (d > 0)
			{
				Student* cur = head;
				Student* last = head;
				for (i = 0; i < d; i++)
				{
					last = last->next;
				}
				for (i = 0; i < n - d; i++)
				{
					int j = i;
					while (j >= 0 && cur->val > last->val)
					{
						count = cur->val;
						cur->val = last->val;
						last->val = count;

						countd = cur->income;
						cur->income = last->income;
						last->income = countd;

						counts = cur->f_s_t_names;
						cur->f_s_t_names = last->f_s_t_names;
						last->f_s_t_names = counts;

						counti = cur->group;
						cur->group = last->group;
						last->group = counti;

						j--;
					}
					cur = cur->next;
					last = last->next;
				}
				d = d / 2;

				if (d == 0)
				{
					d = 1;
					Student* cur = head;
					Student* last = head;
					for (i = 0; i < d; i++)
					{
						last = last->next;
					}
					for (i = 0; i < n - d; i++)
					{
						int j = i;
						while (j >= 0 && cur->val > last->val)
						{
							count = cur->val;
							cur->val = last->val;
							last->val = count;

							countd = cur->income;
							cur->income = last->income;
							last->income = countd;

							counts = cur->f_s_t_names;
							cur->f_s_t_names = last->f_s_t_names;
							last->f_s_t_names = counts;

							counti = cur->group;
							cur->group = last->group;
							last->group = counti;

							j--;
						}
						cur = cur->next;
						last = last->next;
					}
					d = d / 2;
				}
			}
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}










	void readStd(Student* tmp,fstream& file)
	{
		char cur[200];
		char cur1[200];
		char cur2[200];
		char cur3[200];
		int y = 0;
		char ch = file.get();
		while (ch != '\n') {
			*(cur + y) = ch;
			y++;
			ch = file.get();
		}
		*(cur + y) = '\0';

		tmp->f_s_t_names=cur;

		y = 0;
		ch = file.get();
		while (ch != '\n') {
			*(cur1 + y) = ch;
			y++;
			ch = file.get();
		}
		*(cur1 + y) = '\0';

		tmp->group = atoi(cur1);

		y = 0;
		ch = file.get();
		while (ch != '\n') {
			*(cur2 + y) = ch;
			y++;
			ch = file.get();
		}
		*(cur2 + y) = '\0';

		tmp->val = atoi(cur2);

		y = 0;
		ch = file.get();
		while (ch != '*') {
			*(cur3 + y) = ch;
			y++;
			ch = file.get();
		}
		*(cur3 + y) = '\0';

		tmp->income = atoi(cur3);


	}

	


	void Shellgr()
	{
		try
		{
			if (is_empty())
				throw MyException("tried to sort an empty list\n");
			T count = 0;
			string counts;
			double countd;
			int counti;
			int i = 0;
			int d = size();
			int n = d;
			d = d / 2;
			while (d > 0)
			{
				Student* cur = head;
				Student* last = head;
				for (i = 0; i < d; i++)
				{
					last = last->next;
				}
				for (i = 0; i < n - d; i++)
				{
					int j = i;
					while (j >= 0 && cur->group > last->group)
					{
						count = cur->val;
						cur->val = last->val;
						last->val = count;

						countd = cur->income;
						cur->income = last->income;
						last->income = countd;

						counts = cur->f_s_t_names;
						cur->f_s_t_names = last->f_s_t_names;
						last->f_s_t_names = counts;

						counti = cur->group;
						cur->group = last->group;
						last->group = counti;

						j--;
					}
					cur = cur->next;
					last = last->next;
				}
				d = d / 2;

				if (d == 0)
				{
					d = 1;
					Student* cur = head;
					Student* last = head;
					for (i = 0; i < d; i++)
					{
						last = last->next;
					}
					for (i = 0; i < n - d; i++)
					{
						int j = i;
						while (j >= 0 && cur->group > last->group)
						{
							count = cur->val;
							cur->val = last->val;
							last->val = count;

							countd = cur->income;
							cur->income = last->income;
							last->income = countd;

							counts = cur->f_s_t_names;
							cur->f_s_t_names = last->f_s_t_names;
							last->f_s_t_names = counts;

							counti = cur->group;
							cur->group = last->group;
							last->group = counti;

							j--;
						}
						cur = cur->next;
						last = last->next;
					}
					d = d / 2;
				}
			}
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}
	




	void Shellnewver4()
	{
		try
		{
			if (is_empty())
				throw MyException("tried to sort an empty list\n");
		File fint;
		fstream fin("C:/Users/Lenovo/source/repos/Project2.1.8/text.txt", ios::in | ios::out);
		int i, j, step;
		Student tmp('a','a');
		Student	tmp1('a','a');
		char* grbg1[200];
		char* grbg2[200];
		char* tmpc[200];
		char* tmp1c[200];
		int n = size();
		for (int q=0; q < n; q++)
		{
			remove_front_empty();
		}
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				fin.seekg(fint.myseek(i),ios_base::beg);
				readStd(&tmp, fin);
				for (j = i; j >= step; j -= step)
				{
					fin.seekg(fint.myseek(j - step), ios_base::beg );
					readStd(&tmp1, fin);
					if (tmp.Mark() < tmp1.Mark()) {
						
							fin.seekg(fint.myseek(j) , ios_base::beg);
							fin << tmp1.f_s_t_names << '\n';
							fin << tmp1.group << '\n';
							fin << tmp1.val << '\n';
							fin << tmp1.income << '*';
						
							fin.seekg(fint.myseek(i) , ios_base::beg);
							fin << tmp.f_s_t_names << '\n';
							fin << tmp.group << '\n';
							fin << tmp.val << '\n';
							fin << tmp.income << '*';
						
							
					}
					else
							break;
				}
				
					fin.seekg(fint.myseek(j) , ios_base::beg);
					fin << tmp1.f_s_t_names << '\n';
					fin << tmp1.group << '\n';
					fin << tmp1.val << '\n';
					fin << tmp1.income << '*';
			
			}
		//for (int k = 0; k < n; k++)
		//{
		//	fin.seekg(fint.myseek(k), ios_base::beg);
		//	Student to_add('a', 'a');
		//	readStd(&to_add, fin);
		//	to_add.next = head;
		//	head = &to_add;
		//	head_iterator = iterator(head);
		//}
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}



	void add_front(T node_val)
	{
		try
		{
			Student* node_to_add = new Student(node_val);
			if (find(node_to_add->f_s_t_names))
				throw MyException("tried to add an existing element\n");
			node_to_add->next = head;
			head = node_to_add;

			head_iterator = iterator(head);
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}
	}

	bool insert_after(T node_val, const iterator& key_i)
	{
		Student* dn = head;
		for (Student* prvn = head; prvn != tail; dn = prvn->next)
		{

			if (dn == key_i.the_node)
			{
				Student* node_to_add = new Student(node_val);
				prvn->next = dn;
				node_to_add->next = dn->next;
				dn->next = node_to_add;
				return true;
			}


		}
		return false;
	}

	T remove_front()
	{
		
			try
			{

				if (is_empty())
					throw MyException("tried to remove from an empty list\n");
				Student* node_to_remove = head;
				T return_val = node_to_remove->val;
				head = node_to_remove->next;
				head_iterator = iterator(head);
				delete node_to_remove;
				print();
				return return_val;
			}
			catch (MyException exception)
			{
				cerr << exception.getErr();
			}
		


	}


	void remove_front_empty()
	{

		try
		{

			if (is_empty())
				throw MyException("tried to remove from an empty list\n");
			Student* node_to_remove = head;
			T return_val = node_to_remove->val;
			head = node_to_remove->next;
			head_iterator = iterator(head);
			delete node_to_remove;
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}



	}

	bool remove_it(iterator& key_i)					/////////////
	{
		try
		{
			if (is_empty())
				throw MyException("tried to remove from an empty list\n");
			iterator rn = iterator(head);
			for (iterator prn = iterator(head); prn != tail_iterator; rn++)
			{

				if (rn.the_node == key_i.the_node)
				{
					prn.the_node->next = rn.the_node->next;
					delete rn.the_node;
					key_i.the_node = 0;
					return true;
				}


				prn++;
			}

			return false;
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}

	int find_and_del(string f_s_t_names) const
	{
		iterator prn = head_iterator;
		iterator rn = prn.the_node->next;
		if (prn.the_node->f_s_t_names == f_s_t_names)
		{
			return 1;
		}
		while(rn!=tail_iterator.the_node->next)
		{
			if (rn.the_node->f_s_t_names == f_s_t_names)
			{
				rn.the_node->get();
				rn.the_node->getMark();
				cout << endl;
				prn.the_node->next = rn.the_node->next;
				delete rn.the_node;
			}
			prn++;
			rn = prn.the_node->next;
		}
		return 0;

	}


	bool find(string f_s_t_names) const
	{
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			if (rn.the_node->f_s_t_names == f_s_t_names)
				return true;
		}
		return false;

	}

	iterator get_nth(const int element_num) const
	{
		if (element_num < 1)
			return tail_iterator;

		int count = 1;
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			if (count++ == element_num)
				return rn;
		}

		return tail_iterator;
	}

	int size() const
	{
		int count = 0;
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			++count;
		}

		return count;
	}




	void show_front()
	{
		iterator rn = iterator(head);
		rn.the_node->get();
		rn.the_node->getMark();
		cout << endl;
	}



	void print() const
	{
		ofstream file("C:/Users/Lenovo/source/repos/Project2.1.8/text.txt", ios::in | ios::out | ios::trunc);

		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			file << rn.the_node->f_s_t_names<<'\n';
			file << rn.the_node->group << '\n';
			file << rn.the_node->val << '\n';
			file << rn.the_node->income << '*';
			rn.the_node->get();
			rn.the_node->getMark();
			cout << endl;	
     

		}
		cout << endl;
	}

	



	


	







};


