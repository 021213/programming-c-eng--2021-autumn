#include<iostream>

using namespace std;

class RangeTree
{
private:
	int* data;
	int len;
	int* rangeMax;

	void buildMaxRec(int v, int l, int r)
	{
		if (l == r)
		{
			rangeMax[v] = l;
		}
		else
		{
			int m = (l + r) / 2;
			buildMaxRec(2 * v + 1, l, m);
			buildMaxRec(2 * v + 2, m + 1, r);
			int li = rangeMax[2 * v + 1];
			int ri = rangeMax[2 * v + 2];
			if (li == -1 && ri == -1)
			{
				rangeMax[v] = -1;
			}
			else if (ri == -1)
			{
				rangeMax[v] = li;
			}
			else
			if (data[li] >= data[ri])
			{
				rangeMax[v] = li;
			}
			else
			{
				rangeMax[v] = ri;
			}
		}
	}

	int getMaxIRec(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
		{
			return -1;
		}
		if (tl == l && tr == r)
		{
			return rangeMax[v];
		}
		int tm = (tl + tr) / 2;
		int li = getMaxIRec(2 * v + 1, tl, tm, l, min(r, tm));
		int ri = getMaxIRec(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
		if (li == -1 && ri == -1)
		{
			return -1;
		}
		if (li == -1)
		{
			return ri;
		}
		if (ri == -1)
		{
			return li;
		}
		if (data[li] >= data[ri])
		{
			return li;
		}
		else
		{
			return ri;
		}
	}

public:
	RangeTree(int* data = 0, int len = 0) : data(data), len(len)
	{
		rangeMax = new int[4 * len + 1];
		for (int i = 0; i < 4 * len + 1; ++i)
		{
			rangeMax[i] = -1;
		}
		buildMaxRec(0, 0, len - 1);
	}
	~RangeTree()
	{
		delete[] rangeMax;
	}
	int maxEl(int l, int r)
	{
		int index = maxIndex(l, r);
		if (index == -1)
		{
			return -1;
		}
		return data[index];
	}
	int maxIndex(int l, int r)
	{
		return (l > r ? getMaxIRec(0, 0, len - 1, r, l) : getMaxIRec(0, 0, len - 1, l, r));
	}
	void printRangeMax()
	{
		for (int i = 0; i < 4 * len + 1; ++i)
		{
			cout << rangeMax[i] << " ";
		}
		cout << endl;
	}
	void update(int index, int newValue) //TODO: hometask till May 6
	{

	}

};

int main()
{
	const int n = 9;
	int* data = new int[n] {1, 5, 4, 7, 6, 3, 2, 8, 9};
	/*
	for (int i = 0; i < n; ++i)
	{
		data[i] = rand() % 10;
	}
	*/
	for (int i = 0; i < n; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;

	RangeTree tree(data, n);

	for (int i = 0; i < 10; ++i)
	{
		int l = 0;
		int r = 0;
		cin >> l >> r;
		cout << "[" << l << ";" << r << "]" << tree.maxEl(l, r) << endl;
	}

	delete[] data;
	return 0;
}