#include<iostream>
using namespace std;

template <class T>
struct nodeQ
{
	int data;
	struct nodeQ * next;
};

template <class T>
class Queue
{
private:
	struct nodeQ<T> * Head;
	int iSize;

public:
	Queue();
	int Count();
	void Display();
	void Add(T);
	T Delete();	
};

template <class T>
Queue<T>::Queue()
{
	Head = NULL;
	iSize = 0;
}

template <class T>
int Queue<T>::Count()
{
	return iSize;
}

template <class T>
void Queue<T>::Display()
{
	struct nodeQ<T> * temp = Head;

	cout<<"\n|";
	while(temp != NULL)
	{
		cout<<temp->data<<"|";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
void Queue<T>::Add(T no)
{
	struct nodeQ<T> * newn = new struct nodeQ<T>;
	struct nodeQ<T> * temp = Head;

	newn->data = no;
	newn->next = NULL;

	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	iSize++;
}

template <class T>
T Queue<T>::Delete()
{
	struct nodeQ<T> * temp = Head;
	T Ret;
	if(Head == NULL)
	{
		return -1;
	}
	else
	{
		Head = Head->next;
		Ret = temp->data;
		free(temp);
	}
	iSize--;
	return Ret;
}

int main()
{
	int iChoice = 1;

	int iChoice1 = 1;
	int iValue = 0;

	int iChoice2 = 1;
	char cValue;

	int iChoice3 = 1;
	double dValue = 0.0;

	Queue <int> obj16;
	Queue <char> obj17;
	Queue <double> obj18;

	while(iChoice != 0)
	{
		cout<<"\n------------------------------------------------------------------------------------\n";
		cout<<"\t\tQueue Menu\n\n";
		cout<<"\t1: Queue wit <int> datatype\n";
		cout<<"\t2: Queue wit <char> datatype\n";
		cout<<"\t3: Queue wit <double> datatype\n";
		cout<<"\t0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;

		cout<<"\n------------------------------------------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:

				break;

			case 2:	

				break;

			case 3:

				break;

			case 0:
				break;

			default:
				cout<<"Please enter valid choice\n";
				break;
		}//end of queue switch
	}//end of queue while
	while(iChoice1 != 0)
	{
		cout<<"\n------------------------------------------------------------------------------------\n";
		cout<<"\t\tQueue\n\n";
		cout<<"\t1: ADD\n";
		cout<<"\t2: DELETE\n";
		cout<<"\t3: Display\n";
		cout<<"\t4: Count\n";
		cout<<"\t0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice1;

		cout<<"\n------------------------------------------------------------------------------------\n";

		switch(iChoice1)
		{
			case 1:
				cout<<"Enter the element you want to add : ";
				cin>>iValue;
				obj16.Add(iValue);
				break;

			case 2:
				cout<<"Element deleted is : "<<obj16.Delete()<<"\n";
				break;

			case 3:
				cout<<"Queue contains \n";
				obj16.Display();
				break;

			case 4:
				cout<<"Total element in Queue : "<<obj16.Count()<<"\n";
				break;

			case 0:
				break;

			default:
				cout<<"Please enter valid choice\n";
				break;
		}//end of queue case 1 switch	
	}//end of queue case 1 while
	return 0;
}

