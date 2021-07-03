#include"Heap.h"

int main()
{
	Heap h(10);
	int val;
	for (int i = 0;i < 5;i++)
	{
		cout << "Enter value: ";
		cin >> val;
		h.insert(val);
	}
	h.display();
	cout << endl;
	h.Delete();
	h.Delete();
	h.display();
	//h.heapsort();
	//h.display();
	system("pause");
}