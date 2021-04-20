#include <iostream>

using namespace std;

struct Element
{
	int data;
	Element* prev;
	Element* next;
};

class DList {
private:
	Element* begin;
	Element* end;
	int count;
public:
	DList() {
		begin = NULL;
		end = NULL;
		count = 0;
	}
	DList(DList& other) {

		begin = NULL;
		end = NULL;
		count = 0;
		Element* temp = other.begin;
		while (temp != 0) {
			this->addToEnd(temp->data);
			temp = temp->next;
		}
	}
	void addToEnd(int d) {
		Element* temp = new Element;
		temp->next = NULL;
		temp->data = d;
		temp->prev = end;
		count++;
		if (end != 0)
			end->next = temp;
		else
			end = temp;

		if (begin == 0)
		{
			begin = end = temp;
		}
	}
	void addToBegin(int d) {
		Element* temp = new Element;
		temp->prev = 0;
		temp->data = d;
		temp->next = begin;

		if (begin != 0)
			begin->prev = temp;
		if (count == 0) {
			begin = end = temp;
		}
		else {
			begin = temp;
		}
		count++;
	}
	void insert(int pos, int d) {

		if (pos<1 || pos >count + 1)
			return;

		if (pos == count + 1) {
			addToEnd(d);
			return;
		}
		else if (pos == 1) {
			addToBegin(d);
			return;
		}
		int i = 1;
		Element* begTemp = begin;
		while (i < pos) {
			begTemp = begTemp->next;
			i++;
		}
		Element* prevTemp = begTemp->prev;
		Element* temp1 = new Element;

		temp1->data = d;

		if (prevTemp != 0 && count != 1)
			prevTemp->next = temp1;
		temp1->next = begTemp;
		temp1->prev = prevTemp;
		begTemp->prev = temp1;
		count++;
	}
	void print() {

		if (count != 0) {
			Element* temp = begin;
			while (temp->next != 0) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data;
		}
	}
};


int main() {
	DList lst;
	int len = 8;
	int a[] = { 2,3,2,4,3,5,4,6 };


	for (int i = 0; i < len; i++)
		if (i % 2 == 0)
			lst.addToBegin(a[i]);
		else
			lst.addToEnd(a[i]);

	lst.print();
	return 0;
}