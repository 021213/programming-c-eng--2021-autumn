#include "array.h"

using namespace std;

int main(){
	MyList list;
	list.initList();
	list.insert({"vasya", "pupkin.net"}, list.first());
	list.insert({"vasya", "yandex.ru"}, list.first());
	list.insert({"vasya", "banana.com"}, list.first());
	list.insert({"tanya", "pupkin.net"}, list.first());
	list.insert({"vasya", "pupkin.net"}, list.first());
	list.insert({"vanya", "pupkin.net"}, list.first());
	list.insert({"tanya", "pupkin.net"}, list.first());
	cout << list << endl;
	position p = list.first(), q;
	while(p!=list.end()){
		q = list.next(p);
		while(q != list.end())
		if (list.retrieve(p).cmpDat(list.retrieve(q)))
			list.delete_elem(q);
		else
			q = list.next(q);
		p = list.next(p);
	}
	cout << endl << list;
	
	
	return 0;
}
