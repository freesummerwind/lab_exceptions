#include <bitset>
#include <iostream>
#include <map>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class A
{
public:
	virtual void func();
};

class B
{
	virtual void func();
};

class vectorException : std::exception
{
public:
	string what();
};

class myChar
{
	char* c;
public:
	myChar(const int& x)
	{
		c = new char[x];
	}
	~myChar()
	{
		delete[] c;
	}
};

int main()
{
	cout << "Part 1" << endl;

	try
	{
		string str1 = "hello";
		str1.erase(10); // std::out_of_range
	}
	catch (std::out_of_range ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		vector<int> vect1(-5); // std::length_error
	}
	catch (std::length_error ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		std::bitset<32> bitset(string("11001010101100001b100101010110000")); // std::invalid_argument
	}
	catch (std::invalid_argument ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		A a1;
		dynamic_cast<B&> (a1); // std::bad_cast
	}
	catch (std::bad_cast ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		while (true) new int[100000000]; // std::bad_alloc
	}
	catch(std::bad_alloc ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		vector<int> vect2 = { 1, 2 }, vect3 = { 1, 3, 5 };
		if (vect2 < vect3)
		{
			if (vect2.size() != vect3.size()) throw vectorException();
		}
	}
	catch (vectorException ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	cout << endl << "Part 2" << endl;

	try
	{
		char* c = new char[10];
		for (int i = 0; i <= 10; ++i)
		{
			if (i == 10) throw "size";
		}
		delete[] c; // losing of data, because this string won't be done
	}
	catch (...)
	{
		cout << "Error" << endl;
	}

	try
	{
		myChar c1(10);
		for (int i = 0; i <= 10; ++i)
		{
			if (i == 10) throw "size";
		}
	    // No losing of data, no "jump" in programm manager in data statistic
	}
	catch (...)
	{
		cout << "Error!!!" << endl;
	}
	return 0;
}

void A::func()
{
	cout << "A" << endl;
}

void B::func()
{
	cout << "B" << endl;
}

string vectorException::what()
{
	return "these vectors have different sizes";
}