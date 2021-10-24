#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
struct info
{
  
char emp_name[30], father_name[30];
   
int emp_id, attendence;
   
char emp_ph_no[15], ft_ph_no[10];
   
char salary[10];
   
char work[15], status[15];
 
} s;

 
struct user 
{
  
int usr_name;
   
char usr_password[10];
 
} USR;

 
 
 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
FILE * fp;

int flag;

int add = 0;

 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void list_all ();

void admin ();

void newuser ();

void viewprof (int id);

void usr_search ();

void modify ();

void adm_search ();

void main ();

void sal_att ();

void workstatus ();

void viewwork (int id);

void header ();

void add_att (int id);

 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
									USER
*/ 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
newuser () 
{
  
char masterkey[10], password[20];
  
int username;
  
printf ("Enter masterkey: ");
  
fflush (stdin);
  
gets (masterkey);
  
if (strcmp (masterkey, "sanchit") == 0)
    
    {
      
fp = fopen ("usr_login.DAT", "rb");
      
fflush (stdin);
      
clrscr ();
      
header ();
      
printf ("Enter erp_id: ");
      
scanf ("%d", &username);
      
while ((fread (&USR, sizeof (USR), 1, fp)) > 0)
	
	{
	  
if (username == USR.usr_name)
	    
	    {
	      
flag = 1;
	    
}
	
}
      
fclose (fp);
      
 
if (flag == 1)
	
	{
	  
printf ("Cannot add same employee again...!!!");
	
}
      
      else
	
	{
	  
fp = fopen ("USR_LOGIN.DAT", "ab");
	  
fflush (stdin);
	  
clrscr ();
	  
header ();
	  
printf ("\nEnter username: ");
	  
scanf ("%d", &USR.usr_name);
	  
fflush (stdin);
	  
USR.usr_name = username;
	  
printf ("Enter Password: ");
	  
gets (USR.usr_password);
	  
fwrite (&USR, sizeof (USR), 1, fp);
	  
fclose (fp);
	  
fp = fopen ("USR_LOGIN.DAT", "rb");
	  
while ((fread (&USR, sizeof (USR), 1, fp) > 0))
	    
	    {
	      
if (USR.usr_name == username)
		
		{
		  
printf ("New User Successfully Added");
		  
delay (2000);
		
}
	    
}
	  
 
add = 1;
	
}
    
}
  
  else
    
    {
      
header ();
      
printf ("Unauthorized Acess Denied...!!!");
      
delay (2000);
      
exit ();
    
}
  
if (add == 1)
    
    {
      
clrscr ();
      
fp = fopen ("EMPLOYEE.DAT", "ab");
      
clrscr ();
      
header ();
      
s.emp_id = USR.usr_name;
      
fflush (stdin);
      
printf ("Enter Employee Name: ");
      
gets (s.emp_name);
      
fflush (stdin);
      
printf ("Enter Father's Name: ");
      
gets (s.father_name);
      
fflush (stdin);
      
printf ("Enter Employee's Phone number: ");
      
gets (s.emp_ph_no);
      
fflush (stdin);
      
printf ("Enter Father's Phone number: ");
      
gets (s.ft_ph_no);
      
fflush (stdin);
      
printf ("Enter The Salary of Employee : ");
      
gets (s.salary);
      
fflush (stdin);
      
fwrite (&s, sizeof (s), 1, fp);
      
fclose (fp);
      
printf ("\n");
      
printf ("Employee record has been created");
      
printf ("\n");
      
delay (2000);
    
}

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
viewprof (int id) 
{
  
clrscr ();
  
header ();
  
fp = fopen ("EMPLOYEE.DAT", "rb");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (id == s.emp_id)
	
	{
	  
printf ("\t\tProfile Information\t\t\n");
	  
printf ("\nERP: %d", s.emp_id);
	  
printf ("\nEmployee Name: %s", s.emp_name);
	  
printf ("\nFather Name: %s", s.father_name);
	  
printf ("\nEmployee's Phone number:");
	  
puts (s.emp_ph_no);
	  
fflush (stdin);
	  
printf ("Father's Phone Name: ");
	  
puts (s.ft_ph_no);
	  
fflush (stdin);
	
}
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
usr_search () 
{
  
int no, flag = 0;
  
clrscr ();
  
header ();
  
printf ("Enter EMP Id to search details: ");
  
scanf ("%d", &no);
  
fp = fopen ("EMPLOYEE.DAT", "rb");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (s.emp_id == no)
	
	{
	  
clrscr ();
	  
header ();
	  
printf ("Record Found\n\n");
	  
printf ("ERP: %d\n", s.emp_id);
	  
printf ("Name: %s\n", s.emp_name);
	  
printf ("Number: %s\n", s.emp_ph_no);
	  
flag = 1;
	
}
    
}
  
if (flag == 0)
    
    {
      
header ();
      
printf ("Record not found");
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
									USER
*/ 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
user (int id, char password[10]) 
{
  
int usr_choice, a;
  
fp = fopen ("usr_login.DAT", "rb");
  
 
while ((fread (&USR, sizeof (USR), 1, fp)) > 0)
    
    {
      
if (id == USR.usr_name && strcmp (password, USR.usr_password) == 0)
	
	{
	  
flag = 1;
	
}
    
}
  
fclose (fp);
  
 
if (flag == 1)
    
    {
    
 
 
DISP:
clrscr ();
      
header ();
      
printf ("1. View your profile.\n");
      
printf ("2. Search Employee.\n");
      
printf ("3. View Attendance or Mark Attendence\n");
      
printf ("4. View Salary.\n");
      
printf ("5. View Your Project Work\n");
      
printf ("6. Logout\n");
      
printf ("Enter your choice: ");
      
scanf ("%d", &usr_choice);
      
 
 
switch (usr_choice)
	
	{
	
case 1:
	  viewprof (id);
	  
printf ("\n\nEnter 1 for main menu or");
	  
printf ("\n2 for logout and exit..: ");
	  
scanf ("%d", &a);
	  
switch (a)
	    
	    {
	    
case 1:
	      
clrscr ();
	      
goto DISP;
	    
case 2:
	      printf ("Logging out...");
	      
delay (1000);
	      
main ();
	    
default:
	      clrscr ();
	      
goto DISP;
	    
}
	  
break;
	
case 2:
	  usr_search ();
	  
printf ("\n\nEnter 1 for main menu or");
	  
printf ("\n2 for logout and exit..: ");
	  
scanf ("%d", &a);
	  
switch (a)
	    
	    {
	    
 
case 1:
	      
clrscr ();
	      
goto DISP;
	    
case 2:
	      printf ("Logging out...");
	      
delay (1000);
	      
main ();
	    
default:
	      clrscr ();
	      
goto DISP;
	    
}
	  
break;
	
case 3:
	  
add_att (id);
	  
 
 
printf ("\n\nEnter 1 for main menu or");
	  
 
printf ("\n2 for logout and exit..: ");
	  
 
scanf ("%d", &a);
	  
switch (a)
	    
	    {
	    
case 1:
	      
clrscr ();
	      
goto DISP;
	    
case 2:
	      printf ("Logging out...");
	      
delay (1000);
	      
main ();
	    
default:
	      clrscr ();
	      
goto DISP;
	    
}
	  
 
break;
	
case 4:
	  
clrscr ();
	  
header ();
	  
fp = fopen ("EMPLOYEE.DAT", "rb");
	  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
	    
	    {
	      
if (id == s.emp_id)
		
		{
		  
 
printf ("\nSalary of this Month: %s", s.salary);
		
 
}
	    
}
	  
fclose (fp);
	  
 
 
printf ("\n\nEnter 1 for main menu or");
	  
 
printf ("\n2 for logout and exit..: ");
	  
 
scanf ("%d", &a);
	  
switch (a)
	    
	    {
	    
case 1:
	      
clrscr ();
	      
goto DISP;
	    
case 2:
	      printf ("Logging out...");
	      
delay (1000);
	      
main ();
	    
default:
	      clrscr ();
	      
goto DISP;
	    
}
	  
 
break;
	
 
case 5:
	  viewwork (id);
	  
 
 
printf ("\n\nEnter 1 for main menu or");
	  
 
printf ("\n2 for logout and exit..: ");
	  
 
scanf ("%d", &a);
	  
switch (a)
	    
	    {
	    
case 1:
	      
clrscr ();
	      
goto DISP;
	    
case 2:
	      printf ("Logging out...");
	      
delay (1000);
	      
main ();
	    
default:
	      clrscr ();
	      
goto DISP;
	    
}
	  
break;
	
 
case 6:
	  
printf ("Logging out ");
	  
delay (2000);
	  
 
clrscr ();
	  
main ();
	
 
default:
	  printf ("\ninvalid number selected\n");
	  
delay (3000);
	  
goto DISP;
	
 
}
    
}
  
  else
    
    {
      
header ();
      
printf ("Invalid login...");
      
printf ("\n\nLogging out...");
      
delay (1000);
      
exit ();
    
}

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
									ADMIN
*/ 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
list_all () 
{
  
FILE * fp;
  
clrscr ();
  
header ();
  
fp = fopen ("EMPLOYEE.DAT", "rb");
  
if (fp == NULL)
    
    {
      
printf ("File Doesn't exits\n");
    
}
  
while ((fread (&s, sizeof (s), 1, fp) > 0))
    
    {
      
printf ("\nEMP_ID: %d", s.emp_id);
      
printf ("\nEmployee Name: %s", s.emp_name);
      
printf ("\nFather Name: %s", s.father_name);
      
printf ("\nEmployee's Ph. No.: %s", s.emp_ph_no);
      
printf ("\nFather's Ph. No.: %s", s.ft_ph_no);
      
printf ("\n=========");
      
printf ("\n");
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
									ADMIN
*/ 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
admin () 
{
  
 
int adm_choice, a, flag;
  
char masterkey[5], username[10], name[10], password[10];
  
clrscr ();
  
header ();
  
 
fflush (stdin);
  
 
printf ("Enter username: ");
  
gets (name);
  
fflush (stdin);
  
printf ("Enter password: ");
  
gets (password);
  
if (strcmp (name, "sanchit") == 0)
    
    {
      
if (strcmp (password, "sanchit") == 0)
	
	{
	
 
DISP:
clrscr ();
	  
header ();
	  
 
 
printf ("\n1. View Employee details.");
	  
 
printf ("\n2. Search Employee.");
	  
 
printf ("\n3. Modify Employee details.");
	  
 
printf ("\n4. Edit Employee salary or attendence.");
	  
 
printf ("\n5. Add New User login.");
	  
 
printf ("\n6. Add Work for Employee. ");
	  
 
printf ("\n7. Logout");
	  
 
printf ("\nEnter your choice: ");
	  
 
scanf ("%d", &adm_choice);
	  
 
 
switch (adm_choice)
	    
	    {
	    
case 1:
	      list_all ();
	      
 
 
printf ("\nEnter 1 for main menu or");
	      
 
printf ("\n2 for logout and exit..: ");
	      
 
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
main ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
case 2:
	      adm_search ();
	      
 
printf ("\nEnter 1 for main menu or");
	      
 
printf ("\n2 for logout and exit..: ");
	      
 
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
exit ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
case 3:
	      modify ();
	      
 
printf ("\nEnter 1 for main menu or");
	      
 
printf ("\n2 for logout and exit..: ");
	      
 
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
exit ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
case 4:
	      sal_att ();
	      
 
 
printf ("\nEnter 1 for main menu or");
	      
printf ("\n2 for logout and exit..: ");
	      
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
exit ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
case 5:
	      
newuser ();
	      
 
 
printf ("\nEnter 1 for main menu or");
	      
 
printf ("\n2 for logout and exit..: ");
	      
 
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
exit ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
 
case 6:
	      workstatus ();
	      
 
 
printf ("\nEnter 1 for main menu or");
	      
 
printf ("\n2 for logout and exit..: ");
	      
 
scanf ("%d", &a);
	      
switch (a)
		
		{
		
case 1:
		  
clrscr ();
		  
goto DISP;
		
case 2:
		  printf ("Logging out...");
		  
delay (1000);
		  
exit ();
		
default:
		  clrscr ();
		  
goto DISP;
		
}
	      
break;
	    
 
 
logout: 
case 7:
	      
printf ("Logging out ");
	      
delay (2000);
	      
 
clrscr ();
	      
main ();
	    
default:
	      printf ("invalid number selected");
	      
delay (3000);
	      
goto DISP;
	    
}
	
 
}
      
      else
	
	{
	  
header ();
	  
printf ("Invalid login...");
	  
delay (1000);
	  
main ();
	
}
    
}

 
}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  void
add_att (int id) 
{
  
int b;
  
clrscr ();
  
header ();
  
fp = fopen ("EMPLOYEE.DAT", "rb+");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (id == s.emp_id)
	
	{
	  
printf ("\nCurrentAttendence: %d\n", s.attendence);
	  
printf ("\n Enter 1 to mark attendence");
	  
printf ("\n 2 to leave without marking");
	  
printf ("\nEnter your option:");
	  
scanf ("%d", &b);
	  
switch (b)
	    
	    {
	    
case 1:
	      
s.attendence++;
	      
printf ("\n attendence change to: %d\n", s.attendence);
	      
fseek (fp, -(long) sizeof (s), 1);
	      
fwrite (&s, sizeof (s), 1, fp);
	      
delay (3000);
	      
break;
	    
 
 
case 2:
	      printf ("\nLogging out...\n");
	      
delay (1000);
	      
break;
	    
 
default:
	      printf ("without marking attendence");
	      
delay (2000);
	      
break;
	    
 
 
}
	  
break;
	
}
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
 
void
adm_search () 
{
  
 
int no;
  
clrscr ();
  
header ();
  
printf ("Enter EMP Id to search details: ");
  
scanf ("%d", &no);
  
fp = fopen ("EMPLOYEE.DAT", "rb");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (s.emp_id == no)
	
	{
	  
 
clrscr ();
	  
 
header ();
	  
printf ("Record Found");
	  
 
printf ("\nERP: %d", s.emp_id);
	  
printf ("\nEmployee Name: %s", s.emp_name);
	  
printf ("\nFather's Name: %s", s.father_name);
	  
printf ("\nEmployee Number: %s", s.emp_ph_no);
	  
printf ("\nFather's Number: %s", s.ft_ph_no);
	  
printf ("\nEmployee Salary: %s", s.salary);
	  
printf ("\nEmployee Attendence: %d", s.attendence);
	  
printf ("\nWork Assigned: %s", s.work);
	  
printf ("\nWork Status: %s", s.status);
	  
 
flag = 1;
	
}
    
}
  
if (flag == 0)
    
    {
      
gotoxy (40, 15);
      
printf ("\n\nRecord not found\n\n");
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
modify () 
{
  
FILE * fp;
  
int no, flag = 0;
  
 
 
printf ("Enter EMP_ID to modify: ");
  
 
scanf ("%d", &no);
  
fp = fopen ("EMPLOYEE.DAT", "rb+");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (s.emp_id == no)
	
	{
	  
 
clrscr ();
	  
 
header ();
	  
printf ("\nEMP_ID: %d", s.emp_id);
	  
 
printf ("\nEmployee Name: %s", s.emp_name);
	  
 
printf ("\nPress any key ...");
	  
getch ();
	  
 
clrscr ();
	  
header ();
	  
printf ("\nEnter new Detials");
	  
fflush (stdin);
	  
 
printf ("\nEnter Employee Name: ");
	  
 
gets (s.emp_name);
	  
fflush (stdin);
	  
 
printf ("\nEnter Father's Name: ");
	  
gets (s.father_name);
	  
fflush (stdin);
	  
 
printf ("\nEnter Employee Number: ");
	  
gets (s.emp_ph_no);
	  
fflush (stdin);
	  
 
printf ("\nEnter Father's Number: ");
	  
gets (s.ft_ph_no);
	  
fflush (stdin);
	  
 
 
fseek (fp, -(long) sizeof (s), 1);
	  
fwrite (&s, sizeof (s), 1, fp);
	  
 
 
printf ("Record Updated");
	  
delay (2000);
	
}
      
if (s.emp_id == no)
	
	{
	  
flag = 1;
	
}
    
}
  
 
fclose (fp);
  
if (flag == 0)
    
    {
      
header ();
      
printf ("Record doesn't exist");
    
}

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
 
void
workstatus () 
{
  
FILE * fp;
  
int no, flag = 0;
  
 
clrscr ();
  
header ();
  
printf ("Enter EMP_ID to assign work: ");
  
 
scanf ("%d", &no);
  
fp = fopen ("EMPLOYEE.DAT", "rb+");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (s.emp_id == no)
	
	{
	  
 
clrscr ();
	  
 
header ();
	  
printf ("\nEMP_ID: %d", s.emp_id);
	  
 
printf ("\nEmployee Name: %s", s.emp_name);
	  
 
printf ("\nCurrent work Assigned: %s", s.work);
	  
 
printf ("\nPress any key ...");
	  
getch ();
	  
 
clrscr ();
	  
header ();
	  
 
printf ("\nEnter new Detials");
	  
fflush (stdin);
	  
 
printf ("\nEnter Work to be Assigned: ");
	  
 
gets (s.work);
	  
fflush (stdin);
	  
 
printf ("\nEnter Work Status: ");
	  
 
gets (s.status);
	  
fflush (stdin);
	  
 
fseek (fp, -(long) sizeof (s), 1);
	  
fwrite (&s, sizeof (s), 1, fp);
	  
 
 
printf ("\n\nWork Assigned");
	  
delay (2000);
	
}
      
if (s.emp_id == no)
	
	{
	  
flag = 1;
	
}
    
}
  
 
fclose (fp);
  
if (flag == 0)
    
    {
      
header ();
      
printf ("Record doesn't exist");
    
}

}


 
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
  
void
viewwork (int id) 
{
  
clrscr ();
  
header ();
  
fp = fopen ("EMPLOYEE.DAT", "rb");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (id == s.emp_id)
	
	{
	  
 
printf ("\nProject you are working on: %s", s.work);
	  
printf ("\nYour Project Status: %s", s.status);
	
 
}
    
}
  
fclose (fp);

}


 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  
void
main () 
{
  
int choice;
  
int a, id;
  
char password[10];

ADM_DISP:clrscr ();
  
 
 
gotoxy (20, 8);
  
printf
    ("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
  
gotoxy (20, 9);
  
printf ("\xb2\xb2              LOGIN                \xb2\xb2");
  
gotoxy (20, 10);
  
printf ("\xb2\xb2             ~~~~~~~               \xb2\xb2");
  
gotoxy (20, 11);
  
printf ("\xb2\xb2 1. ADMIN                          \xb2\xb2");
  
gotoxy (20, 12);
  
printf ("\xb2\xb2                                   \xb2\xb2");
  
gotoxy (20, 13);
  
printf ("\xb2\xb2 2. USER                           \xb2\xb2");
  
gotoxy (20, 14);
  
printf ("\xb2\xb2                                   \xb2\xb2");
  
gotoxy (20, 15);
  
printf ("\xb2\xb2 3. EXIT                           \xb2\xb2");
  
gotoxy (20, 16);
  
printf ("\xb2\xb2                                   \xb2\xb2");
  
gotoxy (20, 17);
  
printf ("\xb2\xb2 Enter your choice:                \xb2\xb2");
  
gotoxy (20, 18);
  
printf ("\xb2\xb2                                   \xb2\xb2");
  
gotoxy (20, 19);
  
printf
    ("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
  
gotoxy (43, 17);
  
scanf ("%d", &choice);
  
 
 
switch (choice)
    
    {
    
case 1:
      admin ();
      
break;
    
case 2:
      clrscr ();
      
header ();
      
fflush (stdin);
      
printf ("Enter emp_id: ");
      
scanf ("%d", &id);
      
fflush (stdin);
      
printf ("Enter password: ");
      
gets (password);
      
user (id, password);
      
printf
	("\n\nPress 1 for logout and  main menu or 2 for logout and exit...");
      
scanf ("%d", &a);
      
switch (a)
	
	{
	
case 1:
	  goto ADM_DISP;
	
case 2:
	  exit ();
	
}
      
break;
    
case 3:
      exit ();
    
default:
      goto ADM_DISP;
    
}
  
getch ();

}


 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
void
sal_att () 
{
  
FILE * fp;
  
int no, flag = 0;
  
printf ("Enter EMP_ID to edit salary or attendence of Employee: ");
  
 
scanf ("%d", &no);
  
fp = fopen ("EMPLOYEE.DAT", "rb+");
  
while ((fread (&s, sizeof (s), 1, fp)) > 0)
    
    {
      
if (s.emp_id == no)
	
	{
	  
clrscr ();
	  
 
header ();
	  
printf ("\nEMP_ID: %d", s.emp_id);
	  
printf ("\nEmployee Name: %s", s.emp_name);
	  
printf ("\nEmployee Attendence: %d", s.attendence);
	  
printf ("\nEmployee Monthly Salary: %s", s.salary);
	  
printf ("\nPress any key ...");
	  
getch ();
	  
 
clrscr ();
	  
header ();
	  
printf ("\nModify Detials");
	  
fflush (stdin);
	  
 
printf ("\nEnter Employee Salary: ");
	  
 
gets (s.salary);
	  
fflush (stdin);
	  
 
printf ("\nEnter Employees Attendence:");
	  
scanf ("%d", &s.attendence);
	  
 
 
 
fseek (fp, -(long) sizeof (s), 1);
	  
fwrite (&s, sizeof (s), 1, fp);
	  
 
 
printf ("\nSucessfully Modified");
	
}
      
if (s.emp_id == no)
	
	{
	  
flag = 1;
	
}
    
}
  
 
fclose (fp);
  
if (flag == 0)
    
    {
      
header ();
      
printf ("Record doesn't exist\n");
    
}

}


 
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
  
void
header () 
{
  
 
int i;
  
clrscr ();
  
gotoxy (27, 2);
  
printf ("EMPLOYEE MANAGEMENT SYSTEM");
  
gotoxy (34, 3);
  
printf ("MINOR PROJECT");
  
gotoxy (29, 4);
  
printf ("BY SANCHIT AND YUKTESHWAR\n");
  
for (i = 1; i <= 79; i++)
    
    {
      
 
gotoxy (i, 5);
      
printf ("\xb2");
    
}
  
printf ("\n");

}
