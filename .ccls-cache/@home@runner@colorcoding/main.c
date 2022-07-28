#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double net=0;
long long int sum = 0;

struct Node {
    char s[6];
    int key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST Node
struct Node* newNode(char item[],int key)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->s, item);
    temp->key=key;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert
   a new Node with given key in
 * BST */
struct Node* insert(struct Node* Node, char s[],int key)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL)
        return newNode(s,key);
 
    /* Otherwise, recur down the tree */
    if (strcmp (s,Node->s)<0)
        Node->left = insert(Node->left, s,key);
    else if (strcmp(s,Node->s)>0)
        Node->right = insert(Node->right, s,key);
 
    /* return the (unchanged) Node pointer */
    return Node;
}

struct Node* trav(struct Node* Node, char s[])
{
    if (strcmp (s,Node->s)==0 || Node==NULL)
      return Node;
    /* Otherwise, recur down the tree */
    if (strcmp (s,Node->s)<0){
      return trav(Node->left, s);}
    else if (strcmp(s,Node->s)>0){
        return trav(Node->right, s);
    }
    /* return the (unchanged) Node pointer */
    return Node;
}
// Firstly we need to design the resistor for 3 different cases 1. 4 bands 2. 5 bands and 3.6 bands

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void newnode(int item)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    new->value = item;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

int color(int count,struct Node* node)
{
    char color_str[8];
    printf("Enter The Color Of Resistor of band %d in Lowercase :",count);
    scanf("%s",color_str);
    node=trav(node,color_str);
    return node->key;
};

void clear()
{
  struct node * temp=head;
  while(head!=NULL)
    {
      temp=head;
      head=head->next;
      free(temp);
    }
}

long long int calculate(int band)
{
  struct node *temp = head;
    int j = 0;
   while (temp->next!=NULL)
    {
        if (j < band-2)
            sum = (sum * 10) + (temp->value);
        else if (j == band-2)
        {
            int c = temp->value;
            sum = sum * (pow(10, (c)));
        }
        temp = temp->next;
        
        j++;
    }
  printf("%lld +- %d%%\n", sum, temp->value);
  return sum;
}

void resistance_value(int l,int m,struct Node* node)
{
  //l to perform series or parallel 
  //m to print output only after taking all the resistors values
  int band = 0;
    while (!(band >= 4 && band <= 5))
    {
        printf("Please Enter The Bands In Resistor : ");
        scanf("%d", &band);
    }
    int count = band;
    while (count != 0)
    {
        int color_value = color(band-count+1,node);
        newnode(color_value);
        count--;
    }
    struct node *temp = head;
    int j = 0;
    long long int sum = 0;
    while (temp->next!=NULL)
    {
        if (j < band-2)
            sum = (sum * 10) + (temp->value);
        else if (j == band-2)
        {
            int c = temp->value;
            sum = sum * (pow(10, (c)));
        }
        temp = temp->next;
        
        j++;
    }
  printf("%lld +- %d%%\n", sum, temp->value);
  // series and parallel
  if(l==2)
  {
  net+=sum; 
    if(m==1)
      printf("\nThe Value Of Resisotrs In Series is : %lf\n",net);
    }
  if(l==3)
  {
  if(net==(double)(0))
  {
    net=sum;
  }
    else
  {
    net=(net*sum)/(net+sum);
    printf("\nThe Value Of Resisotrs In parallel is :%lf\n",net);
  }
  }
    clear();
};


  

int main()
{
struct Node* root = NULL;
root = insert(root,"grey",8);
root = insert(root,"blue",6);
root = insert(root,"black",0);
root = insert(root,"gold",5);
root = insert(root,"brown",1);
root = insert(root,"green",5);
root = insert(root,"silver",10);
root = insert(root,"red",2);    
root =  insert(root,"orange",3);
root=  insert(root,"violet",7);
root = insert(root,"yellow",4);
root = insert(root,"white",9);

  
  int k;
  
  while(k!=4)
    {
      printf("Please Choose One From The following :\n1.Resistor Color Code Calculator\n2.Calculate resistances In Series\n3.Calculate resistances In Parallel\n4.End\n");
  scanf("%d",&k);
      if(k==1)
      {
        resistance_value(k,0,root);
      }
      else if (k==2 || k==3)
      {
        resistance_value(k,0,root);
        resistance_value(k,1,root);
        }
      else if(k==4)
      {
        break;
      }
      else{
        printf("Please Enter A Valid Color");
      }
    }
    return 0;
}