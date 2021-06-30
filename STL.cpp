#include<iostream>
using namespace std;


// Start Singly LL functions
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
// end of Singly LL function


// start of Singly CL 
template <class T>
struct node2
{
	T data;
	struct node2 * next;
};

template <class T>
class SinglyCL
{
private:
	struct node2<T> * Head;
	struct node2<T> * Tail;
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
	struct node2<T> * temp = Head;
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
	struct node2<T> * newn = new struct node2<T>;
	
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
	struct node2<T> * newn = new struct node2<T>;

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
		struct node2<T> * temp = Head;

		struct node2<T> * newn = new struct node2<T>;
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
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}
	struct node2<T> * temp = Head;

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
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}
	struct node2<T> * temp = Head;

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
		struct node2<T> * temp = Head;
		struct node2<T> * target = NULL;

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

// end of singly CL function


// start of doubly LL function
template <class T>
struct node3
{
	T data;
	struct node3 * next;
	struct node3 * prev;
};

template <class T>
class DoublyLL
{
private:
	struct node3<T> * Head;
	struct node3<T> * Tail;
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
	struct node3<T> *temp = Head;

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
		struct node3<T> * newn = new struct node3<T>;

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
	struct node3<T> * newn = new struct node3<T>;

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
		struct node3<T> * temp = Head;

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
		struct node3<T> * newn = new struct node3<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
			
		struct node3<T> * temp = Head;

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
		struct node3<T> * temp = Head;

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
	
		struct node3<T> * temp = Head;

		for(int i =1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		struct node3<T> * target = NULL;

		target = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		free(target);
		iSize--;
	}
 
}

// end of doubly LL function


// start of doubly CL function
template <class T>
struct node4
{
	T data;
	struct node4 * next;
	struct node4 * prev;
};

template <class T>
class DoublyCL
{	
private:
	struct node4<T> * Head;
	struct node4<T> * Tail;
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
	struct node4<T> * temp = Head;

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
	struct node4<T> * newn = new struct node4<T>;

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
	struct node4<T> * newn = new struct node4<T>;

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
		struct node4<T> * newn = new struct node4<T>;
		struct node4<T> * temp = Head;

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
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}

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
		struct node4<T> * temp = Head;

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
	if(iSize == 0)
	{	
		cout<<"Linked List is empty\n";
		return;
	}

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
		struct node4<T> * temp = Head;

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
		struct node4<T> * temp = Head;
		struct node4<T> * target = NULL;

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
}// end of doubly CL function

// start of stack function
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
}//end of stack function


// start of queue function
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
		cout<<"Queue is empty\n";
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
}// end of queue function

int main()
{
	int iChoiceMain = 1;

	int iChoice = 1;

	int iChoice1 = 1,iPos1 = 0;
	int iRet, iValue;

	int iChoice2 = 1,iPos2 = 0;
	double dValue;

	int iChoice3 = 1,iPos3 = 0;
	char cValue;

	SinglyLL <int> obj1;
	SinglyLL <double> obj2;
	SinglyLL <char> obj3;
	

	SinglyCL <int> obj4;
	SinglyCL <char> obj5;
	SinglyCL <double> obj6;

	DoublyLL <int> obj7;
	DoublyLL <double> obj8;
	DoublyLL <char> obj9;

	DoublyCL <int> obj10;
	DoublyCL <char> obj11;
	DoublyCL <double> obj12;

	Stack <int> obj13;
	Stack <char> obj14;
	Stack <double> obj15;

	Queue <int> obj16;
	Queue <char> obj17;
	Queue <double> obj18;

	while(iChoiceMain != 0)
	{
		cout<<"\n---------------------------------------------------------------------------\n";
		cout<<"\t\tMAIN MENU\n\n";
		cout<<"\t1: Singly Linear Linked List\n";
		cout<<"\t2: Singly Circular Linked List\n";
		cout<<"\t3: Doubly Linear Linked List\n";
		cout<<"\t4: Doubly Circular Linked List\n";
		cout<<"\t5: Stack\n";
		cout<<"\t6: Queue\n";
		cout<<"\t0: Exit the Application\n\n";

		cout<<"Enter you choice : ";
		cin>>iChoiceMain;
		cout<<"\n---------------------------------------------------------------------------\n";
		switch(iChoiceMain)
		{
			case 1:
				while(iChoice != 0)
				{
					cout<<"\n--------------------------------------------------------------------------------\n";
					cout<<"\t\tMain Menu (SinglyLL)\n\n";
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

				}// end main case 1 while
				break;

			case 2:
				while(iChoice != 0)
				{
					cout<<"\n--------------------------------------------------------------------------\n\n";
					cout<<"\t\tMain Menu (SinglyCL)\t\t\n\n";
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
										cin>>iValue;
										obj4.InsertFirst(iValue);
										break;

									case 2:
										cout<<"Enter the elements you want to insert : ";
										cin>>iValue;
										obj4.InsertLast(iValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos1;
										cout<<"Enter the elements you want to insert : ";
										cin>>iValue;
										obj4.InsertAtPosition(iValue,iPos1);
										break;

									case 4:
										obj4.DeleteFirst();
										break;

									case 5:
										obj4.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos1;
										obj4.DeleteAtPosition(iPos1);
										break;

									case 7:
										cout<<"Linked List contains \n";
										obj4.Display();
										break;

									case 8:
										iRet = obj4.Count();
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
										obj5.InsertFirst(cValue);
										break;

									case 2:
										cout<<"Enter the elements you want to insert : ";
										cin>>cValue;
										obj5.InsertLast(cValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos2;
										cout<<"Enter the elements you want to insert : ";
										cin>>cValue;
										obj5.InsertAtPosition(cValue,iPos2);
										break;

									case 4:
										obj5.DeleteFirst();
										break;

									case 5:
										obj5.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos2;
										obj5.DeleteAtPosition(iPos2);
										break;

									case 7:
										cout<<"Linked List contains \n";
										obj5.Display();
										break;

									case 8:
										iRet = obj5.Count();
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
										obj6.InsertFirst(dValue);
										break;

									case 2:
										cout<<"Enter the elements you want to insert : ";
										cin>>dValue;
										obj6.InsertLast(dValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos3;
										cout<<"Enter the elements you want to insert : ";
										cin>>dValue;
										obj6.InsertAtPosition(dValue,iPos3);
										break;

									case 4:
										obj6.DeleteFirst();
										break;

									case 5:
										obj6.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos3;
										obj6.DeleteAtPosition(iPos3);
										break;

									case 7:
										cout<<"Linked List contains \n";
										obj6.Display();
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
				break;

			case 3:
				while(iChoice != 0)
				{
					cout<<"\n--------------------------------------------------------------------------------\n";
					cout<<"\t\tMain Menu (DoublyLL)\n\n";
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
										cin>>iValue;
										obj7.InsertFirst(iValue);
										break;

									case 2:
										cout<<"Enter the Element you want to insert : ";
										cin>>iValue;
										obj7.InsertLast(iValue);
										break;

									case 3:
										cout<<"Enter position : ";
										cin>>iPos1;
										cout<<"Enter the Element you want to insert : ";
										cin>>iValue;
										obj7.InsertAtPosition(iValue,iPos1);
										break;

									case 4:
										obj7.DeleteFirst();
										break;

									case 5:
										obj7.DeleteLast();
										break;

									case 6:
										cout<<"Enter position : ";
										cin>>iPos1;
										obj7.DeleteAtPosition(iPos1);
										break;

									case 7:
										cout<<"Linked List :\n";
										obj7.Display();
										break;

									case 8:
										cout<<"Count of Elements is : "<<obj7.Count()<<"\n";
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
										obj8.InsertFirst(dValue);
										break;

									case 2:
										cout<<"Enter the Element you want to insert : ";
										cin>>dValue;
										obj8.InsertLast(dValue);
										break;

									case 3:
										cout<<"Enter position : ";
										cin>>iPos2;
										cout<<"Enter the Element you want to insert : ";
										cin>>dValue;
										obj8.InsertAtPosition(dValue,iPos2);
										break;

									case 4:
										obj8.DeleteFirst();
										break;

									case 5:
										obj8.DeleteLast();
										break;

									case 6:
										cout<<"Enter position : ";
										cin>>iPos2;
										obj8.DeleteAtPosition(iPos2);
										break;

									case 7:
										cout<<"Linked List :\n";
										obj8.Display();
										break;

									case 8:
										cout<<"Count of Elements is : "<<obj8.Count()<<"\n";
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
										obj9.InsertFirst(cValue);
										break;

									case 2:
										cout<<"Enter the Element you want to insert : ";
										cin>>cValue;
										obj9.InsertLast(cValue);
										break;

									case 3:
										cout<<"Enter position : ";
										cin>>iPos3;
										cout<<"Enter the Element you want to insert : ";
										cin>>cValue;
										obj9.InsertAtPosition(cValue,iPos3);
										break;

									case 4:
										obj9.DeleteFirst();
										break;

									case 5:
										obj9.DeleteLast();
										break;

									case 6:
										cout<<"Enter position : ";
										cin>>iPos3;
										obj9.DeleteAtPosition(iPos3);
										break;

									case 7:
										cout<<"Linked List :\n";
										obj9.Display();
										break;

									case 8:
										cout<<"Count of Elements is : "<<obj9.Count()<<"\n";
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
				break;

			case 4:
				while(iChoice != 0)
				{
					cout<<"\n----------------------------------------------------------------------------------\n";
					cout<<"\t\tMain Menu (DoublyCL)\n\n";
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
										obj10.InsertFirst(iValue);
										break;

									case 2:
										cout<<"Enter the element to insert : ";
										cin>>iValue;
										obj10.InsertLast(iValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos1;
										cout<<"Enter the element to insert : ";
										cin>>iValue;
										obj10.InsertAtPosition(iValue,iPos1);
										break;

									case 4:
										obj10.DeleteFirst();
										break;

									case 5:
										obj10.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos1;
										obj10.DeleteAtPosition(iPos1);
										break;

									case 7:
										cout<<"Linked List Contains\n";
										obj10.Display();
										break;

									case 8:
										iRet = obj10.Count();
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
										obj11.InsertFirst(cValue);
										break;

									case 2:
										cout<<"Enter the element to insert : ";
										cin>>cValue;
										obj11.InsertLast(cValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos2;
										cout<<"Enter the element to insert : ";
										cin>>cValue;
										obj11.InsertAtPosition(cValue,iPos2);
										break;

									case 4:
										obj11.DeleteFirst();
										break;

									case 5:
										obj11.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos2;
										obj11.DeleteAtPosition(iPos2);
										break;

									case 7:
										cout<<"Linked List Contains\n";
										obj11.Display();
										break;

									case 8:
										iRet = obj11.Count();
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
										obj12.InsertFirst(dValue);
										break;

									case 2:
										cout<<"Enter the element to insert : ";
										cin>>dValue;
										obj12.InsertLast(dValue);
										break;

									case 3:
										cout<<"Enter the position : ";
										cin>>iPos3;
										cout<<"Enter the element to insert : ";
										cin>>dValue;
										obj12.InsertAtPosition(dValue,iPos3);
										break;

									case 4:
										obj12.DeleteFirst();
										break;

									case 5:
										obj12.DeleteLast();
										break;

									case 6:
										cout<<"Enter the position : ";
										cin>>iPos3;
										obj12.DeleteAtPosition(iPos3);
										break;

									case 7:
										cout<<"Linked List Contains\n";
										obj12.Display();
										break;

									case 8:
										iRet = obj12.Count();
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
				break;

			case 5:
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
										obj13.PUSH(iValue);
										break;

									case 2:
										cout<<"Popped element is : "<<obj13.POP()<<"\n";
										break;

									case 3:
										cout<<"Stack contains\n";
										obj13.Display();
										break;

									case 4:
										cout<<"Total elements in Stack : "<<obj13.Count()<<"\n";
										break;

									case 5:
										cout<<"Peeked element is : "<<obj13.PEEK()<<"\n";
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
										obj14.PUSH(cValue);
										break;

									case 2:
										cout<<"Popped element is : "<<obj14.POP()<<"\n";
										break;

									case 3:
										cout<<"Stack contains\n";
										obj14.Display();
										break;

									case 4:
										cout<<"Total elements in Stack : "<<obj14.Count()<<"\n";
										break;

									case 5:
										cout<<"Peeked element is : "<<obj14.PEEK()<<"\n";
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
										obj15.PUSH(dValue);
										break;

									case 2:
										cout<<"Popped element is : "<<obj15.POP()<<"\n";
										break;

									case 3:
										cout<<"Stack contains\n";
										obj15.Display();
										break;

									case 4:
										cout<<"Total elements in Stack : "<<obj15.Count()<<"\n";
										break;

									case 5:
										cout<<"Peeked element is : "<<obj15.PEEK()<<"\n";
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
				break;
				
			case 6:
				while(iChoice != 0)
				{
					cout<<"\n------------------------------------------------------------------------------------\n";
					cout<<"\t\tQueue Menu\n\n";
					cout<<"\t1: Queue with <int> datatype\n";
					cout<<"\t2: Queue with <char> datatype\n";
					cout<<"\t3: Queue with <double> datatype\n";
					cout<<"\t0: Exit\n\n";

					cout<<"Enter your choice : ";
					cin>>iChoice;

					cout<<"\n------------------------------------------------------------------------------------\n";

					switch(iChoice)
					{
						case 1:
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
							break;

						case 2:	
							while(iChoice2 != 0)
							{
								cout<<"\n------------------------------------------------------------------------------------\n";
								cout<<"\t\tQueue\n\n";
								cout<<"\t1: ADD\n";
								cout<<"\t2: DELETE\n";
								cout<<"\t3: Display\n";
								cout<<"\t4: Count\n";
								cout<<"\t0: Exit\n\n";

								cout<<"Enter your choice : ";
								cin>>iChoice2;

								cout<<"\n------------------------------------------------------------------------------------\n";

								switch(iChoice2)
								{
									case 1:
										cout<<"Enter the element you want to add : ";
										cin>>cValue;
										obj17.Add(cValue);
										break;

									case 2:
										cout<<"Element deleted is : "<<obj17.Delete()<<"\n";
										break;

									case 3:
										cout<<"Queue contains \n";
										obj17.Display();
										break;

									case 4:
										cout<<"Total element in Queue : "<<obj17.Count()<<"\n";
										break;

									case 0:
										break;

									default:
										cout<<"Please enter valid choice\n";
										break;
								}//end of queue case 2 switch	
							}//end of queue case 2 while
							break;

						case 3:
							while(iChoice3 != 0)
							{
								cout<<"\n------------------------------------------------------------------------------------\n";
								cout<<"\t\tQueue\n\n";
								cout<<"\t1: ADD\n";
								cout<<"\t2: DELETE\n";
								cout<<"\t3: Display\n";
								cout<<"\t4: Count\n";
								cout<<"\t0: Exit\n\n";

								cout<<"Enter your choice : ";
								cin>>iChoice3;

								cout<<"\n------------------------------------------------------------------------------------\n";

								switch(iChoice3)
								{
									case 1:
										cout<<"Enter the element you want to add : ";
										cin>>dValue;
										obj18.Add(dValue);
										break;

									case 2:
										cout<<"Element deleted is : "<<obj18.Delete()<<"\n";
										break;

									case 3:
										cout<<"Queue contains \n";
										obj18.Display();
										break;

									case 4:
										cout<<"Total element in Queue : "<<obj18.Count()<<"\n";
										break;

									case 0:
										break;

									default:
										cout<<"Please enter valid choice\n";
										break;
								}//end of queue case 3 switch	
							}//end of queue case 3 while
							break;

						case 0:
							break;

						default:
							cout<<"Please enter valid choice\n";
							break;
					}//end of queue switch
				}//end of queue while
				break;
			case 0:
				cout<<"THANK YOU  for using STL Application\n";
				break;

			default:
				cout<<"Please enter valid choice\n";
				break;

		}//end of STL switch
	}//end of STL while 

	return 0;
}