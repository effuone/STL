#include <vector>
#include <iostream>
#include <random>
using namespace std;

struct Element
{
	int data;
	Element* next;
};

class List
{
private:
	Element* begin;
	Element* end;
	int count;
public:
	List()
	{
		begin = NULL;
		end = NULL;
		count = 0;
	}

	int getCount()
	{
		return count;

	}
	void add(char d)
	{
		Element* temp = new Element;
		temp->data = d;
		temp->next = NULL;
		if (begin != NULL)
		{
			end->next = temp;
			end = temp;
		}
		else
		{
			begin = end = temp;
		}
	}
	void delAll()
	{
		while (begin != 0)
		{
			Element* temp = begin;
			begin = temp->next;
			delete temp;
		}
	}
	void del()
	{
		Element* temp = begin;
		begin = temp->next;
		delete temp;
	}
	void print()
	{
		Element* temp = begin;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	~List()
	{
		delAll();
	}
};

int main()
{
	List lst;
	char s[] = "HHHHHH!";
	cout << s << endl;
	for (int i = 0; i < strlen(s); ++i)
	{
		lst.add(s[i]);
	}
	lst.print();
	return 0;
}