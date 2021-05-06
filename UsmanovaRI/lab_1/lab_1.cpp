#include<iostream>
using namespace std;

using T = int;

class List 
{
public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);
	unsigned size();
	void resize(unsigned size);
	bool insert(unsigned pos, const T &val);
	void push_back(const T& val);
	bool contains(const T& val);
	T& operator[](unsigned index);
	void clean();
	int find(const T& val);
    ~List();
private:
	
	class Node
	{
	public:
		
		Node *next;
		T value;
		Node(T value = T(), Node *next = nullptr) {
			this->value = value;
			this->next = next;
		}
		
	};
	Node *head;
	unsigned Size;
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::List(unsigned size)
{
	cout << "enter the values of the list nodes " << endl;
	T val;
	cin >> val;
	this->Size = size;
	head = new Node(val);
	Node* tmp = this->head;
	for (unsigned i = 1; i < Size; i++) {
		cin >> val;
		tmp->next = new Node(val);
		tmp = tmp->next;

	}
	tmp->next = nullptr;
}


List::List(unsigned size, const T& val)
{
	this->Size = size;
	head = new Node(val);
	Node* tmp = this->head;
	for (unsigned i = 1; i < Size; i++) {

		tmp->next = new Node(val);
		tmp = tmp->next;
		
	}
	tmp->next = nullptr;

}


unsigned List::size()
{
	return Size;

}

void List::resize(unsigned size)
{
	Node* tmp = this->head;
	Node* fake_head = this->head;
	
	if (size > Size) {
		const unsigned s = size - Size;
		for (unsigned i = 0; i < s; i++)
		{
			push_back(0);
		}
		
	}
	if (size < Size) {
		for (unsigned i = 0; i < size-1; i++)
		{
			tmp = tmp->next;
		}
		head = tmp->next;
		tmp->next = nullptr;
		for (unsigned i = 0; i < Size - size; i++)
		{
			clean();
		}
		this->head = fake_head;
		this->Size = size;
	}
}


bool List::insert(unsigned pos, const T& val)
{
	if (pos > Size) {
		return false;
	}
	if (pos == Size + 1) {
		push_back(val);
		return true;
	}
	if (pos == 0) {
		head = new Node(val, head);
		Size++;
	}
	else {
		Node* tmp = this->head;
		for (unsigned i = 0; i < pos - 1; i++) {
			tmp = tmp->next;
		}
		tmp->next = new Node(val, tmp->next);
		Size++;
		return true;
	}
}


void List::push_back(const T& val)
{

	if (head == nullptr) {
		head = new Node(val);
	}
	else {
		Node* tmp = this->head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Node(val);
	}
	Size++;
}


bool List::contains(const T& val)
{
	bool availability = false;
	Node* tmp = this->head;
	for (unsigned i = 0; i < Size; i++) {
		if (tmp->value == val) {
			availability = true;
			break;
		}
		tmp = tmp->next;
	}

	return availability;
}

T& List::operator[](unsigned index)
{
	unsigned counter = 0;
	Node *tmp = this->head;
	while (tmp != nullptr) {
		if (counter == index) {
			return tmp->value;
		}
		tmp = tmp->next;
		counter++;
	}
}


void List::clean()
{
	Node* delete_tmp = head;
	head = head->next;
	delete delete_tmp;
	
}


int List::find(const T& val)
{
	Node* tmp = this->head;
	unsigned i = 0;
	for ( ; i < Size; i++) {
		if (tmp->value == val) {
			return i;
			break;
		}
		tmp = tmp->next;
	}
	if (i == Size) {
		return -1;
	}
}



List::~List()
{
	while (Size) {
		clean();
		Size--;
	}
}


void Output(List &O_lst) {
	for (unsigned i = 0; i < O_lst.size(); i++) {
		cout << O_lst[i] << " ";
	}
	cout << endl;
}



int main() {

	cout << "enter the size of list" << endl;
	unsigned size_of_list;
	cin >> size_of_list;
	
	List lst(size_of_list);

	cout << "created list: ";
	Output(lst);

	cout << "enter the size of const_value list" << endl;
	unsigned size_of_const_list;
	cin >> size_of_const_list;

	List const_lst(size_of_const_list, 10);

	cout << "created const_value list with the value(10): ";
	Output(const_lst);

	cout << "checking for a value: ";
	T check_val;
	cin >> check_val;
	cout << endl;
	cout << "item in the list: " << boolalpha << lst.contains(check_val) << endl;
	cout << "element index: " << lst.find(check_val) << endl;


	
	cout << "new size of list: ";
	int new_size;
	cin >> new_size;
	lst.resize(new_size);
	cout << "resize list: ";
	Output(lst);
	cout << endl;

	cout << "inserting a new element: ";
	T new_element;
	cin >> new_element;
	cout << "position of the new element in the list: ";
	int position;
	cin >> position;
	if (lst.insert(position, new_element)) {
		cout << "successfully: ";
		Output(lst);
		cout << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}

	return 0;
}
