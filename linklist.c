#include<stdio.h>
#include<stdlib.h>

struct node{              	       		  
int data;              				 
struct node * next;     			  
};

void createlist (int n);      				
void display(); 
void beginsert(int);   
void addany(int); 
void endinsert();        			       
void reverse();

struct node * head;

int main(){
int n,value,j,choice=0;
      while (choice!=7){
      printf("\nPress 1 to Create LinkedList \nPress 2 to Display List \nPress 3 to Begin Insert \nPress 4 to Add Node Anywhere \nPress 5 to Add Node at the end \nPress 6 to Reverse \nPress 7 to Exit\n");
      scanf("%d",&choice);
      switch (choice){
             case 1 : printf("Enter the Number of Node : ");
                      scanf("%d",&n);
                      createlist(n); 
                      printf("Node is Created \n");
                      break;
             case 2 : display();
                      break;
             case 3 : beginsert(value);
                      break;
             case 4 : addany(j);
                      break;
             case 5 : endinsert();
                      break;
             case 6 : reverse();
                      break;
             case 7 : exit(0);
                      break;
            }
      } 
return 0;
}

void createlist(int n){						
struct node *newnode,*temp;
int i,value;
head = (struct node *)malloc(sizeof (struct node));           
   if(head == NULL){
      printf("Memory not found");	
      exit(0);                                                  
     }
printf("Enter Value : ");
scanf("%d",&value);
head->data = value;
head->next = NULL;
temp=head;
  	for(i=2;i<=n;i++){
  	newnode=(struct node*)malloc(sizeof(struct node));        
       		if(newnode==NULL){
          	   printf("Memory Not Found");
         	   break;
          	}
printf("Enter Value : ");
scanf("%d",&value);
newnode->data = value;
newnode->next = NULL;
temp->next = newnode;
temp = temp->next;
 	}
}

void display(){                                    
struct node *ptr;
	if (head == NULL){
            printf("List is Empty \n");
    	    return;
        }
ptr=head;
	while(ptr != NULL){
    	     printf("Data : %d\n",ptr->data);
    	     ptr=ptr->next;
    	}
}

void beginsert(int b){
struct node *temp;
int value;
temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
          printf("Memory not found");	
          exit(0);                                                  
        }
else{
    printf("Enter Value : ");
    scanf("%d",&value);
    temp->data = value;
    temp->next = NULL;
    temp->next = head;
    head = temp;
    printf("\nInsert Node at the Begining\n");
    }
}

void addany(int j){
struct node *ptr,*temp;
int m,p,i;
printf("Enter Pos : ");
scanf("%d",&p);
ptr = (struct node*)malloc(sizeof(struct node));
printf("Enter Value : ");
scanf("%d",&m);
ptr->data = m;
ptr->next = NULL;
           if(p==1){
               printf("\nHello\n");
               ptr->next=head;
               head=ptr;
               return;
               }
else{
temp=head;
for(i=1;i<p-1;i++){
    temp=temp->next;
    }
ptr->next=temp->next;
temp->next=ptr;
printf("Node is Inserted\n");
}
}

void endinsert(){
struct node *ptr,*temp;
int value;
ptr=(struct node*)malloc(sizeof(struct node)); 
printf("Enter Last Value : ");
scanf("%d",&value);
ptr->data = value;
ptr->next = NULL;
   if(ptr == NULL){
		printf("Memory Not Found");
	   }
  else {
	     if(head == NULL){
		     head=ptr;
		     printf("Node Inserted");
		     }
		  else{
	        temp=head;
			      while(temp->next != NULL){
				        temp=temp->next;
			           }
temp->next=ptr;
temp=temp->next;
printf("Node Inserted At The End");
		     }
    	}
}

void reverse(){
printf("List Reversed");
struct node *prev,*cur,*ptr;
prev  = head;
cur = head->next;
head = head->next;
prev->next = NULL;
      while(head!=NULL){
            cur->next = prev;
            head = head->next;
            prev = cur;
            cur = head;
      }
head = prev;
//printf("List Reversed");
}

