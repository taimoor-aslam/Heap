#include"Heap.h"
Heap::Heap(int s)
{
	size = s;
	arr = new int[size];
	noOfElements = 0;
}
//min heap
void Heap::insert(int val)
{
	if (noOfElements > size)
	{
		cout << "Sorry! you can't insert anymore value";
		cout << " due to overflow.";
	}
	else
	{
		noOfElements++;
		int i = noOfElements;
		int j = i;
		if (noOfElements == 1)
		{
			arr[i] = val;
		}
		else
		{
			arr[i] = val;
			while (j > 0)
			{
				if (arr[j / 2] > arr[j])
				{
					swap(arr[j/2], arr[j]);
					j = j / 2;
				}
				else
				{
					break;
				}
			}
		} 
	}
}
void Heap::heapify(int s, int i)
{
	int max = i;
	int left = 2 * i;
	int right = (2 * i) + 1;
	if (left< s && arr[left]>arr[max])
	{
		max = left;
	}
	if (right< s && arr[right]> arr[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(arr[i], arr[max]);
		heapify(s, max);
	}
}
void Heap::heapsort()
{
	for (int i = (noOfElements / 2) ;i >=0;i--)
	{
		heapify(noOfElements, i);
	}
	for (int i = noOfElements;i >= 0;i--)
	{
		swap(arr[0], arr[i]);
		heapify(i, 0);
	}
}

int Heap::Delete()
{
	if (noOfElements == 0)
	{
		cout << "Sorry! There is no value in heap ";
		cout << "to delete. " << endl;
	}
	else
	{
		int temp = arr[1];
		swap(arr[1], arr[noOfElements]);
		noOfElements--;
		int i = 1;
		while (i <= noOfElements)
		{
			if ((i * 2) <= noOfElements && ((i * 2) + 1) <= noOfElements)
			{
				if (arr[i] > arr[2 * i] || arr[i] > arr[(2 * i) + 1])
				{
					if (arr[2 * i] < arr[(2 * i) + 1])
					{
						swap(arr[2 * i], arr[i]);
					}
					else
					{
						swap(arr[(2 * i) + 1], arr[i]);
					}
					i++;
				}
				else
				{
					break;
				}
			}
			else if ((i * 2) <= noOfElements)
			{
				if (arr[i] > arr[2 * i])
				{
					swap(arr[2 * i], arr[i]);
					i++;
				}
				else
				{
					break;
				}
			}
		}
		return temp;
	}
}

/*void Heap::reheapify(int i,int j)
{
	int index, leftChild, rightChild, max, temp;
	leftChild = 2 * i;
	rightChild = leftChild + 1;
	if (leftChild <= j)
	{
		max = arr[leftChild];
		index = leftChild;
		if (rightChild <= j)
		{
			if (arr[rightChild] > max)
			{
				max = arr[rightChild];
				index = rightChild;
			}
		}
		if (arr[i] < arr[index])
		{
			swap(arr[i], arr[index]);
			reheapify(i, j);
		}

	}

}
*/
/*int Heap::Delete()
{
	if (noOfElements == 0)
	{
		cout << "Sorry! There is no value is heap to delete." << endl;
	}
	else
	{
		int temp;
		while (noOfElements > 0)
		{
			temp = arr[1];
			arr[1] = arr[noOfElements];
			noOfElements--;
			reheapify(1, noOfElements);
			return temp;
		}
	}
}*/
void Heap::swap(int& x, int& y)
{
	int z = x;
	 x = y;
	 y = z;
}
void Heap::display()
{
	cout << "Contents in Heap are: ";
	for (int i = 1;i <=noOfElements;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
