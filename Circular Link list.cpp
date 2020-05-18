#include<iostream>
using namespace std;
class node
{
  public:
	int data;
	node*next;
	
}*temp,*listptr,*listptr1;

class list: public node
{	
	public:
		list()
		{
			listptr=NULL;
		    listptr1=NULL;
			temp=NULL;
		}
		
		
		
		void display()
		{
			cout<<"\n";
			temp=listptr;
			do
			{
				cout<<temp->data<<"->";
				temp=temp->next;
				
			}while(temp!=listptr);
			cout<<listptr->data;
			
			
		}
		
		void create(int n)
		{
			node*newnode=new node;
			newnode->data=n;
			newnode->next=NULL;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=listptr;
			}
			else
			{
				temp->next=newnode;
				newnode->next=listptr;	
		   }
		   temp=temp->next;
			
		}
		
		void insertatfront(int n)
		{
			node*newnode=new node;
			newnode->data=n;
			newnode->next=NULL;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=listptr;
			}
			else
			{
				for(temp=listptr;temp->next!=listptr;temp=temp->next);
				temp->next=newnode;
				newnode->next=listptr;
				listptr=newnode;
			}
			cout<<"\nSuccessfull";
			
			display();
		}
		
			void insertatend()
		{
			node *temp1;
			int n;
			cout<<"\Enter element : ";
			cin>>n;
			
		    node*newnode=new node;
			newnode->data=n;
			newnode->next=NULL;
			
			if(listptr==NULL)
			{
				listptr=temp=newnode;
				newnode->next=listptr;
			}
			else
			{
				temp1=listptr;
				while(temp1->next!=listptr)
				{
					temp1=temp1->next;
				}
				temp1->next=newnode;
				newnode->next=listptr;	
			}
			
			
		}
		
	
		
		void insertatpos(int n,int pos)
		{
			node *newnode=new node;
			newnode->data=n;
			newnode->next=NULL;
			
			int j,i;
			
			node *temp1;
			for(temp1=listptr;temp1->next!=listptr;temp1=temp1->next)
			{
				j++;
			}
			
			
			if(pos==1)
			{
				temp1=listptr;
				while(temp1->next!=listptr)
				{
					newnode->next=temp1->next;
					temp1->next=newnode;
					listptr=newnode;
				}
			}
			else
			{
				temp1=listptr;
				for(i=1;i<pos-1&&temp1->next!=listptr;i++)
				{
					if(j<i)
					{
						cout<<"\nInsertion is not possible";
						break;
					}
					else
					{
						temp1=temp1->next;
					}
				}
				newnode->next=temp1->next;
				temp1->next=newnode;
		   }
		    
		    cout<<"\nElement inserted sucessfully";
		    
		    display();
	    }
	    
	    void delfront()
	    {
	    	node *temp1;
	    	
	    	if(listptr==NULL)
	    	{
	    		cout<<"\nList is empty";
			}
	    	
	    	else
	    	{
	    		temp1=listptr;
	    		
	    		while(temp1->next!=listptr)
	    		{
		    		temp1=temp1->next;
		        }
		            listptr=listptr->next;
		         
		            delete temp1->next;
		            temp1->next=listptr;
			    	cout<<"\nFont node deleted\n";
					 
		    	display();
		    }
		}
		
	
		
		void delpos()
		{
			int pos1;
			cout<<"\nEnter the position to be deleted : ";
			cin>>pos1;
			
			int i;
			temp=listptr;
			node *temp1;
			
			for(i=1;temp->next!=listptr && i<pos1-1;i++)
			{
				temp=temp->next;
			}
			
			temp1=temp->next;
			temp->next=temp1->next;
			
			delete temp1;
			
			cout<<"\nNode deleted";
			
			display();
				
		
        }
        
        int search()
        {
        	int d;
        	cout<<"\nEnter the data to be searched : ";
        	cin>>d;
        	
        	int i;
        	
        	temp=listptr;
        	
        	for(i=1;temp->next!=listptr;i++)
        	{
        		if(temp->data==d)
        		{
        			cout<<"\nData found";
				}
				temp=temp->next;
				
			}
			return i;
			
			
		}
		
		void delvalue()
		{
			int val;
			node *temp1;
			
			temp=listptr;
			cout<<"\nEnter the element to be deleted : ";
			cin>>val;
		
				while(temp->next!=listptr)
				{
					if(temp->next->data==val)
					{
						temp1=temp->next;
						temp->next=temp1->next;
						
						delete temp1;
				    }
				    temp=temp->next;
				}
				
			
			cout<<"\nElement deleted\n";
			
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
			
				temp1=listptr;
				while(temp1->next->next!=listptr)
				{
					temp1=temp1->next;
				}
				
			    temp2=temp1->next;
				
				temp1->next=temp2->next;
				delete temp2;
				
				cout<<"\nNode deleted\n";
				display();
			
	        }
		}
	
};

int main()
{
	int n,ch,pos;
	char cho;
	list l;
	do{
	
	cout<<"\n1.Create first link list";
	cout<<"\n2.Insert at a position\n3.Insert at end \n4.Display\n5.Insert at front";
	cout<<"\n6.Delete from front\n7.Delete from position";
	cout<<"\n8.Searching\n9..Delete from end";
	cout<<"\nEnter your choice :";
	cin>>ch;
	switch(ch)
	{
		case 1 : cout<<"\nEnter the element : ";
		         cin>>n;
		         l.create(n);
		         break;
		         
		         
		case 2 : cout<<"\nEnter the element : ";
		         cin>>n;
		         cout<<"\nEnter the position to insert : ";
		         cin>>pos;
		         l.insertatpos(n,pos);
		         break;
		         
		case 3 : l.insertatend();
		         		         
		case 4 : l.display();
		         break;
		         
		case 5 : cout<<"\nEnter the element : ";
		 		 cin>>n;
		 		 l.insertatfront(n);
		         break;
		         
		case 6 : l.delfront();
		         break;
		          
		case 7 : l.delpos();
		         break;
		         
		case 8 : l.search();
		          break;
		         
	//	case 9 : l.delvalue();
		         break;
		    
	    case 9 : l.delend();
	    		  break;
	}
	
	cout<<"\nDo you want to continue ??(Y/N) : ";
	cin>>cho;
  
  }while(cho=='y');
	
	
}


