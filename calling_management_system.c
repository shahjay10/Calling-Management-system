#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <time.h>

struct node {
    char name[50];
    char number[10];
    int freq;
    struct node* prev;
    struct node* next;
};
int rear = -1;
int front = -1;
int size = 5;
struct node* que[5];
struct node* head=NULL;
struct node* current=NULL;

void delay(int d){
int milli_seconds = 1000 * d;
clock_t start_time = clock();
 while (clock() < start_time + milli_seconds)
        ;
}
void red(){
    printf("\033[1;31m");
}
void black(){
printf("\033[0;30m");
}
void green(){
printf("\033[0;32m");
}
void yellow(){
printf("\033[1;33m");
}
void blue(){
printf("\033[0;34m");
}
void purple(){
printf("\033[0;35m");
}
void cyan(){
printf("\033[0;36m");
}
void white(){
printf("\033[0;37m");
}
void reset(){
printf("\033[0m");
}
void sort(){
struct node * temp=head;
do{
  struct node* temp1=temp;
  while(temp1->next!=NULL){
    temp1=temp1->next;
    if(strcmp(temp->name,temp1->name)>0){
  char num[11],na[50];
  int k;
  strcpy(na,temp->name);
  strcpy(num,temp->number);
  strcpy(temp->name,temp1->name);
  strcpy(temp->number,temp1->number);
  strcpy(temp1->name,na);
  strcpy(temp1->number,num);
  k=temp->freq;
  temp->freq=temp1->freq;
  temp1->freq=k;

    }

  }
      temp=temp->next;
}while(temp->next!=NULL);
}

struct node* add(struct node* ptr){
 if(head==NULL){
 head=(struct node *)malloc(sizeof(struct node));
 //printf("--------------------CONTACT DETAILS---------------------------");
 blue();
 printf("\nNAME: ");
 fflush(stdin);
 gets(head->name);
 do{printf("PHONE NO.: ");
 fflush(stdin);
  gets(head->number);
  red();
  if(strlen(head->number)!=10) printf("INVALID NUMBER!!\n");
  }while(strlen(head->number)!=10);
  head->freq=0;
 head->prev=NULL;
 head->next=NULL;
 return head;
 }
 else{
 struct node* temp=NULL;
 temp=(struct node*)malloc(sizeof(struct node));
// printf("--------------------CONTACT DETAILS--------------------------");
blue();
 printf("\nNAME: ");
 fflush(stdin);
gets(temp->name);
int flag=0;
do{ printf("PHONE NO.: ");
fflush(stdin);
  gets(temp->number);
  flag=0;
  red();
    for(int i=0;i<strlen(temp->number);i++){
    if((temp->number[i])<'0'||(temp->number[i])>'9') flag=1;
  }
   if(strlen(temp->number)!=10||flag==1) printf("INVALID NUMBER!!\n");
  
  }while(strlen(temp->number)!=10||flag==1);

  temp->freq=0;
 temp->prev=ptr;
 temp->next=NULL;
 ptr->next=temp;
     sort();
 return temp;
 }
}

void display(){
struct node* temp=head;
if(head==NULL){
    yellow();
    printf("CONTACT LIST EMPTY\n");
    reset();
}
else{
    red();
    printf("<----------------------------------------------------------------CONTACT LIST-------------------------------------------------------------------->");
    reset();
    printf("\n");
    printf("__________________________________________________________________________________________________________________________________________________");
    printf("\n");
    yellow();
    printf("Sr.NO\t\t\t\t\t\t\t\t\tName\t\t\t\t\t\t\tNUMBER\n");
    reset();
     printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
     int count=1;
    do{
        yellow();
    printf("%d",count);
printf("\t\t\t\t\t\t\t\t\t%s",temp->name);
  if(strlen(temp->name)<=7) printf("\t");
printf("\t\t\t\t\t\t%s\n",temp->number);
temp=temp->next;
count++;
}while(temp!=NULL);
reset();
yellow();
printf("Do you want to call someone:\n");
printf("1>YES\n2>NO");
int choice;
while(1){
scanf("%d",&choice);
if(choice==1){
 int num;
 printf("Enter the serial no you want to call: ");
 scanf("%d",&num);
 struct node*temp=head;
 for(int i=0;i<num-1;i++){
  temp=temp->next;
 }
  (temp->freq)++;
  green();
  printf("CALLING %s",temp->name);
    for(int i=0; i<2; i++){
        delay(1);
        printf("..");
    }
    red();
printf("\nCALL ENDED\n");
delay(1);
 break;
}
else if(choice==2){
break;
}
else{
    red();
    printf("Invalid Choice Entered...\n");
}
}
}
}
void del(char s[50]){
    int t=0;
    struct node* temp=head;
while(temp!=NULL){
if(strcmp(temp->name,s)==0) {
        t=1;
        break;}
temp=temp->next;
}
if(t==0){
    red();
    printf("CONTACT NOT FOUND\n");
}
else{
if(temp==head)
    head=temp->next;
if(temp==current)
    current=temp->prev;

temp->prev->next=temp->next;
temp->next->prev=temp->prev;

red();
printf("CONTACT REMOVED\n");
free(temp);
}}

void edit(char s[50]){
int t=0;
char s1[50];
struct node* temp=head;

while(temp!=NULL){
if(strcmp(temp->name,s)==0) {
        t=1;
        break;}
temp=temp->next;
}
if(t==0||head==NULL){
    red();
    printf("CONTACT NOT FOUND\n");
}
else{
printf("%s\t%s",temp->name,temp->number);
reset();
printf("ENTER NEW NAME:");
fflush(stdin);
gets(s1);
strcpy(temp->name,s1);
printf("ENTER NEW NUMBER: ");
fflush(stdin);
gets(s1);
strcpy(temp->number,s1);
}
}

void searchname(){
struct node* temp=head;
char s[30];
printf("ENTER NAME:\n");
fflush(stdin);
gets(s);
int length=strlen(s),flag=0,f=0;
red();
if(temp==NULL) printf("CONTACT LIST IS EMPTY\n");
else{
do{ flag=0;
    for(int i=0;i<length;i++){
        if(s[i]!=temp->name[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        if(f==0)
        green();
        printf("CONTACTS FOUND: \n");
        f=1;
        printf("%s",temp->name);
        printf("\t\t%s\n",temp->number);

    }
    temp=temp->next;
}while(temp!=NULL);
if(f==0){
    red();
    printf("NO RESULTS FOR %s\n",s);
}
}
}

void searchnum(){
struct node* temp=head;
char s[30];
printf("ENTER NUMBER:\n");
fflush(stdin);
gets(s);
int length=strlen(s),flag=0,f=0;
red();
if(temp==NULL) printf("CONTACT LIST IS EMPTY\n");
else{
do{ flag=0;
    for(int i=0;i<length;i++){
        if(s[i]!=temp->number[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        if(f==0)
        green();
        printf("CONTACTS FOUND: \n");
        f=1;
        printf("%s",temp->name);
        printf("\t\t%s\n",temp->number);
        printf("\n");
    }
    temp=temp->next;
}while(temp!=NULL);
if(f==0){
    red();
    printf("NO RESULTS FOR %s\n",s);
}
}
}

void frequent(){
struct node* temp=head;
while(temp!=NULL){
        struct node* temp1=temp;
        while(temp1!=NULL){
    if((temp1->freq)>(temp->freq)){
  char num[11],na[50];
  int k;
  strcpy(na,temp->name);
  strcpy(num,temp->number);
  strcpy(temp->name,temp1->name);
  strcpy(temp->number,temp1->number);
  strcpy(temp1->name,na);
  strcpy(temp1->number,num);
  k=temp->freq;
  temp->freq=temp1->freq;
  temp1->freq=k;

    }
    temp1=temp1->next;
        }
   temp=temp->next;
}
int j =0;
temp=head;
red();
  printf("__________________________________________________________________________________________________________________________________________________");
  printf("\n<-------------------------------------------------------------MOST FREQUENT------------------------------------------------------------------->\n");
  printf("__________________________________________________________________________________________________________________________________________________\n");
yellow();
printf("\n\t\t\t\t\tNAME \t\tNUMBER\n");
while(temp!=NULL&&j<5){
        if(temp->freq!=0){

printf("\t\t\t\t\t%s\t\t%s\n",temp->name,temp->number);

        }
        temp=temp->next;
        j++;
}
}

void insert(struct node* ptr){
    if(front==-1&&rear==-1){
        rear=0;
        front=0;
        }
        else if(((rear+1)%size)==front)
        {
          rear=(rear+1)%size;
          front=(front+1)%size;
        }
        else{
        rear=(rear+1)%size;
        }
que[rear]=ptr;
}

void recent(){
int i=rear;
struct node* ptr=que[i];
red();
  printf("__________________________________________________________________________________________________________________________________________________");
  printf("\n<-------------------------------------------------------------RECENT LOGS------------------------------------------------------------------->\n");
  printf("__________________________________________________________________________________________________________________________________________________\n");
yellow();
printf("\n\t\t\t\t\tNAME \t\tNUMBER\n");
while(i!=front){
if(ptr!=NULL){
ptr=que[i];
printf("\t\t\t\t\t%s\t\t%s\n",ptr->name,ptr->number);
if(i==0){
    i=4;
}
else{
    i--;
}}
}
if(que[front]!=NULL){
ptr=que[front];
printf("\t\t\t\t\t%s\t\t%s\n",ptr->name,ptr->number);
}
}

void call(char s[50]){
    int t=0;

    struct node* temp=head;
while(temp!=NULL){
if(strcmp(temp->name,s)==0) {
        t=1;
        break;}
temp=temp->next;
}
if(t==0){
    red();
    printf("\t\t\t\t\tCONTACT NOT FOUND\n");
}
else{
    green();
printf("\t\t\t\t\tCALLING %s",temp->name);
    for(int i=0; i<2; i++){
        delay(1);
        printf("..");
    }
    red();
printf("\n\t\t\t\t\tCALL ENDED\n");
delay(1);
temp->freq=temp->freq+1;
insert(temp);
}
}

int main(){
    char n[50];
    int sw;
    do{
        red();
        printf("__________________________________________________________________________________________________________________________________________________");
        printf("\n<-------------------------------------------------------------Phone Directory-------------------------------------------------------------------->\n");
        printf("__________________________________________________________________________________________________________________________________________________\n");
        reset();
        green();
        printf("\t\t\t\t\t1.CONTACT LIST          \t");
        printf("2.ADD NEW CONTACT\n");
        printf("\t\t\t\t\t3.DELETE CONTACT        \t");
        printf("4.EDIT CONTACT\n");
        printf("\t\t\t\t\t5.CALL                  \t");
        printf("6.SEARCH BY NAME\n");
        printf("\t\t\t\t\t7.SEARCH BY NUMBER      \t");
        printf("8.RECENT CONTACTS\n");
        printf("\t\t\t\t\t9.MOST FREQUENT CONTACTS\t");
        printf("10.EXIT\n");
        cyan();
        printf("Please Enter your choice: ");
scanf("%d",&sw);
reset();
switch(sw){
case 1:

    display();
    break;
case 2:
   current=add(current);
    break;
case 3:
cyan();
    printf("\t\t\t\t\tENTER NAME:");
    fflush(stdin);
    gets(n);
    del(n);
    break;
case 4:
cyan();
    printf("\t\t\t\t\tENTER NAME:");
    fflush(stdin);
    gets(n);
    edit(n);
    break;
case 5:
    printf("\t\t\t\t\tENTER NAME:");
    fflush(stdin);
    gets(n);
    call(n);
     break;
case 6:
    searchname();
    break;
case 7:
     searchnum();
    break;
case 8:
    recent();
    break;
case 9:
    frequent();
    break;
case 10:
yellow();
    printf("\t\t\t\t\tDSA - INNOVATIVE ASSIGNMENT\n");
    printf("\t\t\t\t\t21BCE269\n21BCE270\n21BCE271");
    break;
default:
red();
    printf("\t\t\t\t\tENTER A VALID CHOICE!!\n");
    break;
}
}while(sw!=10);

}