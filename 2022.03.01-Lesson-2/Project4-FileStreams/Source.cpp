#include<iostream>
#include<fstream>

void example1(int argc, char* argv[])
{
	std::ifstream fin;
	if (argc > 1)
	{
		std::cout << argv[0] << std::endl;
		std::cout << argv[1] << std::endl;
		fin.open(argv[1]);
	}
	else
	{
		fin.open("1.txt");
	}
	int a = 0;
	int b = 0;
	fin >> a >> b;
	int sum = a + b;
	std::cout << sum << std::endl;
	fin.close();
}

void example2(int argc, char* argv[])
{
	std::ifstream fin;
	fin.open("1.txt");
	int sum = 0;
	while (!fin.eof())
	{
		int x = 0;
		fin >> x;
		sum += x;
	}
	std::cout << sum;
	fin.close();
}

void example3(int argc, char* argv[])
{
	std::ifstream fin("3.txt");
	if (fin)
	{
		int x = 0;
		fin >> x;
		std::cout << x;
		fin.close();
	}
	else
	{
		std::cout << "no file was opened" << std::endl;
	}
}

void example4(int argc, char* argv[])
{
	std::fstream fin("3.txt", std::ios_base::in);
	if (fin)
	{
		int sum = 0;
		while (!fin.eof())
		{
			int x = 0;
			fin >> x;
			sum += x;
		}
		std::cout << sum << std::endl;
		fin.close();
		fin.open("3.txt", std::ios_base::out);
		fin << sum << std::endl;
		fin.close();
	}
	else
	{
		std::cout << "no file was opened" << std::endl;
	}
}

void example5(int argc, char* argv[])
{
	std::ofstream fout;
	fout.open("out1.txt", std::ios_base::trunc);
	if (!fout.fail())
	{
		for (int i = 0; i < 10; ++i)
		{
			fout << i << " ";
		}
		fout.close();
		fout.open("out1.txt", std::ios_base::app);
		fout.close();
	}
	else
	{
		std::cout << "error opening file";
	}
}

struct PointInfo //DTO - Data Transfering Object
{
	int x;
	int y;
	PointInfo(int x = 0, int y = 0) : x(x), y(y) {}
};

void example6(int argc, char* argv[])
{
	const int len = 10;
	PointInfo point[len];
	for (int i = 0; i < len; ++i)
	{
		point[i] = PointInfo(rand() % 10 + 10, rand() % 10 + 10);
	}
	for (int i = 0; i < len; ++i)
	{
		printf("(%d;%d) ", point[i].x, point[i].y);
	}
	printf("\n");

	std::fstream fbin;
	fbin.open("db.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app);
	if (!fbin.fail())
	{
		for (int i = 0; i < len; ++i)
		{
			fbin.write((char*)&point[i], sizeof(PointInfo));
		}
		fbin.close();

		fbin.open("db.bin", std::ios_base::binary | std::ios_base::out);
		fbin.write((char*)point, sizeof(PointInfo) * len);
		fbin.close();

		PointInfo point2[len];
		fbin.open("db.bin", std::ios_base::binary | std::ios_base::in);
		fbin.read((char*)point2, sizeof(PointInfo) * len);
		fbin.close();
		for (int i = 0; i < len; ++i)
		{
			printf("(%d;%d) ", point2[i].x, point2[i].y);
		}
		printf("\n");
	}
	else
	{
		std::cout << "Some errors ocurred while opening the binary file";
	}
}

void example7(int argc, char* argv[])
{
	const int len = 10;
	PointInfo point[len];
	for (int i = 0; i < len; ++i)
	{
		point[i] = PointInfo(rand() % 10 + 10, rand() % 10 + 10);
	}
	for (int i = 0; i < len; ++i)
	{
		printf("(%d;%d) ", point[i].x, point[i].y);
	}
	printf("\n");

	std::fstream fbin;
	fbin.open("db.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app);
	if (!fbin.fail())
	{
		for (int i = 0; i < len; ++i)
		{
			fbin.write((char*)&point[i], sizeof(PointInfo));
		}
		fbin.close();

		fbin.open("db.bin", std::ios_base::binary | std::ios_base::out);
		fbin.write((char*)point, sizeof(PointInfo) * len);
		fbin.close();

		PointInfo point2[len];
		fbin.open("db.bin", std::ios_base::binary | std::ios_base::in);
		fbin.read((char*)point2, sizeof(PointInfo) * len);
		fbin.close();
		for (int i = 0; i < len; ++i)
		{
			printf("(%d;%d) ", point2[i].x, point2[i].y);
		}
		printf("\n");
	}
	else
	{
		std::cout << "Some errors ocurred while opening the binary file";
	}
}

int main(int argc, char* argv[])
{
	example6(argc, argv);
	return 0;
}
