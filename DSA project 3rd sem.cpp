#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int count1=0,count2=0;
struct node
{
	char empid[20];
	char name[20],profession[20],empno[10];
	float sal;
	int empage;
	struct node*link;
}*temp1=NULL,*temp2=NULL,*first1=NULL,*first2=NULL,*last1=NULL,*last2=NULL;
void create1()
{
	char empid[20];
	char name[20],profession[20],empno[10];
	float sal;
	int empage;
	temp1=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter the employee details");
	printf("\nEmployee ID:");
	scanf("%s",temp1->empid);
	printf("\nEmployee name:");
	scanf("%s",temp1->name);
	printf("\nDepartment:");
	scanf("%s",temp1->profession);
	printf("\nSalary:");
	scanf("%f",&temp1->sal);
	printf("\nPhone No:");
	scanf("%s",temp1->empno);
	printf("\nAge:");
	scanf("%d",&temp1->empage);
	temp1->link=NULL;
	count1++;
	if(first1==NULL)
	{
		first1=temp1;
		last1=first1;
	}
	else
	{
		last1->link=temp1;
		last1=temp1;
	}
}
void create2()
{
    char empid[20];
	char name[20],profession[20],empno[10];
	float sal;
	int empage;  
	temp2=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter the employee details");
	printf("\nEmployee ID:");
	scanf("%s",temp2->empid);
	printf("\nEmployee name:");
	scanf("%s",temp2->name);
	printf("\nDepartment:");
	scanf("%s",temp2->profession);
	printf("\nSalary:");
	scanf("%f",&temp2->sal);
	printf("\nPhone No:");
	scanf("%s",temp2->empno);
	printf("\nAge:");
	scanf("%d",&temp2->empage);
	temp2->link=NULL;
	count2++;
	if(first2==NULL)
	{
		first2=temp2;
		last2=first2;
	}
	else
	{
		last2->link=temp2;
		last2=temp2;
	}
}

void display1()
{
	temp1=first1;
    if(first1==NULL)
	{
		printf("\nNo employees");
	}
	else
	{
		
		while(temp1!=NULL)
		{
			printf("%s\t%s\t%s\t%f\t%s\t%d",temp1->empid,temp1->name,temp1->profession,temp1->sal,temp1->empno,temp1->empage);
			temp1=temp1->link;
			printf("\n");
		}
		printf("\nThe total number of Employees is %d",count1);
	}
}
void display2()
{
	temp2=first2;
	if(first2==NULL)
	{
		printf("\nNo employees");
	}
	else
	{
		
		while(temp2!=NULL)
		{
			printf("%s\t%s\t%s\t%f\t%s\t%d",temp2->empid,temp2->name,temp2->profession,temp2->sal,temp2->empno,temp2->empage);
			temp2=temp2->link;
			printf("\n");
		}
		printf("\nThe total number of Employees is %d",count2);
	}
}
void search1()
{
	temp1=first1;
	char search1[20];
	printf("\n Enter the ID of the employee to be searched:\n");
	scanf("%s",search1); 
	if(first1==NULL)
	{
		printf("\nNo employees\n");
		return;
	}
	else
	{   
	    
		while(temp1!=NULL)
		{
		    if(strcmp(temp1->empid,search1)==0)
		    {
		    	printf("\nemployee found and details given below\n");
		    	printf("%s\t%s\t%s\t%f\t%s\t%d",temp1->empid,temp1->name,temp1->profession,temp1->sal,temp1->empno,temp1->empage);
                return;
			}
			temp1=temp1->link;
		}
		printf("\nNo employee by this ID found in the company\n");
	}
}
void search2()
{
	temp2=first2;
	char search2[20];
	printf("\nEnter the ID of the employee to be searched:\n");
	scanf("%s",search2); 
	if(first2==NULL)
	{
		printf("\nNo employees\n");
		return;
	}
	else
	{   
	    
		while(temp2!=NULL)
		{
		    if(strcmp(temp2->empid,search2)==0)
		    {
		    	printf("\nemployee found and details given below\n");
		    	printf("%s\t%s\t%s\t%f\t%s\t%d",temp2->empid,temp2->name,temp2->profession,temp2->sal,temp2->empno,temp2->empage);
                return;
			}
			temp2=temp2->link;
		}
		printf("\nNo employee by this ID found in the company\n");
	}
}
void deleteemp1()
{   
	struct node *q=NULL;
	char delemp1[20];
	printf("\nEnter the ID of the employee to be removed:");
	scanf("%s",delemp1);
	temp1=first1;
	if(first1==NULL)
	{
		printf("\nNo employees");
		return;
	}
	else
	{
		while(strcmp(temp1->empid,delemp1)!=0)
		{
			if(temp1->link==NULL)
			{
				printf("\nThe given employee ID %s does not exist",delemp1);
				return;
			}
			temp1=temp1->link;
		}
	}
	temp1=first1;
	if(strcmp(temp1->empid,delemp1)==0)
	{
		first1=temp1->link;
		printf("\nEmployee found");
		printf("\nThe details of fired employee\n");
		printf("%s\t%s\t%s\t%f\t%s\t%d",temp1->empid,temp1->name,temp1->profession,temp1->sal,temp1->empno,temp1->empage);
		temp1->link=NULL;
		free(temp1);
		count1--;
		return;
	}
	else
	{
		while(strcmp(temp1->link->empid,delemp1)!=0)
		{
			temp1=temp1->link;
		}
		q=temp1->link;
		printf("\nEmployee found");
		printf("\nThe details of fired employee\n");
		printf("%s\t%s\t%s\t%f\t%s\t%d",q->empid,q->name,q->profession,q->sal,q->empno,q->empage);
		if(q==last1)
		{
			last1=temp1;
			last1->link=NULL;
		}
		temp1->link=q->link;
		q->link=NULL;
		free(q);
		count1--;
	}
}
void deleteemp2()
{   
	struct node *p=NULL;
	char delemp2[20];
	printf("\nEnter the ID of the employee to be removed:");
	scanf("%s",delemp2);
	temp2=first2;
	if(first2==NULL)
	{
		printf("\nNo employees");
		return;
	}
	else
	{
		while(strcmp(temp2->empid,delemp2)!=0)
		{
			if(temp2->link==NULL)
			{
			printf("\nThe given employee ID %s does not exist",delemp2);
			return;
			}
			temp2=temp2->link;
		}
	}
	temp2=first2;
	if(strcmp(temp2->empid,delemp2)==0)
	{
		first2=temp2->link;
		printf("\nEmployee found");
		printf("\nThe details of fired employee\n");
		printf("%s\t%s\t%s\t%f\t%s\t%d",temp2->empid,temp2->name,temp2->profession,temp2->sal,temp2->empno,temp2->empage);
		temp2->link=NULL;
		free(temp2);
		count2--;
		return;
	}
	else
	{
		while(strcmp(temp2->link->empid,delemp2)!=0)
		{
			temp2=temp2->link;
		}
		p=temp2->link;
		printf("\nEmployee found");
		printf("\nThe details of fired employee\n");
		printf("%s\t%s\t%s\t%f\t%s\t%d",p->empid,p->name,p->profession,p->sal,p->empno,p->empage);
		if(p==last2)
		{
			last2=temp2;
			last2->link=NULL;
		}
		temp2->link=p->link;
		p->link=NULL;
		free(p);
		count2--;
	}
}

void highestsal1()
{
  float maxsal1;
  char emp[20];
  temp1=first1;
  if(first1==NULL)
  {
  	printf("\nNo employees");
  	return;
  }
  else
  {
  	maxsal1=temp1->sal;
  	while(temp1!=0)
  	{
  		if(maxsal1<temp1->sal)
  		{
  			maxsal1=temp1->sal;
  			strcpy(emp,temp1->name);
		}
		temp1=temp1->link;
	}
	printf("\n%s has the highest salary:%f",emp,maxsal1);
  }
}
void highestsal2()
{
   float maxsal2;
  char emp[20];
  temp2=first2;
  if(first2==NULL)
  {
  	printf("\nNo employees");
  	return;
  }
  else
  {
  	maxsal2=temp2->sal;
  	while(temp2!=0)
  	{
  		if(maxsal2<temp2->sal)
  		{
  			maxsal2=temp2->sal;
  			strcpy(emp,temp2->name);
		}
		temp2=temp2->link;
	}
	printf("\n%s has the highest salary:%f",emp,maxsal2);
  }
}
void highestage()
{
	int maxage=0;
	char name[20];
	temp1=first1;
	temp2=first2;
	if((first1==NULL) && (first2==NULL))
	{
		 printf("\nThere are no employees");
	     return;
	}
    if(temp1!=NULL)
	{
		while(temp1!=NULL)
		{
			if(maxage<temp1->empage)
			{
				maxage=temp1->empage;
				strcpy(name,temp1->name);
			}
			temp1=temp1->link;
		}
	}
	if(temp2!=NULL)
	{
		while(temp2!=NULL)
		{
			if(maxage<temp2->empage)
			{
				maxage=temp2->empage;
				strcpy(name,temp2->name);
			}
			temp2=temp2->link;
		}
	}
	printf("\n%s has the highest age:%d",name,maxage);
}
int main()
{
	int ch,i,j,m,n;
	char branch1[20],branch2[20];
    //clrscr();
    printf("---------------EMPLOYEE MAPPING AND MANAGEMENT---------------");
    printf("\nEnter the name of two Branches of the company\n");
	scanf("%s\n%s",branch1,branch2);	
	printf("1.Create list of employees of %s\n",branch1);
	printf("2.Create list of employees of %s\n",branch2);
	printf("3.Insert an employee to %s\n",branch1);
	printf("4.Insert an employee to %s\n",branch2);
	printf("5.Display list of employees of %s\n",branch1);
	printf("6.Display list of employees of %s\n",branch2);
	printf("7.Search an employee in %s\n",branch1);
	printf("8.Search an employee in %s\n",branch2);
	printf("9.Remove an employee in %s\n",branch1);
    printf("10.Remove an employee in %s\n",branch2);
    printf("11.To find highest salary in %s\n",branch1);
    printf("12.To find highest salary in %s\n",branch2);
    printf("13.To find the highest age of employee in both the branches\n");
    printf("14.exit\n");
    while(1)
    {
      printf("\nEnter your choice:");
	  scanf("%d",&ch);
	  switch(ch)
	    {
	      case 1:printf("\nEnter the number of employees in %s:",branch1);
		         scanf("%d",&m);
				 for(i=0;i<m;i++)
				  create1();
				  break;
		  case 2:printf("\nEnter the number of employees in %s:",branch2);
		         scanf("%d",&n);
				 for(j=0;j<n;j++)
				  create2();
				  break;
		  case 3:create1();
		         break;	
		  case 4:create2();
		         break;	
	      case 5:display1();
		         break;	
	      case 6:display2();
		         break;
		  case 7:search1();
		         break;	
		  case 8:search2();
		         break;	
		  case 9:deleteemp1();
		         break;	
		  case 10:deleteemp2();
		         break;	
		  case 11:highestsal1();
		          break;
		  case 12:highestsal2();
		          break;
		  case 13:highestage();
		          break;
		  case 14:exit(0);
		  default:printf("Invalid choice");
		}
		printf("\n");	
	}
	return 0;
}
