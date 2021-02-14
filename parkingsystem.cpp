#include <iostream>
#include <string>
#include<stdlib.h>
#include<fstream>
#define slots 10
enum typeofrecord{EMPTY,OCCUPIED,LEFT};
using namespace std;
struct car
{
    int carno;
    string carnumber;
};
struct parking
{
    struct car info;
    enum typeofrecord status;
};
void allot(struct car carec,struct parking table[]);
void emptyslot(struct  parking table[]);
void filledslot(struct car carec,struct parking table[]);
void findandempty(struct car carec,struct parking table[]);
int hash(int carno);
int main()
{
system("Color E4");
    struct parking table[slots];
    struct car carec;
    for(int i=0;i<slots;i++)
    {
        table[i].status=EMPTY;
    }
    int choice;
cout<<"Welcome to Advanced Car Parking Management System"<<endl;
while(1)
{
    cout<<"1.New car slot allocation"<<endl;
    cout<<"2.View slots allocated"<<endl;
    cout<<"3.View Empty slots"<<endl;
    cout<<"4.Find slot of parked car and mark that slot as left"<<endl;
    cout<<"5.Exit system"<<endl;
    cin>>choice;
    switch(choice)
    {
 case 1:
    {
        cout<<"Enter last two digits of your car's number plate"<<endl;
        cin>>carec.carno;
        cout<<"Enter car number of your car"<<endl;
        cin>>carec.carnumber;
        allot(carec,table);
        break;
    }
 case 2:
    {
        filledslot(carec,table);
        break;
    }
 case 3:
    {
        emptyslot(table);
            break;
    }
 case 4:
    {
        cout<<"Enter your car number"<<endl;
        cin>>carec.carnumber;
        findandempty(carec,table);
        break;

    }
 case 5:
    {
        exit(0);
    }
    }
}
    return 0;
}
void allot(struct car carec,struct parking table[])
{
    int location,h;
    struct parking info;
     h=hash(carec.carno);
     location=h;
    for(int i=0;i<slots;i++)
    {
        if(table[location].status==EMPTY||table[location].status==LEFT)
        {
            table[location].info=carec;
            table[location].status=OCCUPIED;
            cout<<"Slot allocated is: "<<location<<endl;
            return;
        }
    location=(h+i)%slots;
    }
    cout<<"Sorry No Space Left"<<endl;
}
void emptyslot(struct parking table[])
{
    int count=0;
    for(int i=0;i<slots;i++)
    {
        if(table[i].status==EMPTY|| table[i].status==LEFT)
        {
            count++;
        }
    }
    cout<<"Number of empty slots are: "<<count<<endl;
}
void filledslot(struct car carec,struct parking table[])
{
    int count=0;
    for(int i=0;i<slots;i++)
    {
        if(table[i].status==OCCUPIED)
        {
            cout<<"The occupied slots are: "<<i<<" "<<table[i].info.carnumber<<endl;
            count++;
        }
    }
        cout<<"Number of Occupied slots are: "<<count<<endl;

}
void findandempty(struct car carec,struct parking table[])
{
    for(int i=0;i<slots;i++)
    {
        if(table[i].info.carnumber==carec.carnumber)
        {
            cout<<"Your car is parked at slot number: "<<i<<endl;
            table[i].status=LEFT;
        }
    }
}

int hash(int carno)
{
    return (carno%slots);
}

