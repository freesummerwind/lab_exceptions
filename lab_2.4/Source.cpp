#include <bitset>
#include <iostream>
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

int main()
{
	vector<int> vect1 = { 1, 2, 3, 4 };
	cout << vect1[4]; // std::out_of_range

	vector<int> vect2(-5); // std::length_error

	std::bitset<32> bitset(string("11001010101100001b100101010110000")); // std::invalid_argument

	A a1;
	dynamic_cast<B&> (a1); // std::bad_cast

	while (true) new int[100000000]; // std::bad_alloc
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