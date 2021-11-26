#include"Header.h"

using namespace std;
//Task 1
template<typename T>
void _swap(T& ptr1, T& ptr2)
{
	T tmpPtr = ptr1;
	ptr1 = ptr2;
	ptr2 = tmpPtr;
}

//Task 2
template<typename T>
void sortPointer(vector<T>& vect)
{
	sort(vect.begin(), vect.end(), [](T vect1, T vect2) {return *vect1 < *vect2; });
}

int main()
{
	setlocale(0, "");
	//Task 1
	cout << "Task 1\n";
	int* ptr1 = new int(123);
	int* ptr2 = new int(987);
	cout << "ptr1: " << *ptr1 << "\nptr2: " << *ptr2 << endl;
	_swap(ptr1, ptr2);
	cout << "ptr1: " << *ptr1 << "\nptr2: " << *ptr2 << endl;

	//Task 2
	cout << "\nTask 2\n";
	vector<int*> vec;
	for (int i=0; i < 10; ++i)
		vec.push_back(new int(rand()%100));

	for (auto& ptr : vec)
		cout << *ptr << endl;

	sortPointer(vec);
	cout << endl;
	for (auto& ptr : vec)
		cout << *ptr << endl;

	//Task 3
	cout << "\nTask 3\n";
	
	ifstream file("“олстой Ћев. ¬ойна и мир.txt");
	string symbols = "ја”уќоџыЁэя€ёю®Є»и≈е";
	string str;
	string tmpStr;

	while (!file.eof())
	{
		getline(file, tmpStr);
		str += tmpStr;

	}

	//count if and find
	{
		auto cmp = [&symbols](char symb)
		{
		 
			if (symbols.find(symb) != -1)
				return true;
			else
				return false;
			
		};

		int count = 0;
		Timer timer("count_if and find");

		count += count_if(str.begin(), str.end(), cmp);
		timer.print();
		cout << count << endl;
	}

	//count if and for
	{
		auto cmp = [&symbols](char symb)
		{
			for (auto& findSymb : symbols)
			{
				if (findSymb == symb)
					return true;
			}
			return false;
		};

		int count = 0;
		Timer timer("count_if and for");
		count += count_if(str.begin(), str.end(), cmp);
		timer.print();
		cout << count << endl;
	}

	//for and find
	{
		int count = 0;
		int ptrToChar = 0;
		Timer timer("for and find");
		for (auto& findSymb : symbols)
		{
			while (true)
			{
				ptrToChar = str.find(findSymb,++ptrToChar);
				if (ptrToChar == -1)
					break;
				count++;
			}

		}
		timer.print();
		cout << count << endl;
	}

	//for and for
	{
		int count = 0;
		Timer timer("for and for");
		for (auto& findSymb : symbols)
		{
			for (auto& symb : str)
			{
				if (findSymb == symb)
					++count;
			}
		}
		timer.print();
		cout << count << endl;
	}
}
/*
¬ыводы: count_if медленнее сканирует строку чем цикл for, find быстрее с count_if 
чем count_if с циклом for, цикл for с find медленнее чем два цикла for потому что 
приходитьс€ делать больше вычеслений.
*/