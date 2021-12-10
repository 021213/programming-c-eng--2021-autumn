
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
	list_elem(const char* new_name = "", const char* new_domen = "") { elem_data info(new_name, new_domen); }
	elem_data info;
};

class MyList
{
public:
	MyList() {}; //конструктор по умолчанию
	MyList(const MyList &o_arr); //копирующий конструктор
	position end(); //позиция после последнего
	bool insert(const elem_data &new_data, const position &pos); //вставка элемента в позицию
	friend ostream& operator << (ostream& out, const MyList& pl);
	position locate(const elem_data &cmpElem) const; //поиск элемента в списке
	elem_data& retrieve(const position &pos); //возвращение элемента по позиции
	bool delete_elem(const position &pos); //удаление элемента на позиции
	position next(const position &pos) const; //позиция элемента после текущего
	position previous(const position &pos) const; //позиция элемента перед текущим
	void makeNull(); //обнулить список
	position first() const; //позиция первого элемента
	bool cmpElem(const position &f, const position &s) const; //сравнение элементов на позициях
	static void initList() {}; //пустышка

private:
	static const int LEN_ = 20; //длина списка
	list_elem list_[LEN_];
	int count_ = 0; //текущее количество элементов списка
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

//копирующий конструктор
//передаваемые параметры: список
//возвращаемое значение:
MyList::MyList(const MyList &o_arr)
{
	memcpy(list_, o_arr.list_, o_arr.count_ * sizeof(list_elem));
	count_ = o_arr.count_;
}

//позиция элемента, после последнего
//передаваемые параметры: 
//возвращаемое значение: позиция элемента после последнего, либо "-1", если таковой нет
position MyList::end()
{
	if (count_ < LEN_)
		return count_ + 1;
	else
		return -1;
}

//вставка элемента в список
//передаваемые параметры: элемент данных, позиция для вставки
//возвращаемое значение: true -- вставка прошла успешна, false -- вставка невозможна
bool MyList::insert(const elem_data &new_data, const position &pos)
{
	if ((pos - 1 > count_) || (pos < 1)) //позиция для вставки не находится в ОДЗ
		return false;
	else
		if (pos - 1 == count_) //вставляемый элемент -- последний в списке
		{
			list_[pos - 1].info = new_data;
			count_++;
			return true;
		}
		else
		{
			for (int i = count_ - 1; i >= pos - 1; i--)
				list_[i + 1].info = list_[i].info;
			//memmove(list_ + pos, list_ + pos - 1, (count_ - pos + 1) * sizeof(list_elem)); //альтернативный сдвиг
			list_[pos - 1].info = new_data; //вставка нового элемента
			count_++;
			return true;
		}
}

//поиск элемента списка
//передаваемые параметры: элемент списка
//возвращаемое значение: позиция искомого элемента, если элемент найден; -1 -- если элемент не найден в списке
position MyList::locate(const elem_data &cmp_elem) const
{
	position i = 0;
	while ((list_[i].info.cmpDat(cmp_elem) != 1) && (i < count_)) //просматриваем элементы в списке, пока не находим нужный или список не заканчивается
		i++;
	if (i == count_)
		return -1;
	else
		return i + 1;
}

//элемент по позиции
//передаваемые параметры: позиция элемента
//возвращаемое значение: ссылка на объект в нужной позиции, если позиция валидна, NULL-ссылка, в ином случае
elem_data& MyList::retrieve(const position &pos)
{
	if ((pos <= count_) && (pos > 0))
		return list_[pos - 1].info;
}

//удаление элемента из списка
//передаваемые параметры: позици элемента
//возвращаемое значение: true -- удаление успешно, false -- удаление не удалось
bool MyList::delete_elem(const position &pos)
{
	if ((pos > 0) && (pos <= count_))
	{
		memcpy(list_ + pos - 1, list_ + pos, (count_ - pos) * sizeof(list_elem)); //сдвигаем элементы на позицию удалённого
		count_--;
		return true;
	}
	else
		return false;
}

//следующий элемент списка
//передаваемые параметры: позиция элемента
//возвращаемое значение: позиция элемента, после исходной
position MyList::next(const position &pos) const
{
	if ((pos <= count_) && (pos > 0))
		return pos + 1;
	else
		return -1;
}

//предыдущий элемент списка
//передаваемые параметры: позиция элемента
//возвращаемое значение: позиция элемента, перед исходной
position MyList::previous(const position &pos) const
{
	if ((pos <= count_) && (pos > 1))
		return pos - 1;
	else
		return -1;
}

//обнуление массива
//передаваемые параметры: 
//возвращаемое значение: 
void MyList::makeNull()
{
	count_ = 0;
}

//начало списка
//передаваемые параметры: 
//возвращаемое значение: позиция первого элемента списка 
position MyList::first() const
{
	return 1;
}

//сравнение элементов списка
//передаваемые параметры: позиция 1-ого элемента, позиция 2-ого элемента
//возвращаемое значение: true -- элементы равны, false -- элементы не равны
bool MyList::cmpElem(const position &f, const position &s) const
{
	return list_[f - 1].info.cmpDat(list_[s - 1].info);
}

//инициализация массива из файла
//передаваемые параметры: список для инициализации
//возвращаемое значение: 
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
