#include <iostream>
using namespace std;
void create();
void show();
void write();
void display();
void admin();
void search();
void modify();
void del();
void menu();
   
   void product::create()
   {
    cout<<"\n\n Please Enter The Product No. of The Product";
    cout<<"\n\n Please Enter The Name No. of The Product";
    cout<<"\n\n Please Enter The Price of The Product";
    cout<<"\n\n Plese Enter The Discount(%)";
    cin>>dis;
   }
   void product::show()
   {
    cout<<"\nThe Product No. of The Product:"<<product;
    cout<<"\nThe Name of The Product :"<<name;
    cout<<"\nThe Price of The Product :"<<price;
    cout<<"\nDiscount:"<<dis<<%;
   }
   void product::write()
   {
    file.open("shop.txt",ios::out|ios::app);
    create();
    file<<" "<<pno<<" "<<name<<" "<<price<<" "<<discount<<" ";
    file.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();
   }
   void product::display()
   {
    system("cls");
    cout<<"\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        show();
        cout<<"\n\n=========================================";
        file>>pno>>name>>price>>dis>>;
    }
    file.close();
    getch();
   }
   void product::search(int n)
   {
    int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            system("cls");
            show();
            found=1;
        }
        file>>pno>>name>>price>>dis;
    }
    file.close();
    if(found == 0)
    cout<<"\n\nrecord not exit";
    getch();
   }
   void product::modify(int n)
   {
    int found=0;
    system("cls")
    cout<<"\n\n\tTo Modify";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out|ios::app);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            show();
            cout<<"\n\n Please Enter The New Detail";
            create();
            file<<" "pno<<" "<<name<<" "<<price<<dis<<" ";
            cout<<"\n\n\tRecord Updated";
            found=1;
        }
        else
        file<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<" ";
    }
    file.close();
    file1.close();
    remove("shop1..txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
   }
   void product::del(int n)
   {
    int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            cout<<"\n\n\t Record Deleted";
            found=1;
        }
        else
        file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<" ";
        file>>pno>>name>>price>>dis;
    }
    file.close();
    file1.close();
    remove("shop.txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
   }
   void product::menu()
   {
    system("cls");
    file.open("shop.txt",ios::in);
    cout<<"\n\n\t\tProduct MENU\n\n";
    cout<<"=======================================";
    cout<<"P.NO.\t\tNAME\t\tPRICE\n";
    cout<<"=======================================";
    file>>pno>>name>>price>>;
    while(!file.eof())
    {
        cout<<pno<<"\t\t"<<name<<"\t\t"<<price<<"\n\n"<<dis;
        file>>pno>>name>>price>>dis;
    }
    file.close();
   }

