#include <iostream>
#include <string.h>
#define SIZE 11
using namespace std;

struct Client_data
{
    string name;
    long phone;
};

class Hash_Class
{
    private: 
    Client_data Hash_Table[SIZE];
    public:
    Hash_Class()
    {
        for(int i=0;i<SIZE;i++)
        {
            Hash_Table[i].phone = -1;
            Hash_Table[i].name = "NULL";
        }
    }

    int Calculate_Hash(string name)
    {
        int i = 0;
        int sum = 0;
        while(name[i] != '\0')
        {
            sum += name[i];
            i++;
        }
        return sum%SIZE;
    }

    int insert(string name,long phone)
    {
        int hash = Calculate_Hash(name);
        int placed_index = -1;
        for(int i=0;i<SIZE;i++)
        {
            if(Hash_Table[(hash+i)%SIZE].phone == -1)
            {
                Hash_Table[(hash+i)%SIZE].name = name;
                Hash_Table[(hash+i)%SIZE].phone = phone;
                placed_index = (hash+i)%SIZE;
                break;
            }
        }
        return placed_index;
    }

    void insert()
    {
        Client_data temp;
        int n,place;
        cout<<"Enter the no of clients to insert : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter client name : ";
            cin>>temp.name;
            cout<<"Enter client phone : ";
            cin>>temp.phone;
            place = insert(temp.name,temp.phone);
            if(place == -1)
            {
                cout<<"Table overflow. Not inserted";
            }
            else
            {
                cout<<"Inserted record on index :"<<place<<endl;
            }
        }
    }

    void search()
    {
        string name;
        cout<<"Enter name to search : ";
        cin>>name;
        int hash = Calculate_Hash(name);
        int found = -1;
        for(int i=0;i<SIZE;i++)
        {
            if(Hash_Table[(hash+i)%SIZE].name == name)
            {
                found = (hash+i)%SIZE;
                break;
            }
        }
        if(found==-1)
        {
            cout<<"Client details not found"<<endl;
        }
        else
        {
            cout<<Hash_Table[found].name << " : " << Hash_Table[found].phone<<endl;
        }
    }

    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<"\t"<<Hash_Table[i].name<<" : \t"<<Hash_Table[i].phone<<endl;
        }
    }

};

int main()
{
    Hash_Class obj;
    obj.insert();
    obj.display();
    obj.search();

    return 0;
}
