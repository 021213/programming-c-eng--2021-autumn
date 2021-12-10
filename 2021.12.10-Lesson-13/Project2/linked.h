// linked.cpp : Defines the entry point for the console application.
//
// Array.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

struct elem_data
{
public:
	elem_data(const char* new_name = "", const char* new_domen = "") // ����������� 
	{
		strcpy(name, new_name);
		strcpy(domen, new_domen);
	}

	bool cmpDat(const elem_data &cmp_elem) // ��������� ���������
	{
		return (strcmp(name, cmp_elem.name) == 0 && strcmp(domen, cmp_elem.domen) == 0);
	}

	friend ostream& operator << (ostream& out, const elem_data& data);

	static const int NLEN = 31;
	char name[NLEN];
	char domen[NLEN];
};


struct list_elem
{
	elem_data info;
	list_elem* next;
	list_elem(const char* new_name = "", const char* new_domen = "", list_elem* new_next = NULL):next(new_next) { elem_data info(new_name, new_domen); }
	list_elem(const elem_data &new_data, list_elem* new_next = NULL) :info(new_data), next(new_next) {}
};

typedef list_elem* position;

class MyList
{
public:
	~MyList(); //����������
	position end(); //������� ����� ����������
	bool insert(const elem_data &new_data, const position pos); //������� �������� � �������
	friend ostream& operator << (ostream& out, const MyList& pl);
	position locate(const elem_data &cmpElem) const; //����� �������� � ������
	elem_data& retrieve(const position &pos); //����������� �������� �� �������
	bool delete_elem(position &pos); //�������� �������� �� �������
	position next(const position &pos); //������� �������� ����� ��������
	position previous(const position &pos); //������� �������� ����� �������
	void makeNull(); //�������� ������
	position first() const; //������� ������� ��������
	static void initList() {}; //��������

private:
	position srchPos(position const &pos); //����� ������� � ������
	position list_ = NULL;
};

MyList::~MyList()
{
	while (list_ != NULL)
		this->delete_elem(list_);
}

ostream& operator << (ostream& out, const elem_data& data)
{
	cout << data.name << "@" << data.domen << endl;
	return out;
}

ostream& operator << (ostream& out, const MyList& pl)
{
	position tmp = pl.list_;
	while (tmp != NULL)
	{
		cout << tmp->info;
		tmp = tmp->next;
	}
	return out;
}

//������� ��������, ����� ����������
//������������ ���������: 
//������������ ��������: ������� �������� ����� ����������, ���� "-1", ���� ������� ���
position MyList::end()
{
	return NULL;
}

//������� �������� � ������
//������������ ���������: ������� ������, ������� ��� �������
//������������ ��������: true -- ������� ������ �������, false -- ������� ����������
bool MyList::insert(const elem_data &new_data, const position pos)
{
	if (pos == list_) //������� � ������
	{
		list_ = new list_elem(new_data, list_);
		return true;
	}

	if (pos == NULL) //������� � �����
	{
		position tmp = srchPos(NULL);
		tmp->next = new list_elem(new_data, NULL);
		return true;
	}
	
	position tmp = srchPos(pos)->next;
	if (tmp)
	{
		list_elem* new_elem = new list_elem(tmp->info, tmp->next);
		tmp->info = new_data;
		tmp->next = new_elem;
		return true;
	}
	
	return false;
}

//����� �������� ������
//������������ ���������: ������� ������
//������������ ��������: ������� �������� ��������, ���� ������� ������;
position MyList::locate(const elem_data &cmp_elem) const
{
	position tmp = list_;
	while ((!tmp->info.cmpDat(cmp_elem)) && (tmp != NULL))
		tmp = tmp->next;
	return tmp;
}

//������� �� �������
//������������ ���������: ������� ��������
//������������ ��������: ������ �� ������ � ������ �������, ���� ������� �������, NULL-������, � ���� ������
elem_data& MyList::retrieve(const position &pos)
{
	if ((pos == list_) || (srchPos(pos)))
		return pos->info;
}

//�������� �������� �� ������
//������������ ���������: ������ ��������
//������������ ��������: true -- �������� �������, false -- �������� �� �������
bool MyList::delete_elem(position &pos)
{
	if (pos == list_)
	{
		position tmp = list_;
		list_ = list_->next;
		delete tmp;
		pos = list_;
		return true;
	}

	position tmp = srchPos(pos);
	if (tmp->next)
	{
		tmp->next = tmp->next->next;
		delete pos;
		pos = tmp->next;
		return true;
	}
	
	return false;
}

//��������� ������� ������
//������������ ���������: ������� ��������
//������������ ��������: ������� ��������, ����� ��������
position MyList::next(const position &pos)
{
	if (pos == list_)
		return pos->next;
	if (srchPos(pos))
		return srchPos(pos)->next->next;
	return NULL;
}

//���������� ������� ������
//������������ ���������: ������� ��������
//������������ ��������: ������� ��������, ����� ��������
position MyList::previous(const position &pos)
{
	if (pos == list_)
		return NULL;
	else
		return srchPos(pos);
}

//��������� �������
//������������ ���������: 
//������������ ��������: 
void MyList::makeNull()
{
	while (list_ != NULL)
		this->delete_elem(list_);
}

//������ ������
//������������ ���������: 
//������������ ��������: ������� ������� �������� ������ 
position MyList::first() const
{
	return list_;
}

position MyList::srchPos(position const &pos)
{
	position tmp = list_;
	while ((tmp->next != pos) && (tmp->next != NULL))
		tmp = tmp->next;
	return tmp;
}

//������������� ������� �� �����
//������������ ���������: ������ ��� �������������
//������������ ��������: 
void insertList(MyList &new_list)
{
	ifstream FIN("C:\\education\\prog\\first\\linked\\destination.txt");
	if (!FIN)
	{
		cout << "File not found!";
		return;
	}

	char name_in[31];
	char domen_in[31];
	FIN >> name_in >> domen_in;
	while ((strlen(name_in) > 0) && (strlen(domen_in) > 0))
	{
		new_list.insert({ name_in, domen_in }, new_list.end());
		FIN >> name_in >> domen_in;
	}
	FIN.close();
}
