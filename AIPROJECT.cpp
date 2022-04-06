#include<iostream>
using namespace std;

class Column
{
public:
	int c[3];
	int top;

public :
	Column()
	{
		top = -1;
	}
	bool check(int disk)
	{
		if (top == -1)
		{
			return true;
		}

		else if (disk > c[top])
		{
			return false;
		}
		else
		{
			return true;
		}

	}


	void add(int disk)
	{
		c[++top] = disk;
		cout << "top is :" << top << " value is: " << c[top] << endl;
	}

	int remove()
	{
		if (top >= 0)
			return c[top--];
		return -1;
	}

};


int x;
int y;

// choose which column to move disks in
int choosingcoltomove()
{
	int x;
	cout << "Choose which column to move to: ";
	cin >> x;
	return x;
}

// choose which column to move disks in
int choosingcoltoremove()
{
	int x;
	cout << "Choose which column to remove disk from: ";
	cin >> x;
	return x;
}



int main()
{
	Column arr[3];
	
	Column c1;
	c1.add(3);
	c1.add(2);
	c1.add(1);
	cout << "top is : " << c1.top << endl;

	Column c2;
	Column c3;

	arr[0] = c1;
	arr[1] = c2;
	arr[2] = c3;

	for (int i = 1; arr[2].top != 2; i++)
	{
		if (i == 1)
		{
			x = choosingcoltomove();
			y = 1;
		}
		else
		{
			x = choosingcoltomove();
			y = choosingcoltoremove();
		}
		int v = arr[y - 1].remove();
		if (arr[x-1].check(v))
		{
			arr[x - 1].add(v);
		}
		else
		{
			cout << "choose another column" << endl;
			x = choosingcoltomove();
			y = choosingcoltoremove();
			continue;
		}
		cout << "moved disk " << v << "from col " << y  << "to col " << x  << endl;
	}
	cout << "Congratulations! You solved the game" << endl;
}