#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//structure for a node containing datd and left and right node
struct node
{
    int data;
    struct node*left;
    struct node*right;

};

struct node *root=NULL;
struct node *CreateNode(int data)
{
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
//Now we will initiaslize a queue
struct queue
{
    int front,rear,size;
    struct node* *arr;
};

//creating a queue
struct queue *CreateQueue()
{
    struct queue *newQueue = (struct node*)malloc(sizeof(struct node));
    newQueue->front=-1;
    newQueue->rear=0;
    newQueue->size=0;

    newQueue->arr=(struct node**)malloc(100*sizeof(struct node*));
    return newQueue;
}
void Enqueue(struct queue *queue,struct node *temp)
{
   queue->arr[queue->rear++]=temp;
   queue->size++;

}

void dequeue(struct queue *queue)
{
    queue->size--;
   return queue->arr[++queue->front];
}

void InsertNode(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    else
    {
        struct queue *queue=createqueue();
        Enqueue(queue,root);
        while(true)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                Enqueue(queue,root->left);
                Enqueue(queue,root->right);
                
            }
        }
      
    }
}

int main()
{
    int ch=0;
    int data;
    while(ch!=4)
    {
        printf("\n1.Insert\n2.Delete\n3.Traversal\n");
        sca4nf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data:");
                    scanf("%d",&data);
                    CreateNode(data);
                    break;
            case 2: printf("Enter the data that you want to enter\n");
                    scanf("%d",&data);
                    
        }
        
    }
    
    
    
    return 0;
}