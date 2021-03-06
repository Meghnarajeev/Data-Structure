#include<stdio.h>
#include<alloc.h>
struct TreeNode
{
   struct TreeNode *lchild;
   int data;
   struct TreeNode *rchild;
};
typedef struct TreeNode TreeNode;
TreeNode *getnode();
main()
{
   TreeNode *root;
   root=NULL;
   TreeCreate(&root, 6);
   TreeCreate(&root, 4);
   TreeCreate(&root, 8);
   TreeCreate(&root, 3);
   TreeCreate(&root, 7);
   TreeCreate(&root, 5);
   TreeCreate(&root, 9);
   clrscr();
   TreeDisplay(root, 1);
   getch();
}

TreeCreate(TreeNode **rt, int item)
{
   TreeNode *current=(*rt), *temp;
   if((*rt)==NULL)
   {
      (*rt)=getnode();
      (*rt)->data=item;
      (*rt)->lchild=NULL;
      (*rt)->rchild=NULL;
      return;
   }
   while(current!=NULL)
   {
   if(item<current->data)
   {
      if(current->lchild!=NULL)
      current=current->lchild;
      else
      {
	 temp=getnode();
	 current->lchild=temp;
	 temp->data=item;
	 temp->lchild=NULL;
	 temp->rchild=NULL;
	 return;
      }
   }
   else
   {
      if(item>current->data)
      {
	 if(current->rchild!=NULL)
	    current=current->rchild;
	 else
	 {
	    temp=getnode();
	    current->rchild=temp;
	    temp->data=item;
	    temp->rchild=NULL;
	    temp->lchild=NULL;
	    return;
	 }
      }
      else
      {
	 printf("\nWrong Data");
	 exit(0);
      }
   }
}
}

TreeDisplay(TreeNode *rt, int level)
{
   int i;
   if((rt)!=NULL)
   {TreeDisplay((rt)->rchild, level+1);
   printf("\n");
   for(i=0; i<level; i++)
       printf("     ");
   printf("%d", (rt)->data);
   TreeDisplay((rt)->lchild, level + 1);
   }
}

TreeNode *getnode()
{TreeNode *t;
t=(TreeNode *)malloc(sizeof(TreeNode));
}
