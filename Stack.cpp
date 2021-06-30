#include<iostream>
using namespace std;


template <class T>
struct nodeS
{
	T data;
	struct nodeS * next;
};

template <class T>
class Stack
{
private:
	struct nodeS<T> * Head;
	int iSize;

public:
	Stack();
	void PUSH(T);
	T POP();
	void Display();
	int Count();
	T PEEK();
};

template <class T>
Stack<T>::Stack()
{
	Head = NULL;
	iSize = 0;
}

template <class T>
void Stack<T>::PUSH(T no)
{
	struct nodeS<T> * newn = new struct nodeS<T>;

	newn->data = no;
	newn->next = NULL;

	newn->next= Head;
	Head = newn;
	iSize++;
}

template <class T>
T Stack<T>::POP()
{	
	struct nodeS<T> * temp = Head;
	T Ret;

	if(iSize == 0)
	{
		cout<<"Stack is empty\n";
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

template <class T>
void Stack<T>::Display()
{
	struct nodeS<T> * temp = Head;

	cout<<"\n";
	while(temp != NULL)
	{
		cout<<"\t|"<<temp->data<<"|\n";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
	return iSize;
}

template <class T>
T Stack<T>::PEEK()
{
	struct nodeS<T> * temp = Head;
	T Ret;

	if(iSize == 0)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		Ret = temp->data;
		return Ret;
	}
}

int main()
{	
	int iChoice =1;

	int iChoice1 =1;
	int iValue = 0;

	int iChoice2 = 1;
	char cValue;

	int iChoice3 = 1;
	double dValue = 0.0;

	Stack <int> obj1;
	Stack <char> obj2;
	Stack <double> obj3;

	while(iChoice != 0)
	{
		cout<<"\n-----------------------------------------------------------------------\n";
		cout<<"\t\t Stack Menu\n\n";
		cout<<"\t1: Stack with <int> datatype\n";
		cout<<"\t2: Stack with <char> datatype\n";
		cout<<"\t3: Stack with <double> datatype\n";
		cout<<"\t0: Exit\n\n";
		cout<<"Enter your choice : ";
		cin>>iChoice;
		cout<<"\n-----------------------------------------------------------------------\n";
	
		switch(iChoice)
		{
			case 1:
				while(iChoice1 != 0)
				{
					cout<<"\n-----------------------------------------------------------------------\n";
					cout<<"\t\t Stack\n\n";
					cout<<"\t1: PUSH\n";
					cout<<"\t2: POP\n";
					cout<<"\t3: Display\n";
					cout<<"\t4: Count\n";
					cout<<"\t5: PEEK\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice1;
					cout<<"\n-----------------------------------------------------------------------\n";
					switch(iChoice1)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>iValue;
							obj1.PUSH(iValue);
							break;

						case 2:
							cout<<"Popped element is : "<<obj1.POP()<<"\n";
							break;

						case 3:
							cout<<"Stack contains\n";
							obj1.Display();
							break;

						case 4:
							cout<<"Total elements in Stack : "<<obj1.Count()<<"\n";
							break;

						case 5:
							cout<<"Peeked element is : "<<obj1.PEEK()<<"\n";
							break;

						case 0:
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of stack case1 switch
				}//end of stack case1 while
				break;

			case 2:
				while(iChoice2 != 0)
				{
					cout<<"\n-----------------------------------------------------------------------\n";
					cout<<"\t\t Stack\n\n";
					cout<<"\t1: PUSH\n";
					cout<<"\t2: POP\n";
					cout<<"\t3: Display\n";
					cout<<"\t4: Count\n";
					cout<<"\t5: PEEK\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice2;
					cout<<"\n-----------------------------------------------------------------------\n";
					switch(iChoice2)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>cValue;
							obj2.PUSH(cValue);
							break;

						case 2:
							cout<<"Popped element is : "<<obj2.POP()<<"\n";
							break;

						case 3:
							cout<<"Stack contains\n";
							obj2.Display();
							break;

						case 4:
							cout<<"Total elements in Stack : "<<obj2.Count()<<"\n";
							break;

						case 5:
							cout<<"Peeked element is : "<<obj2.PEEK()<<"\n";
							break;

						case 0:
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of stack case2 switch
				}//end of stack case2 while
				break;

			case 3:
				while(iChoice3 != 0)
				{
					cout<<"\n-----------------------------------------------------------------------\n";
					cout<<"\t\t Stack\n\n";
					cout<<"\t1: PUSH\n";
					cout<<"\t2: POP\n";
					cout<<"\t3: Display\n";
					cout<<"\t4: Count\n";
					cout<<"\t5: PEEK\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice3;
					cout<<"\n-----------------------------------------------------------------------\n";
					switch(iChoice3)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>dValue;
							obj3.PUSH(dValue);
							break;

						case 2:
							cout<<"Popped element is : "<<obj3.POP()<<"\n";
							break;

						case 3:
							cout<<"Stack contains\n";
							obj3.Display();
							break;

						case 4:
							cout<<"Total elements in Stack : "<<obj3.Count()<<"\n";
							break;

						case 5:
							cout<<"Peeked element is : "<<obj3.PEEK()<<"\n";
							break;

						case 0:
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of stack case3 switch
				}//end of stack case3 while
				break;

			case 0:
				break;

			default:
				cout<<"Enter valid choice\n";
				break;

		}//end of stack switch
	}// end of stack while
	

	return 0;
}