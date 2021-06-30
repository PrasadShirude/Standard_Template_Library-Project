// Singly Circular Linked List using Generic Programming

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node * next;
};

template <class T>
class SinglyCL
{
private:
	struct node<T> * Head;
	struct node<T> * Tail;
	int iSize;

public:
	SinglyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);

};

template <class T>
SinglyCL<T>:: SinglyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

template <class T>
int SinglyCL<T>::Count()
{
	return iSize;
}

template <class T>
void SinglyCL<T>::Display()
{	
	struct node<T> * temp = Head;
	int i = 0;
	for(i =1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{	
	struct node<T> * newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;

	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->next = Head;
		Head = newn;
	}
	Tail->next = Head;
	iSize++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;

	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{	
		Tail->next = newn;
		Tail = newn;
	}
	Tail->next = Head;
	iSize++;
}

template <class T>
void SinglyCL<T>::InsertAtPosition(T no,int iPos)
{
	if(iPos < 1 || (iPos > iSize +1))
	{
		return;
	}

	if(iPos == 1)
	{
		SinglyCL<T>::InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		SinglyCL<T>::InsertLast(no);
	}
	else
	{		
		struct node<T> * temp = Head;

		struct node<T> * newn = new struct node<T>;
		newn->data = no;
		newn->next = NULL;

		int i =0;
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

		iSize++;
	}
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{	
	struct node<T> * temp = Head;

	if(Head == NULL && (Tail == NULL))
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
		temp = Head;
		Head = Head->next;
		free(temp);
	}
	iSize--;

}

template <class T>
void SinglyCL<T>::DeleteLast()
{
	struct node<T> * temp = Head;

	if(Head == NULL && (Tail == NULL))
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
		int i =0;
		for(i=1;i<iSize;i++)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		free(Tail);
		Tail = temp;
	}
	Tail->next = Head;
	iSize--;
		
}

template <class T>
void SinglyCL<T>::DeleteAtPosition(int iPos)
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
		SinglyCL<T>::DeleteFirst();
	}
	else if(iPos == iSize)
	{
		SinglyCL<T>::DeleteLast();
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
		free(target);
		iSize--;
	}
}
int main()
{
	SinglyCL <int> obj1;
	int iChoice1 = 1,iValue1 = 0,iRet=0,iPos1 = 0 ;

	SinglyCL <char> obj2;
	int iChoice2 = 1,iPos2  =0;
	char cValue;

	SinglyCL <double> obj3;
	int iChoice3=1,iPos3 = 0;
	double dValue = 0.0;

	int iChoice = 1;
	while(iChoice != 0)
	{
		cout<<"\n--------------------------------------------------------------------------\n\n";
		cout<<"\t\tMain Menu\t\t\n\n";
		cout<<"\t1: SinglyCL with <int> datatype\n";
		cout<<"\t2: SinglyCL with <char> datatype\n";
		cout<<"\t3: SinglyCL with <double> datatype\n";
		cout<<"\t0: Terminate the Application\n\n";
		cout<<"Enter your choice : ";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				while(iChoice1 != 0)
				{
					cout<<"\n-------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert at given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete At given Position\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"Enter your choice : ";
					cin>>iChoice1;

					cout<<"\n-------------------------------------------------------------------------\n\n";

					switch(iChoice1)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>iValue1;
							obj1.InsertFirst(iValue1);
							break;

						case 2:
							cout<<"Enter the elements you want to insert : ";
							cin>>iValue1;
							obj1.InsertLast(iValue1);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos1;
							cout<<"Enter the elements you want to insert : ";
							cin>>iValue1;
							obj1.InsertAtPosition(iValue1,iPos1);
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
							cout<<"Linked List contains \n";
							obj1.Display();
							break;

						case 8:
							iRet = obj1.Count();
							cout<<"No.of nodes : "<<iRet;
							break;

						case 0:
							cout<<"THANK YOU!!!\n";
							break;

						default:
							cout<<"Enter valid choice \n";
							break;

					}//end of case 1 switch / iChoice1 
				}//end of case 1 while
				break;

			case 2:
				while(iChoice2 != 0)
				{
					cout<<"\n-------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert at given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete At given Position\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"Enter your choice : ";
					cin>>iChoice2;

					cout<<"\n-------------------------------------------------------------------------\n\n";

					switch(iChoice2)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>cValue;
							obj2.InsertFirst(cValue);
							break;

						case 2:
							cout<<"Enter the elements you want to insert : ";
							cin>>cValue;
							obj2.InsertLast(cValue);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos2;
							cout<<"Enter the elements you want to insert : ";
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
							cout<<"Linked List contains \n";
							obj2.Display();
							break;

						case 8:
							iRet = obj2.Count();
							cout<<"No.of nodes : "<<iRet;
							break;

						case 0:
							cout<<"THANK YOU!!!\n";
							break;

						default:
							cout<<"Enter valid choice \n";
							break;

					}//end of case 2 switch / iChoice2 
				}//end of case 2 while
				break;

			case 3:
				while(iChoice3 != 0)
				{
					cout<<"\n-------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert at given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete At given Position\n";
					cout<<"\t7: Display\n";
					cout<<"\t8: Count\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"Enter your choice : ";
					cin>>iChoice3;

					cout<<"\n-------------------------------------------------------------------------\n\n";

					switch(iChoice3)
					{
						case 1:
							cout<<"Enter the elements you want to insert : ";
							cin>>dValue;
							obj3.InsertFirst(dValue);
							break;

						case 2:
							cout<<"Enter the elements you want to insert : ";
							cin>>dValue;
							obj3.InsertLast(dValue);
							break;

						case 3:
							cout<<"Enter the position : ";
							cin>>iPos3;
							cout<<"Enter the elements you want to insert : ";
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
							cout<<"Linked List contains \n";
							obj3.Display();
							break;

						case 8:
							iRet = obj3.Count();
							cout<<"No.of nodes : "<<iRet;
							break;

						case 0:
							cout<<"THANK YOU!!!\n";
							break;

						default:
							cout<<"Enter valid choice \n";
							break;

					}//end of case 3 switch / iChoice3 
				}//end of case 3 while
				break;

			case 0:
				cout<<"THANK YOU For using SinglyCL\n";
				break;

			default:
				cout<<"Enter valid choice\n";
				break;


		}//end of main switch / iChoice
	}//end of main while
	

	return 0;
}