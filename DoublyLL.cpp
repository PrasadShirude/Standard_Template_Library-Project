// Doubly Linear Linked List using Generic Programming 

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
class DoublyLL
{
private:
	struct node<T> * Head;
	struct node<T> * Tail;
	int iSize;

public:

	DoublyLL();
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
DoublyLL<T>::DoublyLL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
	struct node<T> *temp = Head;

	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|<=>";
		temp = temp->next;
	}
	cout<<"NULL\n";

}	

template <class T>
int DoublyLL<T>::Count()
{
	return iSize;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
		struct node<T> * newn = new struct node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		if(iSize == 0)
		{
			newn->next = Head;
			Head = newn;
			Tail = newn;
			newn->prev = Head;
		}
		else
		{
			newn->next = Head;
			Head = newn;
			newn->prev = Head;
			newn->next->prev = newn;
		}

		Tail->next = NULL;
		iSize++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if(iSize == 0)
	{
		newn->next = Head;
		Head = newn;
		Tail = newn;
		newn->prev = Head;
	}
	else
	{
		struct node<T> * temp = Head;

		while(temp->next !=NULL)
		{
			temp = temp->next;
		}

		temp->next =newn;
		newn->prev = Tail;
		Tail = newn;
	}
	Tail->next = NULL;
	iSize++;
}

template <class T>
void DoublyLL<T>::InsertAtPosition(T no ,int iPos)
{		
	if((iPos < 1) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 1)
	{
		DoublyLL<T>::InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		DoublyLL<T>::InsertLast(no);
	}
	else
	{
		struct node<T> * newn = new struct node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
			
		struct node<T> * temp = Head;

		for(int i =1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		newn->next=temp->next;
		temp->next = newn;
		newn->prev = temp;
		newn->next->prev = newn;
		iSize++;
	}
 
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
	if(iSize == 0)
	{
		cout<<"Linked List is empty\n";
		return;
	}
	else if (iSize == 1)
	{
		free(Head);
		Head = NULL;
		Tail = NULL;
		iSize--;
	}
	else
	{
		Head = Head->next;
		free(Head->prev);
		iSize--;
	}
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
	if(iSize == 0)
	{
		cout<<"Linked List is empty\n";
		return;
	}
	else if (iSize == 1)
	{
		free(Head);
		Head = NULL;
		Tail = NULL;
		iSize--;
	}
	else
	{
		struct node<T> * temp = Head;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->next = NULL;
		Tail = temp;
		iSize--;
	}
}

template <class T>
void DoublyLL<T>::DeleteAtPosition(int iPos)
{		
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DoublyLL<T>::DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DoublyLL<T>::DeleteLast();
	}
	else
	{
	
		struct node<T> * temp = Head;

		for(int i =1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		struct node<T> * target = NULL;

		target = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		free(target);
		iSize--;
	}
 
}
		
int main()
{		
	int iChoice = 1;
	
	DoublyLL <int> obj1;
	int iChoice1 = 1,iPos1 = 0;
	int  Value;

	DoublyLL <double> obj2;
	int iChoice2 = 1,iPos2 = 0;
	double dValue;

	DoublyLL <char> obj3;
	int iChoice3 = 1,iPos3 = 0;
	char cValue;
	
	while(iChoice != 0)
	{
		cout<<"\n--------------------------------------------------------------------------------\n";
		cout<<"\t\tMain Menu\n\n";
		cout<<"\t1: Doubly Linked List with <int> datatype\n";
		cout<<"\t2: Doubly Linked List with <double> datatype\n";
		cout<<"\t3: Doubly Linked List with <char> datatype\n";
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
							cin>>Value;
							obj1.InsertFirst(Value);
							break;

						case 2:
							cout<<"Enter the Element you want to insert : ";
							cin>>Value;
							obj1.InsertLast(Value);
							break;

						case 3:
							cout<<"Enter position : ";
							cin>>iPos1;
							cout<<"Enter the Element you want to insert : ";
							cin>>Value;
							obj1.InsertAtPosition(Value,iPos1);
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
		}// end main swtich case
	}// end main while

	return 0;
}// end of main