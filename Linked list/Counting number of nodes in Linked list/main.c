#include<stdio.h>
#include<conio.h>

struct node
{
    int num;
    struct node*link;
}*m ;
void createnode(int n)
{
    struct node *temp,*r;
    int num,i;
    m=(struct node*)malloc(sizeof(struct node));
    if(m==NULL)
    {

        printf("No memory allocation");

    }
    else
    {
        printf("Enter the data for node 1=");
        scanf("%d",&num);
        m->num=num;
        m->link=NULL;
        temp=m;

        for(i=2;i<=n;i++)
        {
             r=(struct node*)malloc(sizeof(struct node));
             if(r==NULL)
             {

                printf("No memory allocation");
                break;
             }
             else
             {
                 printf("Enter the data for node %d=",i);
                 scanf("%d",&num);
                 r->num=num;
                 r->link=NULL;
                 temp->link=r;
                 temp=temp->link;
             }
        }
    }
}
void displaynode()
{
    struct node* tmp;
    if(m==NULL)
    {
        printf("No memory allocation");
    }
    else
    {
        tmp=m;
        while(tmp!=NULL)
        {
            printf("\n%d\n",tmp->num);
            tmp=tmp->link;
        }
    }
}
int countnodes()
{
    int count=0;
    struct node* temp;
    temp=m;
    while(temp!=NULL)

    {
        count++;
        temp=temp->link;
    }
    return count;
}

int main()
{
    int n;
    printf("Enter the number of nodes=");
    scanf("%d",&n);
    createnode(n);
    printf("Data entered=");
    displaynode();
    int total_nodes=countnodes();
    printf("\nTotal nodes=%d",total_nodes);
    printf("\n");
    return 0;
}
