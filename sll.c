#include<stdio.h>
#include<stdlib.h>
typedef struct slist
{
        int data;
        struct slist *next;
}
sll;
int main()
{
        sll * create(sll *);
        void display(sll *);
        sll * insbegin(sll *,int );
        sll * insend(sll *,int );
       void insatpos(sll *,int ,int );
       int count(sll *);
       sll * delatbegin(sll *);
       sll * delatend(sll *);
       void delatpos(sll *,int );
       void search(sll *,int );
       void sort(sll *);
       sll* reverse(sll*);
        sll *head=NULL;
        int ch,ele,pos,c;
        do
        {
                printf("\n\n1.create\n2.display\n3.insatbegin\4.insatend\5.count\n");
                printf("6.insatpos\n7.delatbegin\n8.delatend\n9.delatpos\n10.search\n11.sort12.Reverse\n");
                scanf("%d",&ch);
                        switch(ch)
                      {
                        case 1:
                                head=create(head);
                                break;
                        case 2:
                                display (head);
                                break;
                        case 3:
                                printf ("enter an elemant to insert \n");
                                scanf("%d",&ele);
                                head=insbegin(head,ele);
                                break;
                        case 4:
                                printf("enter elemant to insert\n");
                                scanf("%d",&ele);
                                head=insend(head,ele);
                                break;
                        case 5: c=count(head);
                                printf("count=%d\n",c);
                                break;
                        case 6:
                                printf("enter elemant and position to insert\n");
                                scanf("%d %d",&ele,&pos);
                                 insatpos(head,ele,pos);
                                break;
                        case 7:
                                head=delatbegin(head);
                                        break;
                        case 8:
                                        head=delatend(head);
                                        break;
                        case 9:
                                        printf("enter position to sll\n");
                                        scanf("%d",&pos);
                                        delatpos(head,pos);
                                        break;
                        case 10:
                                        printf("element to search\n");
                                        scanf("%d",&ele);
                                        search(head,ele);
                                        break;
                        case 11:
                                        sort(head);
                                        break;
                        case 12:       head=reverse(head);
                                        break;
                }
        }
        while(ch>=1&&ch<=12);
}                         


sll * create(sll *f)
{
        sll *new,*t;
        int ele;
        printf("enter value(enter -1 to stop)\n");
        scanf("%d",&ele);
        while(ele!=-1)
        {
                new=(sll *)malloc(sizeof(sll));
                new->data=ele;
                new->next=NULL;
                if(f==NULL)
                        f=new;
                else
        {
                t->next=new;
        }
                t=new;
                printf("enter value press 9999 to stop\n");
                scanf("%d",&val);
        }
             return f;
}
void display(sll *f)
{
        if(f==NULL)
        {
                printf("list is empty\n");
                return;
        }
        printf("forward traversal of list\n");\
                while(f->next!=NULL)
                {
                        printf("%d\t",f->data);
                        f=f->next;
                }
        printf("%d\t",f->data);
}

sll * insbegin(sll *f,int ele)
{
        sll *new;
        new=(sll *)malloc(sizeof(sll));
        new->data=ele;
        new->next=NULL;
        if(f==NULL)
                f=new;
        else
        {
                new->next=f;
                f=new;
        }
        return f;
}
sll * insend(sll *f,int ele)
{
        sll *new,*t;
        new=(sll *)malloc(sizeof(sll));
        new->data=ele;
        new->next=NULL;
        if(f==NULL)
                f=new;
        else
        {
                t=f;
                while(t->next!=NULL)
                        t=t->next;
                t->next=new;
        }
        return f;
}
int count(sll *f)
{
        int c=0;
        while(f!=NULL)
{
        c++;
        f=f->next;
}
return c;
}
void insatpos(sll *f,int ele,int pos)
{
        sll *new,*t;
        int cnt,i;
         cnt=count(f);
        if(pos>0&&pos<cnt)
        {
                new=(sll *)malloc(sizeof(sll));
                new->data=ele;
                new->next=NULL;
                t=f;
                for(i=0;i<pos-1;i++)
                        t=t->next;
                new->next=t->next;
                t->next=new;
        }
        else printf("Invalid position");
}
sll * delatbegin(sll *f)
{
                sll *t;
                if(f==NULL)
                        printf("list is empty\n");
                else
                {
                        t=f;
                        f=f->next;
                        free(t);
                }
                        return f;
        }
        sll * delatend(sll *f)
        {
                sll *t,*prev;
                if(f==NULL)
                        printf("list is empty\n");
                else
                       {
                                                                                                                                          188,1-8       70%
                        t=f;
                        while(t->next!=NULL)
                        {
                                prev=t;
                                t=t->next;
                        }
                        free(t);
                        prev->next=NULL;
                }
                return f;
        }
        void delatpos(sll *f,int pos)
        {
                sll *t,*prev;
                int c,i;
                c=count(f);
                if(pos>0&&pos<c-1)
                {
                        t=f;
                        for(i=0;i<pos;i++)
                        {
                                prev=t;
                                t=t->next;
                        }
                        prev->next=t->next;
                        free(t);
                }
                else
                        printf("invalid position\n");
        }
        void search(sll *f,int ele)
        {
                while(f!=NULL)
                {
                        if(f->data==ele)
                        {
                                printf("%d is found\n",ele);
                                  break;
                        }
                        else
                                f=f->next;
                }
                if(f==NULL)
                        printf("elment not found\n");
        }
        void  sort(sll *f)
        {
                sll *t1,*t2;
                int x;
                for(t1=f;t1!=NULL;t1=t1->next)
                {
                        for(t2=t1->next;t2!=NULL;t2=t2->next)
                        {
                                if(t1->data>t2->data)
                                {
                                        x=t1->data;
                                        t1->data=t2->data;
                                        t2->data=x;
                                }
                        }
                }
         }
         sll *reverse(sll *f)
         {   sll *save,*present=f,*prev=NULL;
              while(present!=NULL) 
              { save=present->next;
                present->next=prev;
                prev=present;
                present=save;
              }
               return prev;
          }
                              
                                      
