#include <stdio.h>
#include<stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------

struct bookdet
{
    char name[50];
    char auth[100];
    int lang;
    char review[100][100];
    int tag[10];
    int price;
    int index;
    int pa;
    float rating;
};

//----------------------------------------------------------------------------

void bill(struct bookdet temp[50],int c,int bl[100]);

void review(int r,struct bookdet s[] );

void sort(int a,int n,struct bookdet bok[n]);

void display(int n,int gcount,int g[gcount],struct bookdet x[n],struct bookdet y[n],int l);

//----------------------------------------------------------------------------
/*
1. Biography and autobiography
2. Fiction and Science fiction
3. Inspirational and Self-Help
4. Classics
5. Thrillers and horror
6. Mystery
7. Young Adults
*/

int main()
{
    struct bookdet book[100],filtered_books[50];
    int gcount=0,bookcount,choice,flag=1,n=3,language;
    book[0]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};
    book[1]=(struct bookdet){"Pride and Prejudice\0","Jane Austen\0",1,{"Good book must buy.","\0"},{4,2},60,1,432,4.2};
    book[2]=(struct bookdet){"The book thief\0","Markus Zusak\0",1,{"Good book must buy.","\0"},{2,7},80,1,564,4.4};
    /*book[3]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};
    book[4]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};
    book[5]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};
    book[6]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};
    book[7]=(struct bookdet){"11/22/63\0","Stephen King\0",1,{"Good book must buy.","\0"},{2,6},100,1,1849,4.3};*/
    do{
            system("cls");
            fflush(stdin);
            printf("Welcome to JIIT Bookstore \n");
            printf("\n--------------------------------------\n\n");
            printf("Would you like to\n 1.Purchase a book\n 2.Review a book\n 3.Exit\nEnter choice :");
            scanf("%d",&choice);
            fflush(stdin);
            system("cls");
            switch(choice)
            {
                case 1:{
                    printf("Enter the language (1 for English or 2 for Hindi): ");
                    scanf("%d",&language);
                    printf("\n--------------------------------------\n\n");
                    printf("Here is a few genres to choose from, select any apt genre :\n");
                    printf("For Genre:\n Press [1] for Biography and autobiography \n Press [2] for Fiction and Science fiction \n Press [3] for Inspirational and Self-Help \n Press [4] for Classics \n Press [5] for Thrillers and horror \n Press [6] for Mystery \n Press [7] for Young Adults\n \n");
                    printf("How many genres would you like : ");
                    scanf("%d",&gcount);
                    int genres[gcount];
                    printf("Enter the genres one by one :\n");
                    for (int i=0;i<gcount;i++)
                    {
                        scanf("%d",&genres[i]);
                    }
                    system("cls");
                    display(n,gcount,genres,book,filtered_books,language);
                    printf("\n\nHow many books would you like to purchase:");
                    scanf("%d",&bookcount);
                    int bookno[bookcount];
                    printf("\nEnter the book numbers on by one:\n ");
                    for (int i=0;i<bookcount;i++)
                    {
                        scanf("%d",&bookno[i]);
                    }
                    system("cls");
                    fflush(stdin);
                    bill(filtered_books,bookcount,bookno);
                    break;}
                case 2:{
                    review(n,book);
                    break;}
                case 3:{
                    flag=0;
                    break;}
                default:
                    printf("Sorry wrong input, restarted...\n");}


            }while(flag);
            printf("Ending...Bye");
            return 0;
            }
//----------------------------------------------------------------------------
void bill(struct bookdet temp[50],int c,int bl[100])//n- number of books purchased
{
    int t=0;
    printf("\n\t\tJIIT Bookstore");
    printf("\n-----------------------------------------------------------\n");
    printf("Book Name\t Author Name\t No. of Pages\t Rating\t Cost\t");
    printf("\n------------------------------------------------------------");

    for(int i=0;i<c;i++)
        {
            printf("\n %s\t  %s\t  %d\t  %f\t  %d\n",temp[bl[i]].name,temp[bl[i]].auth,temp[bl[i]].pa,temp[bl[i]].rating,temp[bl[i]].price);
            t=t+temp[bl[i]].price;
        }
        printf("\t\t\t\t\t\t\t Total:%d",t);
        printf("\nEnter any key to continue");
        scanf("%c");
}

void review(int r,struct bookdet s[] )
{
    char a[100];
    printf("enter the name of book for review");
    scanf("%s",&a);
    fflush(stdin);
    int p=r+1,x;
    for(int i=0;i<r;i++){
        int k=strcmp(a,s[i].name);
        if(k==0)
            {
            p=i;
            break;
            }
       }
    if(p==(r+1)){
        printf("Book doesn't exist in database returned to home\n");
        return;
    }
    else {
        printf("What would the rate the book(out of 5): ");
        scanf("%d",&x);
        fflush(stdin);
        s[p].rating=(s[p].rating*s[p].index+x)/(s[p].index+1);
        printf("Enter your review");
        gets(s[p].review[s[p].index]);
        s[p].index+=1;
        }
}

void sort(int a,int n,struct bookdet bok[n])
{
    int x;
    struct bookdet bk;
    if(a==0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(bok[j].price>bok[j+1].price)
                {
                bk=bok[j+1];
                bok[j+1]=bok[j];
                bok[j]=bk;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(bok[j].rating>bok[j+1].rating)
                {
                bk=bok[j+1];
                bok[j+1]=bok[j];
                bok[j]=bk;
                }
            }
        }
    }
}
void display(int n,int gcount,int g[gcount],struct bookdet x[n],struct bookdet y[n],int l){
    int a,yindex=0,match=0,t=0;
    printf("Sort by :\n 1 for price\n 2 for review\nEnter choice: ");
    scanf("%d",&a);
    a--;
    sort(a,n,x);
    system("cls");
    for (int xindex=0;xindex<n;xindex++){
        int j=0;
        while (x[xindex].tag[j]!=0){
            for(int abc=0;abc<gcount;abc++){
                if (x[xindex].tag[j]==g[abc])
                    match++;
            }
        if (match==gcount&&l==x[xindex].lang){
            if (t==0)
            {
                printf("S.No.\tBook details\n");
                t++;
            }
            match=0;
            printf("%d.\t%s (Pages-%d)   -%s\tRs. %d\n\tRated: %f\n\tReviews:",yindex,x[xindex].name,x[xindex].pa,x[xindex].auth,x[xindex].price,x[xindex].rating);
            printf("%s\n",x[xindex].review[0]);
            printf("\t\t%s\n",x[xindex].review[1]);
            printf("\t\t%s\n",x[xindex].review[2]);
            y[yindex++]=x[xindex];
            printf("\n");
        }
        j++;
        }
    }
}