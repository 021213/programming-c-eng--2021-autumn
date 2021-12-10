#define LIST_LEN 30

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
	elem_data(const char* new_name = "", const char* new_domen = "") // конструктор 
	{
		strcpy(name, new_name);
		strcpy(domen, new_domen);
	}

	bool cmpDat(const elem_data &cmp_elem) const // сравнение элементов
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
	list_elem(const char* new_name = " ", const char* new_domen = " ", const int next = -1) :info_(new_name, new_domen), next_(next) {};
	elem_data info_;
	position next_;
};

class MyList
{
public:
	MyList() {}; //конструктор по умолчанию
	//MyList(const MyList &o_arr); //копирующий конструктор
	position end(); //позиция после последнего
	bool insert(const elem_data &new_data, const position pos); //вставка элемента в позицию
	friend ostream& operator << (ostream& out, const MyList& pl);
	position locate(const elem_data &cmpElem) const; //поиск элемента в списке
	elem_data& retrieve(const position &pos); //возвращение элемента по позиции
	bool delete_elem(position &pos); //удаление элемента на позиции
	position next(const position &pos) const; //позиция элемента после текущего
	position previous(const position &pos) const; //позиция элемента перед текущим
	void makeNull(); //обнулить список
	position first() const; //позиция первого элемента
	static void initList(); //инициализация статичного массива
	bool testtest();
	static int teststatic;
private:
	bool deleteElemFromList(const position pos, position& list); // удалить элемент из данного списка
	bool addElemToList(const position pos, position &list); // добавить элемент в данный список
	bool addToList(const position pos, const position prev_pos, position &list); // добавить элемент в данный список
	bool moveElem(const position pos, const position prev_pos, position &list_d, position &list_a); // добавить элемент в данный список

	static position srchPos(const position pos, const position &list); //поиск позиции в листе, успех -- возвращает предыдущую позицию, иначе -1
	static position eHead_; 

	static list_elem list_[LIST_LEN];
	
	position head_ = -1; //голова списка
};

list_elem MyList::list_[LIST_LEN];
position MyList::eHead_ = 0;
position MyList::teststatic = 0;

position MyList::end()
{
	return -1;
}

bool MyList::insert(const elem_data & new_data, const position pos)
{
	if ((pos == head_) && (pos != -1))
	{
		list_[eHead_].info_ = list_[head_].info_;
		list_[head_].info_ = new_data;
		moveElem(eHead_, head_, eHead_, head_);
		return true;
	}

	position tmp = srchPos(pos, head_);
	if ((tmp != -1) || (pos == -1)) //вставка в уже существующую позицию
	{
		list_[eHead_].info_ = new_data;
		moveElem(eHead_, tmp, eHead_, head_);
		return true;
	}

	tmp = srchPos(pos, eHead_);
	if ((tmp != -1) || (pos == eHead_)) //вставка в конкретную позицию, сущесвующую в пустом списке
	{
		list_[pos].info_ = new_data;
		moveElem(pos, srchPos(-1, head_), eHead_, head_);
		return true;
	}

	return false;
}

position MyList::locate(const elem_data & cmpElem) const
{
	int tmp = head_;
	while (cmpElem.cmpDat(list_[tmp].info_) && (tmp != -1))
		tmp = list_[tmp].next_;
	return tmp;
}

elem_data & MyList::retrieve(const position & pos)
{
	if ((pos == head_) || (srchPos(pos, head_) != -1))
		return list_[pos].info_;
	else 
		return *(new elem_data("123",""));
}

bool MyList::delete_elem(position & pos)
{
	position tmp = pos;
	pos = list_[pos].next_;

	if (deleteElemFromList(tmp, head_))
		return addElemToList(tmp, eHead_);
	return false;
}

position MyList::next(const position & pos) const
{
	return list_[pos].next_;
}

position MyList::previous(const position & pos) const
{
	return srchPos(pos, head_);
}

void MyList::makeNull()
{
	position tmp = srchPos(-1, head_);
	list_[tmp].next_ = eHead_;
	eHead_ = head_;
	head_ = -1;
	
		
}

position MyList::first() const
{
	return head_;
}

void MyList::initList()
{
	for (int i = 0; i < LIST_LEN - 1; i++)
		list_[i].next_ = i + 1;
	list_[LIST_LEN - 1].next_ = -1;
}

bool MyList::deleteElemFromList(const position pos, position& list)
{
	if (pos == list) //искомый элемент -- первый в списке
	{
		list = list_[pos].next_;
		return true;
	}
	position tmp = srchPos(pos, list); 
	if (tmp != -1) //искомый элемент содержится в списке
	{
		list_[tmp].next_ = list_[pos].next_;
		return true;
	}
	return false; //элемента нет в списке
}

bool MyList::addElemToList(const position pos, position& list)
{
	list_[pos].next_ = list;
	list = pos;
	return true;
}

bool MyList::addToList(const position pos, const position prev_pos, position & list)
{
	if (prev_pos == -1)
	{
		list = pos;
		list_[pos].next_ = -1;
		return true;
	}

	list_[pos].next_ = list_[prev_pos].next_;
	list_[prev_pos].next_ = pos;
	return true;
}

bool MyList::moveElem(const position pos, const position prev_pos, position & list_d, position & list_a)
{
	deleteElemFromList(pos, list_d);
	addToList(pos, prev_pos, list_a);
	return true;
}

bool MyList::testtest()
{
	teststatic = 100;
	return true;
}

position MyList::srchPos(const position pos, const position &list)
{
	position tmp = list;
	while ((list_[tmp].next_ != pos) && (tmp != -1))
		tmp = list_[tmp].next_;
	return tmp;
}


ostream& operator << (ostream& out, const elem_data& data)
{
	cout << data.name << "@" << data.domen << endl;
	return out;
}

ostream& operator << (ostream& out, const MyList& pl)
{
	position tmp = pl.head_;
	while (tmp != -1)
	{
		out << pl.list_[tmp].info_;
		tmp = pl.list_[tmp].next_;
	}
	return out;
}
