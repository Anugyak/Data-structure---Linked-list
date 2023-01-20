#include<string>
#include<iostream>
#include <sstream>
#include<stdlib.h>
using namespace std;

//structure of the node
struct List{
   string name;			//stores the name of person
   int index;			//gives the person's current position
   List* next;			
}*head;

//insert at the beginning of the list
void insertFirst(string name)
{
	//null head pointer
   if(head==0)
   {
       //point new node to root node
	   List* temp = new List();
       temp->name = name;
       temp->index = 0;
       temp->next = NULL;
       head = temp;
   }
   else
   {
       List* temp = new List();
       temp->name = name;
       temp->index = 0;
       temp->next = head;
       head = temp;
		//assign new node to the position of head
       temp = head->next;
       while(temp!=NULL)
       {
           temp->index = temp->index+1;
           temp = temp->next;
       }
   }
}

//delete at the beginning of the list
void deleteFirst()
{
   if(head == NULL)					//null head pointer to check if it is empty
       return;
   List* temp = head;			//store the next node from the head
   head = head->next;
   delete temp;						//deletion

   List* t = head;
   while(t!=NULL)
   {
       t->index = t->index-1;
       t=t->next;
   }
}

//insert at the end of the list
void insertLast(string name)
{
   //new node
   List* new_temp = new List();		
   new_temp->name = name;
   new_temp->next = NULL;		//have null as a next node
   if(head==NULL)				//if head node is null add new head node
   {
       head = new_temp;
       head->index = 0;
       return;
   }
   List* temp = head;
   while(temp->next!=NULL)
   {
       temp = temp->next;
   }
   new_temp->index=temp->index+1;		//index positioning
   temp->next = new_temp;				//adding new node
}

//delete from the end of the list
void deleteLast()
{
   if(head==NULL)			//if it has null head or not
   return;
   if(head->next == NULL)
   {
       delete head;			//delete the list if single data
       head = NULL;
   }
   List* temp = head;
   while(temp->next->next!=NULL)
   {
       temp=temp->next;
   }
   List* delNode = temp->next;		//deleting the node from the list
   temp->next = NULL;						//setting the next node to null
   delete delNode;
}

//insert after the given index
void insertAfter(string name,int index)
{
   List* newNode = new List();		//stores the data in new node
   newNode->name = name;						//provide the name to the list
   newNode->index = index+1;					//setting the index position and current
   List* temp = head;						//temporary variable
   while(temp->index!=index)					//while loop for the provided index
   {
       temp=temp->next;
   }
   List* t = temp->next;					//next node from temp
   temp->next = newNode;						//next node to new one
   newNode->next = t;
   while(t!=NULL)								//increasing the index position
   {
       t->index = t->index +1;
       t=t->next;
   }
}

//delete the node at the given index
void deleteAfter(int index)
{
   List* temp = head;				//temp to the list
   while(temp->next->index!=index)		//for the index position to find
   {
       temp=temp->next;					//temp is next node
   }
   temp->next=temp->next->next;
   List* t = temp->next;
   while(t!=NULL)						//if last node is null
   {
       t->index = t->index-1;
       t=t->next;						//new node
   }

}

//search the linked list for the given url
int search(string name)
{
   List* temp = head;				//temp for the list
   while(temp!=NULL)					//in search of the name of person
   {
       if(temp->name == name)			//if name is matched return it
       return temp->index;
       temp = temp->next;
   }
   return -1;							
}

//display the list in the form of a string
string display()
{
	stringstream ss;					//converting into string
   string result = "",a;				//result at aux
   List* temp = head;				//store in temporary variable
   while(temp!=NULL)					//until temp is null					
   {
       result+=temp->name;
       ss<<temp->index;					//gives the index 
       a = "(" +ss.str() + ")";
       result+=a;						//increase the position
       result+="->";
       temp = temp->next;				//store at new node
   }
   return result;
}

int main()
{
   head = NULL; 
   insertFirst("Ruby");
   insertFirst("Zoya");
   insertFirst("Bob");
   deleteFirst();
   insertLast("Harry");
   insertAfter("Emily",1);
   insertAfter("Smith",2);
   insertAfter("William",3);
   deleteAfter(1);
   cout<<display();
   //to search the name of person from the function
   string to_find = "Smith";
   if (search(to_find)) {
  	cout << endl << to_find << " is found";
	} else {
  	cout << endl << to_find << " is not found";
  	}
}
