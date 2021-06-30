#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node * next;
	struct node * prev;
};

template <class T>
class DoublyCL
{	
private:
	struct node<T> * Head;
	struct node<T> * Tail;
	int iSize;

public:
	DoublyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);
	void Display();
	int Count();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
	struct node<T> * temp = Head;

	int i =0;
	for(i=1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|<=>";
		temp = temp->next;
	}
}

template <class T>
int DoublyCL<T>::Count()
{
	return iSize;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		newn->next->prev = newn;
	}
	Tail->next = Head;
	Head->prev = Tail;
	iSize++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{	
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}
	Head->prev = Tail;
	Tail->next = Head;
	iSize++;
}


template <class T>
void DoublyCL<T>::InsertAtPosition(T no,int iPos)
{
	if((iPos < 1) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 1)
	{
		DoublyCL<T>::InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		DoublyCL<T>::InsertLast(no);
	}
	else
	{
		struct node<T> * newn = new struct node<T>;
		struct node<T> * temp = Head;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		int i =0;
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		newn->prev = temp;
		newn->next->prev = newn;

		iSize++;
	}
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
	if((Head == NULL) && (Tail == NULL))
	{
		return;
	}

	if(iSize == 1)
	{
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		struct node<T> * temp = Head;

		Head = Head->next;
		free(temp); 
	}
	Head->prev= Tail;
	Tail->next = Head;
	iSize--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
	if((Head == NULL) && (Tail == NULL))
	{
		return;
	}

	if(iSize == 1)
	{
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		struct node<T> * temp = Head;

		int i =0;
		for(i=1;i<iSize-1;i++)
		{
			temp = temp->next;
		} 
		free(temp->next);
		Tail = temp;
	}
	Head->prev= Tail;
	Tail->next = Head;
	iSize--;
}


template <class T>
void DoublyCL<T>::DeleteAtPosition(int iPos)
{
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	if((Head == NULL) && (Tail == NULL))
	{
		return;
	}

	if(iPos == 1)
	{
		DoublyCL<T>::DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DoublyCL<T>::DeleteLast();
	}
	else
	{
		struct node<T> * temp = Head;
		struct node<T> * target = NULL;

		int i =0;
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}		

		target = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		free(target);

		iSize--;
	}
}
int main()
{	

	DoublyCL <int> obj1;
	int iChoice1 =1, iPos1 =0,iRet =0;
	int iValue = 0;

	DoublyCL <char> obj2;
	int iChoice2 =1, iPos2 =0;
	char cValue;

	DoublyCL <double> obj3;
	int iChoice3 =1, iPos3 =0;
	double dValue = 0;

	int iChoice = 1;

	while(iChoice != 0)
	{
		cout<<"\n----------------------------------------------------------------------------------\n";
		cout<<"\t\tMain Menu\n\n";
		cout<<"\t1: DoublyCL with <int> datatype\n";
		cout<<"\t2: DoublyCL with <char> datatype\n";
		cout<<"\t3: DoublyCL with <double> datatype\n";
		cout<<"\t0: Terminate the Application\n\n";
		cout<<"\tEnter your choice : ";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				while(iChoice1 != 0)
				{
					cout<<"\n------------------------------------------------------------------------------------------\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: InsertFirst\n";
					cout<<"\t2: InsetLast\n";
					cout<<"\t3: InsertAtPosition\n";
					cout<<"\t4: DeleteFirst\n";
					cout<<"\t5: DeleteLast\n";
					cout<<"\t6: DeleteAtPosition\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice1;
					cout<<"\n------------------------------------------------------------------------------------------\n";

					switch(iChoice1)
					{
						case 1:
							cout<<"Enter the element to insert : ";
							cin>>iValue;
							obj1.InsertFirst(iValue);
							break;

						case 2:
							cout<<"Enter the element to insert : ";
							cin>>iValue;
							obj1.InsertLast(iValue);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos1;
							cout<<"Enter the element to insert : ";
							cin>>iValue;
							obj1.InsertAtPosition(iValue,iPos1);
							break;

						case 4:
							obj1.DeleteFirst();
							break;

						case 5:
							obj1.DeleteLast();
							break;

						case 6:
							cout<<"Enter the position : ";
							cin>>iPos1;
							obj1.DeleteAtPosition(iPos1);
							break;

						case 7:
							cout<<"Linked List Contains\n";
							obj1.Display();
							break;

						case 8:
							iRet = obj1.Count();
							cout<<"Total elements in the Linked List : "<<iRet<<"\n";
							break;

						case 0:
							cout<<"Thank You!!\n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;

					}//end of case 1 switch
				}//end of case 1 while
				break;
				
			case 2:
				while(iChoice2 != 0)
				{
					cout<<"\n------------------------------------------------------------------------------------------\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: InsertFirst\n";
					cout<<"\t2: InsetLast\n";
					cout<<"\t3: InsertAtPosition\n";
					cout<<"\t4: DeleteFirst\n";
					cout<<"\t5: DeleteLast\n";
					cout<<"\t6: DeleteAtPosition\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice2;
					cout<<"\n------------------------------------------------------------------------------------------\n";

					switch(iChoice2)
					{
						case 1:
							cout<<"Enter the element to insert : ";
							cin>>cValue;
							obj2.InsertFirst(cValue);
							break;

						case 2:
							cout<<"Enter the element to insert : ";
							cin>>cValue;
							obj2.InsertLast(cValue);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos2;
							cout<<"Enter the element to insert : ";
							cin>>cValue;
							obj2.InsertAtPosition(cValue,iPos2);
							break;

						case 4:
							obj2.DeleteFirst();
							break;

						case 5:
							obj2.DeleteLast();
							break;

						case 6:
							cout<<"Enter the position : ";
							cin>>iPos2;
							obj2.DeleteAtPosition(iPos2);
							break;

						case 7:
							cout<<"Linked List Contains\n";
							obj2.Display();
							break;

						case 8:
							iRet = obj2.Count();
							cout<<"Total elements in the Linked List : "<<iRet<<"\n";
							break;

						case 0:
							cout<<"Thank You!!\n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;

					}//end of case 2 switch
				}//end of case 2 while
				break;

			case 3:
				while(iChoice3 != 0)
				{
					cout<<"\n------------------------------------------------------------------------------------------\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: InsertFirst\n";
					cout<<"\t2: InsetLast\n";
					cout<<"\t3: InsertAtPosition\n";
					cout<<"\t4: DeleteFirst\n";
					cout<<"\t5: DeleteLast\n";
					cout<<"\t6: DeleteAtPosition\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit\n\n";
					cout<<"Enter your choice : ";
					cin>>iChoice3;
					cout<<"\n------------------------------------------------------------------------------------------\n";

					switch(iChoice3)
					{
						case 1:
							cout<<"Enter the element to insert : ";
							cin>>dValue;
							obj3.InsertFirst(dValue);
							break;

						case 2:
							cout<<"Enter the element to insert : ";
							cin>>dValue;
							obj3.InsertLast(dValue);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos3;
							cout<<"Enter the element to insert : ";
							cin>>dValue;
							obj3.InsertAtPosition(dValue,iPos3);
							break;

						case 4:
							obj3.DeleteFirst();
							break;

						case 5:
							obj3.DeleteLast();
							break;

						case 6:
							cout<<"Enter the position : ";
							cin>>iPos3;
							obj3.DeleteAtPosition(iPos3);
							break;

						case 7:
							cout<<"Linked List Contains\n";
							obj3.Display();
							break;

						case 8:
							iRet = obj3.Count();
							cout<<"Total elements in the Linked List : "<<iRet<<"\n";
							break;

						case 0:
							cout<<"Thank You!!\n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;

					}//end of case 3 switch
				}//end of case 3 while
				break;

			case 0:
				cout<<"Thank you for using DoublyCL\n";
				break;

			default:
				cout<<"Enter valid choice \n";
				break;	
		}//end of main switch
	}// end of main while

	
	
	return 0;
}