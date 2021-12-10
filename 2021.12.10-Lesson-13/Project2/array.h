
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

typedef int position;

struct elem_data
{
public:
	elem_data(const char* new_name = "", const char* new_domen = "") // ����������� 
	{
		strcpy(name, new_name);
		strcpy(domen, new_domen);
	}

	bool cmpDat(const elem_data &cmp_elem) const // ��������� ���������
	{
		if (strcmp(name, cmp_elem.name) == 0 && strcmp(domen, cmp_elem.domen) == 0)
			return true;
		return false;
	}

	friend ostream& operator << (ostream& out, const elem_data& data);

	static const int NLEN = 31;
	char name[NLEN];
	char domen[NLEN];
};


struct list_elem
{
	list_elem(const char* new_name = "", const char* new_domen = "") { elem_data info(new_name, new_domen); }
	elem_data info;
};

class MyList
{
public:
	MyList() {}; //����������� �� ���������
	MyList(const MyList &o_arr); //���������� �����������
	position end(); //������� ����� ����������
	bool insert(const elem_data &new_data, const position &pos); //������� �������� � �������
	friend ostream& operator << (ostream& out, const MyList& pl);
	position locate(const elem_data &cmpElem) const; //����� �������� � ������
	elem_data& retrieve(const position &pos); //����������� �������� �� �������
	bool delete_elem(const position &pos); //�������� �������� �� �������
	position next(const position &pos) const; //������� �������� ����� ��������
	position previous(const position &pos) const; //������� �������� ����� �������
	void makeNull(); //�������� ������
	position first() const; //������� ������� ��������
	bool cmpElem(const position &f, const position &s) const; //��������� ��������� �� ��������
	static void initList() {}; //��������

private:
	static const int LEN_ = 20; //����� ������
	list_elem list_[LEN_];
	int count_ = 0; //������� ���������� ��������� ������
};

ostream& operator << (ostream& out, const elem_data& data)
{
	cout << data.name << "@" << data.domen << endl;
	return out;
}

ostream& operator << (ostream& out, const MyList& pl)
{
	for (position i = 0; i < pl.count_; i++)
		cout << pl.list_[i].info;
	return out;
}

//���������� �����������
//������������ ���������: ������
//������������ ��������:
MyList::MyList(const MyList &o_arr)
{
	memcpy(list_, o_arr.list_, o_arr.count_ * sizeof(list_elem));
	count_ = o_arr.count_;
}

//������� ��������, ����� ����������
//������������ ���������: 
//������������ ��������: ������� �������� ����� ����������, ���� "-1", ���� ������� ���
position MyList::end()
{
	if (count_ < LEN_)
		return count_ + 1;
	else
		return -1;
}

//������� �������� � ������
//������������ ���������: ������� ������, ������� ��� �������
//������������ ��������: true -- ������� ������ �������, false -- ������� ����������
bool MyList::insert(const elem_data &new_data, const position &pos)
{
	if ((pos - 1 > count_) || (pos < 1)) //������� ��� ������� �� ��������� � ���
		return false;
	else
		if (pos - 1 == count_) //����������� ������� -- ��������� � ������
		{
			list_[pos - 1].info = new_data;
			count_++;
			return true;
		}
		else
		{
			for (int i = count_ - 1; i >= pos - 1; i--)
				list_[i + 1].info = list_[i].info;
			//memmove(list_ + pos, list_ + pos - 1, (count_ - pos + 1) * sizeof(list_elem)); //�������������� �����
			list_[pos - 1].info = new_data; //������� ������ ��������
			count_++;
			return true;
		}
}

//����� �������� ������
//������������ ���������: ������� ������
//������������ ��������: ������� �������� ��������, ���� ������� ������; -1 -- ���� ������� �� ������ � ������
position MyList::locate(const elem_data &cmp_elem) const
{
	position i = 0;
	while ((list_[i].info.cmpDat(cmp_elem) != 1) && (i < count_)) //������������� �������� � ������, ���� �� ������� ������ ��� ������ �� �������������
		i++;
	if (i == count_)
		return -1;
	else
		return i + 1;
}

//������� �� �������
//������������ ���������: ������� ��������
//������������ ��������: ������ �� ������ � ������ �������, ���� ������� �������, NULL-������, � ���� ������
elem_data& MyList::retrieve(const position &pos)
{
	if ((pos <= count_) && (pos > 0))
		return list_[pos - 1].info;
}

//�������� �������� �� ������
//������������ ���������: ������ ��������
//������������ ��������: true -- �������� �������, false -- �������� �� �������
bool MyList::delete_elem(const position &pos)
{
	if ((pos > 0) && (pos <= count_))
	{
		memcpy(list_ + pos - 1, list_ + pos, (count_ - pos) * sizeof(list_elem)); //�������� �������� �� ������� ���������
		count_--;
		return true;
	}
	else
		return false;
}

//��������� ������� ������
//������������ ���������: ������� ��������
//������������ ��������: ������� ��������, ����� ��������
position MyList::next(const position &pos) const
{
	if ((pos <= count_) && (pos > 0))
		return pos + 1;
	else
		return -1;
}

//���������� ������� ������
//������������ ���������: ������� ��������
//������������ ��������: ������� ��������, ����� ��������
position MyList::previous(const position &pos) const
{
	if ((pos <= count_) && (pos > 1))
		return pos - 1;
	else
		return -1;
}

//��������� �������
//������������ ���������: 
//������������ ��������: 
void MyList::makeNull()
{
	count_ = 0;
}

//������ ������
//������������ ���������: 
//������������ ��������: ������� ������� �������� ������ 
position MyList::first() const
{
	return 1;
}

//��������� ��������� ������
//������������ ���������: ������� 1-��� ��������, ������� 2-��� ��������
//������������ ��������: true -- �������� �����, false -- �������� �� �����
bool MyList::cmpElem(const position &f, const position &s) const
{
	return list_[f - 1].info.cmpDat(list_[s - 1].info);
}

//������������� ������� �� �����
//������������ ���������: ������ ��� �������������
//������������ ��������: 
void insertList(MyList &new_list)
{
	ifstream FIN("C:\\education\\prog\\first\\Array\\destination.txt");
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
