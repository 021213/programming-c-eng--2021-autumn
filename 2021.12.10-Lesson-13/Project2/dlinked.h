// DLinked.cpp : Defines the entry point for the console application.
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
	elem_data(const char* new_name = "", const char* new_domen = "") // конструктор 
	{
		strcpy(name, new_name);
		strcpy(domen, new_domen);
	}

	bool cmpDat(const elem_data &cmp_elem) // сравнение элементов
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
	list_elem(const char* new_name = "", const char* new_domen = "", list_elem* new_next = NULL, list_elem* new_prev = NULL) :next(new_next), prev(new_prev) { elem_data info(new_name, new_domen); }
	list_elem(const elem_data &new_data, list_elem* new_next = NULL, list_elem* new_prev = NULL) :info(new_data), next(new_next), prev(new_prev) {}
	elem_data info;
	list_elem* next;
	list_elem* prev;
};

typedef list_elem* position;

class  MyList
{
public:
	~ MyList(); //деструктор
	position end(); //позиция после последнего
	bool insert(const elem_data &new_data, const position pos); //вставка элемента в позицию
	friend ostream& operator << (ostream& out, const  MyList& pl);
	position locate(const elem_data &cmpElem) const; //поиск элемента в списке
	elem_data& retrieve(const position &pos); //возвращение элемента по позиции
	bool delete_elem(position &pos); //удаление элемента на позиции
	position next(const position &pos); //позиция элемента после текущего
	position previous(const position &pos); //позиция элемента перед текущим
	void makeNull(); //обнулить список
	position first() const; //позиция первого элемента
	static void initList() {}; //пустышка

private:
	position srchPos(position const pos); //поиск позиции в списке
	position head_ = NULL;
	position tail_ = NULL;
};

 MyList::~ MyList()
{
	while (head_ != NULL)
		this->delete_elem(head_);
}

ostream& operator << (ostream& out, const elem_data& data)
{
	cout << data.name << "@" << data.domen << endl;
	return out;
}

ostream& operator << (ostream& out, const  MyList& pl)
{
	position tmp = pl.head_;
	while (tmp != NULL)
	{
		cout << tmp->info;
		tmp = tmp->next;
	}
	return out;
}

//позиция элемента, после последнего
//передаваемые параметры: 
//возвращаемое значение: позиция элемента после последнего, либо "-1", если таковой нет
position  MyList::end()
{
	return NULL;
}

//вставка элемента в список
//передаваемые параметры: элемент данных, позиция для вставки
//возвращаемое значение: true -- вставка прошла успешна, false -- вставка невозможна
bool  MyList::insert(const elem_data &new_data, const position pos)
{
	if ((head_ == NULL) && (pos == NULL)) // вставка в пустой список
	{
		head_ = tail_ = new list_elem(new_data, NULL, NULL);
		return true;
	}
		
	if (pos == NULL) //вставка в конец списка
	{
		tail_ = new list_elem(new_data, NULL, tail_);
		(tail_->prev)->next = tail_;
		return true;
	}

	if (srchPos(pos)) //вставка на конкретную позицию
	{
		pos->next = new list_elem(pos->info, pos->next, pos);
		if (pos->next->next)
			pos->next->next->prev = pos->next;
		else
			tail_ = pos->next;
		pos->info = new_data;
		return true;
	}
	return false;
}

//поиск элемента списка
//передаваемые параметры: элемент списка
//возвращаемое значение: позиция искомого элемента, если элемент найден;
position  MyList::locate(const elem_data &cmp_elem) const
{
	position tmp = head_;
	while ((!tmp->info.cmpDat(cmp_elem)) && (tmp))
		tmp = tmp->next;
	return tmp;
}

//элемент по позиции
//передаваемые параметры: позиция элемента
//возвращаемое значение: ссылка на объект в нужной позиции, если позиция валидна, NULL-ссылка, в ином случае
elem_data&  MyList::retrieve(const position &pos)
{
	if (srchPos(pos))
		return pos->info;
}

//удаление элемента из списка
//передаваемые параметры: позици элемента
//возвращаемое значение: true -- удаление успешно, false -- удаление не удалось
bool  MyList::delete_elem(position &pos)
{
	position tmp = srchPos(pos);
	if (tmp)
	{
		if (pos == head_) //удаляемый элемент -- первый в списке
		{
			head_ = head_->next;
			delete tmp;
			if (head_ != NULL)
				head_->prev = NULL;
			pos = head_;
			return true;
		}

		if (pos == tail_) //удаляемый элемент -- последний в списке
		{
			tail_ = tail_->prev;
			delete tmp;
			tail_->next = NULL;
			pos = tail_;
			return true;
		}

		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		pos = pos->next;
		delete tmp;
		return true;
	}
	else
		return false;
}

//следующий элемент списка
//передаваемые параметры: позиция элемента
//возвращаемое значение: позиция элемента, после исходной
position  MyList::next(const position &pos)
{
	if (srchPos(pos))
		return pos->next;
	else
		return NULL;
}

//предыдущий элемент списка
//передаваемые параметры: позиция элемента
//возвращаемое значение: позиция элемента, перед исходной
position  MyList::previous(const position &pos)
{
	if (srchPos(pos))
		return pos->prev;
	else
		return NULL;
}

//обнуление массива
//передаваемые параметры: 
//возвращаемое значение: 
void  MyList::makeNull()
{
	while (head_ != NULL)
		this->delete_elem(head_);
}

//начало списка
//передаваемые параметры: 
//возвращаемое значение: позиция первого элемента списка 
position  MyList::first() const
{
	return head_;
}

position MyList::srchPos(position const pos)
{
	position tmp = head_;
	while ((tmp != NULL) && (tmp != pos))
		tmp = tmp->next;
	return tmp;
}

//инициализация массива из файла
//передаваемые параметры: список для инициализации
//возвращаемое значение: 
void insertList( MyList &new_list)
{
//	ifstream FIN("C:\\education\\prog\\first\\DLinked\\destination.txt");
	ifstream FIN("D:\\Desktop\\banana\\Hw\\dest.txt");
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
		new_list.insert({ name_in, domen_in }, new_list.first());
		FIN >> name_in >> domen_in;
	}
	FIN.close();
}


