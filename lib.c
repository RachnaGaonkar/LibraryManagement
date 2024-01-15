#include<stdio.h>
#include<stdlib.h>

struct books{
    int id;
    char bookname[50];
    char authorname[50];
    char date[12];
}b;

FILE *fp;
//function
void addbook(){
    fp =fopen("book.txt","ab"); //create a file name book.txt to store books ; ab is used of open a binary file in apend mode
    printf("enter book id: ");
    scanf("%d",&b.id);

    printf("enter book name: ");
    fflush(stdin);
    gets(b.bookname);

    printf("enter aurthor name: ");
    fflush(stdin);
    gets(b.authorname);

    printf("\nbook added sucessfully...");
    fwrite(&b, sizeof(b), 1,fp); //1st reference of structure, 2nd size of structure b, 3rd one record is inserted at a time ,4th  with the help of fp pointer  
    fclose(fp);
}

//function
void viewbooklist(){
    
    printf("<==Available books==>\n\n");
    printf("%-10s %-30s %-20s\n\n","Book id","Book Name","aurthor");

    fp=fopen("book.txt","rb"); // rb is used for open a file to read in binary mode

    while(fread(&b,sizeof(b),1,fp)==1)
    {
        printf("%-10d %-30s %-20s\n\n",b.id,b.bookname,b.authorname);   
    }
    fclose(fp);
}
//function
void removebook(){
    int id,f=0;
    printf("<==Remove Book==>\n\n");
    printf("enter id to remove book.\n");
    scanf("%d",&id);

    FILE *ft;
    fp=fopen("book.txt","rb"); //rb read in binary mode
    ft=fopen("temp.txt","wb"); //wb write in binary mode

    while(fread(&b,sizeof(b),1,fp)==1)
    {
        if(id == b.id)
        {
            f=1;
        }
        else
        {
            fwrite(&b,sizeof(b),1,ft);
        }
    }
    if(f==1)
    {

        printf("\n\nbook deleted successfully");
    }
    else
    {
        printf("\n\nNo Book Found!");
    }
    fclose(fp);
    fclose(ft);
    remove("book.txt");
    rename("temp.txt","book.txt");
}

int main()
{
    int ch;
    while(1)
    {
        printf("<== library Management system==>\n");
        printf("1:Add book\n");
        printf("2:View book list\n");
        printf("3:Remove book\n");
        printf("0:exit\n\n");
        printf("enter your choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 0:
                exit(0);
            case 1:
                addbook();
                break;
            case 2:
                viewbooklist();
                break;
            case 3:
                removebook();
                break;
            default:
                printf("invalid choice...\n\n");
        }

        printf("\npress any key to continue ...\n\n");
        getch();
    }
    
    return 0;
}

