#include<stdio.h>
#include<stdlib.h>
typedef struct dlist
{ int data;
struct dlist *prev,*next;
}dll;
dll* cre(dll *f)
{
        dll *new,*t;
        int val;
        printf("enter elements (-1 to stop)\n");
        scanf("%d",&val);
        while(val!=-1)
        {
                new=(dll*)malloc(sizeof(dll));
                new->data=val;
                new->next=NULL;
                new->prev=NULL;
                if(f==NULL)
                        f=new;
                else
                {
                        new->prev=t;
                        t->next=new;
                }
                t=new;
                scanf("%d",&val);
        }
        printf("list is created\n");
        return f;
}
void display(dll *f)
{
        if(f==NULL)
        {
                printf("list is empty\n");
                        return;
        }
        printf("list in forward traversal\n");
        while(f->next!=NULL)
        {
                printf("%d  <====> ",f->data);
                f=f->next;
        }
        printf("%d\n",f->data);
        printf("list in reverse traversal\n");
        while(f!=NULL)
        {
                printf("%d <====> ",f->data);
                f=f->prev;
        }
}
dll* insbeg(dll *f,int ele)
{
        dll *new;
        new=(dll*)malloc(sizeof(dll));
        new->data=ele;
        new->next=NULL;
        new->prev=NULL;
        if(f==NULL)
        {
                f=new;
        }
        else
        {
                f->prev=new;
                new->next=f;
        }
        return new;
}
dll* insend(dll *f,int ele)
{
        dll *new,*t;
        new=(dll*)malloc(sizeof(dll));
        new->data=ele;
        new->next=NULL;
        new->prev=NULL;
        if(f==NULL)
                f=new;
        else
        {
                t=f;
                while(t->next!=NULL)
                        t=t->next;
                t->next=new;
                new->prev=t;
        }
        return f;
}
int cnt(dll *f)
{
        int c=0;
        while(f!=NULL)
        {
                c++;
                f=f->next;
        }
        return c;
}
dll* inspos(dll *f,int ele,int pos)
{
        dll *t,*new;
        int c,i;
        c=cnt(f);
        if(pos==0)
                f=insbeg(f,ele);
         else if(pos==c)
                f=insend(f,ele);
        else if(pos>0&&pos<c)
        {
                new=(dll*)malloc(sizeof(dll));
                new->data=ele;
                new->next=NULL;
                new->prev=NULL;
                t=f;
                for(i=0;i<pos-1;i++)
                        t=t->next;
                new->next=t->next;
                new->prev=t;
                t->next=new;
                new->next->prev=new;

        }
        else
                printf("invalid position\n");
        return f;
}
dll* delbeg(dll *f)
{
        dll *t;
        if(f==NULL)
        return f;
        else
        {
                t=f;
                f=f->next;
                f->prev=NULL;
                free(t);
        }
        return f;
}
dll* delend(dll *f)
{
        dll *t;
        if(f==NULL)
                return f;
        else
        {
                t=f;
                while(t->next!=NULL)
                        t=t->next;
                if(t->prev!=NULL)
                        t->prev->next=NULL;
                else
                        f=NULL;
                free(t);
        }
        return f;
}
dll* delpos(dll *f,int pos)
{
        dll *t;
        int c,i;
        c=cnt(f);
        if(pos==0)
                f=delbeg(f);
        else if(pos==c-1)
                f=delend(f);
        else if(pos>0&&pos<c-1)
        {
                t=f;
                for(i=0;i<pos;i++)
                        t=t->next;
                t->prev->next=t->next;
                t->next->prev=t->prev;
                free(t);
        }
        else
                printf("invalid position\n");
        return f;
}
void ser(dll *f,int ele)
{
        int c=0;
        if(f==NULL)
                printf("list is empty\n");
        while(f!=NULL)
        {
                if(f->data==ele)
                {
                        printf("element is found at %d position\n",c);
                        break;
                }
                else
                        f=f->next;
                c++;
        }
        if(f==NULL)
                printf("element is not in the list\n");
}
void sort(dll *f)
{
        dll *t1,*t2;
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

int main()
{
        dll *head=NULL;
        int ch,ele,c,pos;
        do
        {
        printf("\nenter your option\n");
        printf("1.create\n2.display\n");
        printf("3.insert at begin\n");
        printf("4.insert at end\n");
        printf("5. count the no.of nodes\n");
        printf("6.insert at position\n");
        printf("7.delete at begin\n");
        printf("8.delete at end\n");
        printf("9.delete at position\n");
        printf("10.search an element\n");
        printf("11.sort the elemnts\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        head=cre(head);
                        break;
                case 2:
                        display(head);
                        break;
                case 3:
                        printf("enter element\n");
                        scanf("%d",&ele);
                        head=insbeg(head,ele);
                        display(head);
                        break;
                case 4:
                        printf("enter element\n");
                        scanf("%d",&ele);
                        head=insend(head,ele);
                        display(head);
                        break;
                case 5:
                        c=cnt(head);
                        printf("no.of nodes=%d\n",c);
                        break;
                case 6:
                        printf("enter element and position\n");
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
                        printf("enter position\n");
                        scanf("%d",&pos);
                        head=delpos(head,pos);
                        display(head);
                        break;
                case 10:
                        printf("enter element to search\n");
                        scanf("%d",&ele);
                        ser(head,ele);
                        break;
                case 11:
                        sort(head);
                        display(head);
                        break;

        }
        }while(ch>=1&&ch<=11);
}


