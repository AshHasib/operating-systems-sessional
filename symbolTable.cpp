#include<bits/stdc++.h>
using namespace std;
#define LENGTH 51
#define MAX 128


class symbol_info
{
public:
    char *name;
    char *type;
    symbol_info *next;
} *block[LENGTH];


int hashFunc(char *name)
{
    int sum=0;

    if(strlen(name)==1)
    {
        return ((name[0]*name[0])%LENGTH);
    }
    else
    {
        return (((name[0]* name[0])+(name[strlen(name)-1]* name[strlen(name)-1]))%LENGTH);
    }
}

/*
int hashFunc(char *name)
{
    int id=0;
    for(int i=0;name[i];i++)
    {
        id+=name[i];
    }
    return (id%LENGTH);
}
*/
class SymbolTable
{
public:
    void Insert(char *name, char *type)
    {
        int pos=hashFunc(name);

        if(block[pos]==NULL)
        {
            block[pos]=new symbol_info();
            block[pos]->name=name;
            block[pos]->type=type;
            block[pos]->next=NULL;
        }
        else
        {
            symbol_info *newNode=new symbol_info();
            newNode->name=name;
            newNode->type=type;

            symbol_info *nextNode=block[pos];
            block[pos]=newNode;
            newNode->next=nextNode;
        }
        printf("Insertion Successful . . . . \n");
    }

    void Search(char *name, char *type)
    {
        int pos=hashFunc(name);

        symbol_info * temp=block[pos];

        while(temp!=NULL)
        {
            if(!strcmp(temp->name,name) && !strcmp( temp->type,type))
            {
                printf("Data Found\n");
                return;
            }
            temp=temp->next;
        }
        printf("Data Not Found\n");
        return;
    }

    void Delete(char *name, char *type)
    {
        int pos=hashFunc(name);

        symbol_info *temp = block[pos];

        if(temp==NULL)
        {
            printf("Deletion Unsuccessful . . . . \n");
            return ;
        }

        if(temp->next == NULL && !strcmp(temp->name, name) && !strcmp(temp->type,type))
        {
            block[pos]=NULL;
            printf("Deletion Successful . . . . \n");
            return ;
        }

        else if(!strcmp(temp->name, name) && !strcmp(temp->type,type))
        {
            block[pos]=temp->next;
            printf("Deletion Successful . . . . .\n");
            return ;
        }
        else
        {
            while(temp->next!=NULL)
            {
                if(!strcmp(temp->next->name,name) && !strcmp(temp->next->type,type))
                {
                    break;
                }
                temp=temp->next;
            }

            if(temp!=NULL)
            {
                symbol_info *found=temp->next;
                temp->next=found->next;
                delete(found);
                printf("Deletion Successful. . . \n");
                return;
            }
        }
        printf("Deletion Unsuccessful . . . . . \n");
    }

    void Update(char *name, char *type, char *newType)
    {
        int pos=hashFunc(name);

        symbol_info *temp=block[pos];

        while(temp!=NULL)
        {
            if(!strcmp(temp->name,name) && !strcmp(temp->type, type))
            {
                temp->type=newType;
                printf("Update Successful . . . . \n");
                return ;
            }
            temp=temp->next;
        }
        printf("Update Unsuccessful . . . . \n");
    }

    void Display()
    {
        for(int i=0;i<LENGTH;i++)
        {
            printf("%d : ",i);
            printf(" - > ");
            symbol_info *temp=block[i];

            while(temp!=NULL)
            {
                printf(" [%s | %s] , ",temp->name,temp->type);
                temp=temp->next;
            }

            printf("\n");
        }
    }
};

int main()
{
    SymbolTable myTable;

    /*
    myTable.Insert("id" , "int");
    myTable.Insert("ch" , "char");
    myTable.Insert("60" , "number");
    myTable.Insert("float" , "rate");
    printf("\n");
    myTable.Display();
    printf("\n");
    myTable.Delete("60" , "number");
    myTable.Delete("40" , "number");
    printf("\n");
    myTable.Search("id", "int");
    myTable.Search("a", "int");
    printf("\n");
    myTable.Display();

    */

    myTable.Insert("abc","int");
    myTable.Display();


    return 0;
}
