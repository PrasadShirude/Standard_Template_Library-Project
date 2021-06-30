// generic programming implementing Singly Linked List

#include<iostream>
using namespace std;

template <class T>

struct node
{
	T data;
	struct node * next;
};

template <class T>
class SinglyLL
{
private:
	struct node<T> * Head;
	int iSize;

public:
	SinglyLL();
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
SinglyLL<T>:: SinglyLL()
{
	Head = NULL;
	iSize = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
	struct node<T> * temp = Head;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
	return iSize;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;

	newn->next = Head;
	Head = newn;
	iSize++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;

	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		struct node<T> *temp = Head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
	iSize++;
}

template <class T>
void SinglyLL<T>::InsertAtPosition(T no,int iPos)
{
	if((iPos < 1) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 1)
	{
		SinglyLL<T>::InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		SinglyLL<T>::InsertLast(no);
	}
	else
	{
		struct node<T> * newn = new struct node<T>;

		newn->data = no;
		newn->next = NULL;
	
		struct node<T> * temp = Head;

		for(int i =1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
		iSize++;
	}
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{	
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}
	else if(iSize == 1)
	{
		free(Head);
		Head = NULL;
		iSize--;
	}
	else
	{
		struct node<T> *temp = Head;
		Head = Head->next;
		free(temp);
		iSize--;
	}
}

template <class T>
void SinglyLL<T>::DeleteLast()
{	
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}
	else if(iSize == 1)
	{
		free(Head);
		Head = NULL;
		iSize--;
	}
	else
	{
		struct node<T> *temp = Head;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		iSize--;
	}
}

template <class T>
void SinglyLL<T>::DeleteAtPosition(int iPos)
{
	if(iPos == 1)
	{
		SinglyLL<T>::DeleteFirst();
	}
	else if(iPos == iSize)
	{
		SinglyLL<T>::DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		struct node<T> *target = NULL;

		for(int i = 1;i<iPos-1;i++)
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
	int iChoice = 1;

	SinglyLL <int> obj1;
	int iChoice1 = 1,iPos1 = 0;
	int Ret, iValue;

	SinglyLL <double> obj2;
	int iChoice2 = 1,iPos2 = 0;
	double dValue;

	SinglyLL <char> obj3;
	int iChoice3 = 1,iPos3 = 0;
	char cValue;
	while(iChoice != 0)
	{
		cout<<"\n--------------------------------------------------------------------------------\n";
		cout<<"\t\tMain Menu\n\n";
		cout<<"\t1: Singly Linked List with <int> datatype\n";
		cout<<"\t2: Singly Linked List with <double> datatype\n";
		cout<<"\t3: Singly Linked List with <char> datatype\n";
		cout<<"\t0: Exit Main Application\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;

		cout<<"\n--------------------------------------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:
				while(iChoice1 != 0)
				{
					cout<<"---------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert At given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete at given position\n";
					cout<<"\t7: Display Linked List\n";
					cout<<"\t8: Count Elements\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"Enter your choice : ";
					cin>>iChoice1;
					cout<<"--------------------------------------------------------------------------\n";
	

					switch(iChoice1)
					{
						case 1:
							cout<<"Enter the Element you want to insert : ";
							cin>>iValue;
							obj1.InsertFirst(iValue);
							break;

						case 2:
							cout<<"Enter the Element you want to insert : ";
							cin>>iValue;
							obj1.InsertLast(iValue);
							break;

						case 3:
							cout<<"Enter position : ";
							cin>>iPos1;
							cout<<"Enter the Element you want to insert : ";
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
							cout<<"Enter position : ";
							cin>>iPos1;
							obj1.DeleteAtPosition(iPos1);
							break;

						case 7:
							cout<<"Linked List :\n";
							obj1.Display();
							break;

						case 8:
							cout<<"Count of Elements is : "<<obj1.Count()<<"\n";
							break;

						case 0:
							cout<<"Thank you \n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of case 1 switch
				}// end of case 1 while
				break;
			case 2:

				while(iChoice2 != 0)
				{
					cout<<"---------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert At given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete at given position\n";
					cout<<"\t7: Display Linked List\n";
					cout<<"\t8: Count Elements\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"\tEnter your choice : ";
					cin>>iChoice2;
					cout<<"--------------------------------------------------------------------------\n";
	

					switch(iChoice2)
					{
						case 1:
							cout<<"Enter the Element you want to insert : ";
							cin>>dValue;
							obj2.InsertFirst(dValue);
							break;

						case 2:
							cout<<"Enter the Element you want to insert : ";
							cin>>dValue;
							obj2.InsertLast(dValue);
							break;

						case 3:
							cout<<"Enter position : ";
							cin>>iPos2;
							cout<<"Enter the Element you want to insert : ";
							cin>>dValue;
							obj2.InsertAtPosition(dValue,iPos2);
							break;

						case 4:
							obj2.DeleteFirst();
							break;

						case 5:
							obj2.DeleteLast();
							break;

						case 6:
							cout<<"Enter position : ";
							cin>>iPos2;
							obj2.DeleteAtPosition(iPos2);
							break;

						case 7:
							cout<<"Linked List :\n";
							obj2.Display();
							break;

						case 8:
							cout<<"Count of Elements is : "<<obj2.Count()<<"\n";
							break;

						case 0:
							cout<<"Thank you \n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of case 2 switch
				}// end of case 2 while
				break;
			case 3:
				while(iChoice3 != 0)
				{
					cout<<"---------------------------------------------------------------------------\n\n";
					cout<<"\t\tMENU\n\n";
					cout<<"\t1: Insert First\n";
					cout<<"\t2: Insert Last\n";
					cout<<"\t3: Insert At given position\n";
					cout<<"\t4: Delete First\n";
					cout<<"\t5: Delete Last\n";
					cout<<"\t6: Delete at given position\n";
					cout<<"\t7: Display Linked List\n";
					cout<<"\t8: Count Elements\n";
					cout<<"\t0: Exit Application\n\n";

					cout<<"\tEnter your choice : ";
					cin>>iChoice3;
					cout<<"--------------------------------------------------------------------------\n";
	

					switch(iChoice3)
					{
						case 1:
							cout<<"Enter the Element you want to insert : ";
							cin>>cValue;
							obj3.InsertFirst(cValue);
							break;

						case 2:
							cout<<"Enter the Element you want to insert : ";
							cin>>cValue;
							obj3.InsertLast(cValue);
							break;

						case 3:
							cout<<"Enter position : ";
							cin>>iPos3;
							cout<<"Enter the Element you want to insert : ";
							cin>>cValue;
							obj3.InsertAtPosition(cValue,iPos3);
							break;

						case 4:
							obj3.DeleteFirst();
							break;

						case 5:
							obj3.DeleteLast();
							break;

						case 6:
							cout<<"Enter position : ";
							cin>>iPos3;
							obj3.DeleteAtPosition(iPos3);
							break;

						case 7:
							cout<<"Linked List :\n";
							obj3.Display();
							break;

						case 8:
							cout<<"Count of Elements is : "<<obj3.Count()<<"\n";
							break;

						case 0:
							cout<<"Thank you \n";
							break;

						default:
							cout<<"Enter valid choice\n";
							break;
					}//end of case 3 switch
				}// end of case 3 while
				break;
			case 0:
				cout<<"Thank You\n";
				break;

			default:
				cout<<"Please Enter valid choice\n";
				break;

		}// end main swtich case

	}// end main while

	return 0;
}// end of main