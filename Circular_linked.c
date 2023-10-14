#include<stdio.h>
#include<stdlib.h>
typedef struct clist
{
        int data;
        struct clist *next;
}list;
list* create(list *f)
{
        list *new,*t;
        int val;
        printf("enter  vlaues (-1 to stop)\n");
        scanf("%d",&val);
        while(val!=999)
        {
        new=(list*)malloc(sizeof(list));
        new->data=val;
        new->next=NULL;
        if(f==NULL)
        f=new;    
        else
        t->next=new;
        t=new;
        scanf("%d",&val);
        }
        new->next=f;
        printf("list is created\n");
        return f;
}
void display(list *f)
{
        list *t;
        if(f==NULL)
                printf("list is empty\n");
        else
        {
                t=f;
                do
                {
                        printf("%d--->",t->data);
                        t=t->next;
                }while(t!=f);
        }
}
list* insbeg(list *f,int ele)
{
        list *t,*new;
        new=(list*)malloc(sizeof(list));
        new->data=ele;
        new->next=NULL;
        if(f==NULL)
        {
                f=new;
                new->next=f;
        }
        else
        {
                t=f;
                while(t->next!=f)
                t=t->next;
                t->next=new;
                new->next=f;
                f=new;
}
        return f;
}
list* insend(list *f,int ele)
{
        list *t,*new;
        new=(list*)malloc(sizeof(list));
        new->data=ele;
        new->next=NULL;
        if(f==NULL)
        {
                f=new;
                new->next=f;
        }
        else
        {
                t=f;
                while(t->next!=f)
                t=t->next;
                t->next=new;
                new->next=f;
        }
        return f;
}
int cnt(list *f)
{
        list* t;
        int c=0;
        if(f==NULL)
                return c;
        else
        {
                t=f;
                do
                {
                        c++;
                        t=t->next;
                }while(t!=f);
        }
        return c;
}
list* inspos(list *f,int ele,int pos)
{
        list *new,*t;
        int i,c;
        c=cnt(f);
        if(pos==0)
                f=insbeg(f,ele);
        else if(pos==c)
                f=insend(f,ele);
        else if(pos>0&&pos<c)
        {
                new=(list*)malloc(sizeof(list));
                new->data=ele;
                new->next=NULL;
                t=f;
                for(i=0;i<pos-1;i++)
                        t=t->next;
                new->next=t->next;
                t->next=new;
        }
        else
                printf("invalid position\n");
        return f;
}
list* delbeg(list *f)
{
        list *t;
        if(f==NULL)
                printf("list is empty\n");
        else if(f->next==f)
        {
                t=f;
                f=NULL;
                free(t);
        }
        else
        {
                t=f;
                while(t->next!=f)
                        t=t->next;
                t->next=f->next;
                t=f;
                f=f->next;
                free(t);
        }
        return f;
}
list* delend(list *f)
{
        list *t,*prev;
        if(f==  NULL)
                printf("list is empty\n");
        else if(f->next==f)
        {
                t=f;
                f=NULL;
                free(t);
        }
        else
        {
                t=f;
                while(t->next!=f)
                {
                        prev=t;
                        t=t->next;
                }
                prev->next=t->next;
                free(t);
        }
        return f;
}
list* delpos(list *f, int pos)
{
        list *t,*pre;
        int i,c;
        c=cnt(f);
        if(pos==0)
                f=delbeg(f);
        else if(pos==c-1)
                f=delend(f);
        else if(pos>0&&pos<c-1)
        {
                t=pre=f;
                for(i=0;i<pos;i++)
                {
                        pre=t;
                        t=t->next;
                }
                pre->next=t->next;
                free(t);
        }
        else
                printf("invalid posiion\n");
        return f;
}
void search(list *f,int ele)
{
        list *t;
        int c=0;
        if(f==NULL)
                printf("list is empty\n");
        else
        {
        t=f;
        do
        {
                if(t->data==ele)
                {
                        printf("element is found at %d location\n",c);
                        break;
                }

                else
                        t=t->next;
                c++;
        }while(t!=f);
        if(t==f)
                printf("element is not in the list\n");
        }
}
void sort(list *f)
{
        list *t1,*t2;
        int x;
        for(t1=f;t1->next!=f;t1=t1->next)
        {
                for(t2=t1->next;t2!=f;t2=t2->next)
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

int main()
{
        list *head=NULL;
        int ch,ele,pos,c;
        do
        {
        printf("\nenter your option\n");
        printf("1.create\n2.display\n");
        printf("3.insert at begin\n4.insert at end\n");
        printf("5.count the nodes\n6.insert at given position\n");
        printf("7.delete at begin\n8.delete at end\n");
        printf("9.delete at given position\n");
        printf("10.search the given element\n");
        printf("11.to sort the elements\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        head=NULL;
                        head=create(head);
                        break;
                case 2:
                        display(head);
                        break;
                case 3:
                        printf("enter an element\n");
                        scanf("%d",&ele);
                        head=insbeg(head,ele);
                        display(head);
                        break;
                case 4:
                        printf("enter an element\n");
                        scanf("%d",&ele);
                        head=insend(head,ele);
                        display(head);
                        break;
                case 5:
                        c=cnt(head);
                        printf("no.of nodes =%d\n",c);
                        break;
                case 6:
                        printf("enter element and position to insert\n");
                        scanf("%d%d",&ele,&pos);
                        head=inspos(head,ele,pos);
                        display(head);
                        break;
                case 7:
                        head=delbeg(head);
                        display(head);
                        break;
                case 8:
                        head=delend(head);
                        display(head);
                        break;
                case 9:
                        printf("enter a position\n");
                        scanf("%d",&pos);
                        head=delpos(head,pos);
                        display(head);
                        break;
                case 10:
                        printf("enter an element to search\n");
                        scanf("%d",&ele);
                        search(head,ele);
                        break;
                case 11:
                        sort(head);
                        display(head);
                        break;

        }
        }
        while(ch>=1&&ch<=11);
}

