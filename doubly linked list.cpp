#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
class node
{
	public :
			int data;
			node *next,*prev;
			
}*temp,*temp1 ,*listptr;

class list : public node
{
	public :
		
		list()
		{
			next=NULL;
			prev=NULL;
			temp=listptr=NULL;
		}
		
		void create()
		{
			int n;
			cout<<"\nEnter data : ";
			cin>>n;
			
			node *newnode=new node;
			newnode->data=n;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=NULL;
				newnode->prev=NULL;
			}
			else
			{
				temp->next=newnode;
				newnode->prev=temp;
				newnode->next=NULL;
				temp=temp->next;
			}
		}
		
		void insertatbegin()
		{
			int n;
			cout<<"\nEnter data to be inserted : ";
			cin>>n;
			
			node *newnode=new node;
			newnode->data=n;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=NULL;
				newnode->prev=NULL;
			}
			else
			{
				listptr->prev=newnode;
				newnode->next=listptr;
				newnode->prev=NULL;
				listptr=newnode;
			}
				display();
		}
		
		void insertatend()
		{
			int n;
			cout<<"\nEnter data to be inserted : ";
			cin>>n;
			
			node *newnode=new node;
			newnode->data=n;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=NULL;
				newnode->prev=NULL;
			}
			else
			{
				for(temp=listptr;temp->next!=NULL;temp=temp->next);
				
					temp->next=newnode;
					newnode->prev=temp;
					newnode->next=NULL;
					
			}
				display();
					
		}
		
		void insertatpos()
		{
			int n,pos;
			cout<<"\nEnter the position : ";
			cin>>pos;
			cout<<"\nEnter element : ";
			cin>>n;
			
			node *newnode=new node;
			newnode->data=n;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=NULL;
				newnode->prev=NULL;	
			}
			else
			{
				temp=listptr;
				int i;
				for(i=1;i<pos-1&&temp->next!=NULL;temp=temp->next);
			
					newnode->next=temp->next;
					temp->next->prev=newnode;
					temp->next=newnode;
					newnode->prev=temp;
					
				
			}
				display();
			
		}
		
		void delfront()
		{
		
			if(listptr==NULL)
			{
				cout<<"\nDeletion not possible ";
			}
			else
			{
				listptr=listptr->next;
				delete listptr->prev;
				listptr->prev=NULL;
				cout<<"\nElement deleted";
			}
				display();
		
		}
		
		void delend()
		{
			node *temp1,*temp2;
			
			if(listptr==NULL)
			{
				cout<<"\nList is empty";
			}
			
			else
			{
				for(temp=listptr;temp->next!=NULL;temp=temp->next);
				temp1=temp->prev;
				cout<<"\nElement Deleted";
				delete temp;
				temp1->next=NULL;
	        }
	       	display();
		}
		
		void delpos()
		{
			node *temp2;
			int pos;
			cout<<"\nEnter the position : ";
			cin>>pos;
			
			if(listptr==NULL)
			{
				cout<<"\nDeletion not possible ";
			}
			else
			{
				int i;
				temp=listptr;
				
				for(i=1;i<pos-1&&temp->next!=NULL;temp=temp->next,i++);
				temp1=temp->next;
				temp->next=temp1->next;
				
				temp1->next->prev=temp;
				cout<<"\nElement deleted";
				delete temp1;
				
			}
			display();
		}
	
		
		void display()
		{
			cout<<"\nThe linked list is : \n";
			for(temp=listptr;temp!=NULL;)
			{
				cout<<temp->data;
				if(temp->next!=NULL)
				   cout<<"-><-";
				   
				temp=temp->next;
				
			}
		}
};

main()
{
	list l;
	int ch;
	int cho;
	
	label :
	cout<<"\n1.Create a list \n2.Insert at front \n3.Insert at end \n4.Insert at position";
	cout<<"\n5.Delete from front \n6.Delete from end \n7.Delete from position";
	cout<<"\n8.Display";
	cout<<"\nEnter your choice  : ";
	cin>>ch;
	switch(ch)
	{
		case 1 : l.create();
		         break;
		         
		case 2 : l.insertatbegin();
		         break;
		         
		case 3 : l.insertatend();
		         break;
		         
		case 4 : l.insertatpos();
		         break;
		        
		case 5 : l.delfront();
		         break;
		         
		case 6 : l.delend();
		         break;
		         
		case 7 : l.delpos();
		         break;
		         
		case 8 : l.display();
		         break;
	}
	
	cout<<"\n\nPress 1 to continue ";
	cin>>cho;
	if(cho==1)
	{
		goto label;
	}
	else
	{
		exit(0);
	}
	
}
