#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class stringName
{
private:
    string name;
public:
    stringName (){}
    stringName(string a)
    {
        name = a;
    }
    void SetName(string a)
    {
        name=a;
    }
    string printName()
    {
        int counter=0;
///first case if found 2 space:

        for(int i=0;i<name.size();i++)
        {
            if (name[i]==' ')
                counter++;
        }
        if (counter >= 2)
            return name;
///second case if found 1 space:
        else if(counter == 1)
        {
            stack<string>stk;
            stk.push("N");
            string str;
            for (int i=name.size()-1;i>=0;i--)
            {
                if (name[i]!=' ')
                    {stk.push(string(1,name[i]));}
                else if (name[i]==' ')
                    break;
            }
            while(stk.top()!="N")
            {
                str+=stk.top();
                stk.pop();
            }

            return name+' '+str;
        }
///third case if found 1 space:
        else if(counter == 0)
        {
            stack<string>stk;
            stk.push("N");
            string str;
            for (int i=name.size()-1;i>=0;i--)
            {
                    stk.push(string(1,name[i]));
            }
            while(stk.top()!="N")
            {
              str+=stk.top();
              stk.pop();
            }
            return name+' '+str+' '+str ;
        }

    }
///___________________________________________________________
void print(string newName)
{

    istringstream ss(newName);

    do {

        string word;
        ss >> word;


        cout << word << endl;

    } while (ss);
}
///___________________________________________________________
void Replace (string newName,int i,int j)
{

    vector<string>vec;
    istringstream ss(newName);

    do {

        string word;
        ss >> word;


        vec.push_back(word);

    } while (ss);

    if (j>vec.size())
    {
        cout <<"false";
    }
    else
    {
        swap(vec[i-1],vec[j-1]);
        for (vector<string>::iterator it = vec.begin() ; it != vec.end(); ++it)
        cout << ' ' << *it;
    }

}

};

int main()
{
    stringName a ;
    string input;
    cout << "Enter Name \n";
    getline(cin,input);
    a.SetName(input);
    int choice ;
    do
    {
        cout << " \n Welcome Ya User :) \n";
        cout << "1- Print Name \n2-Separate Name \n3-Replace \n4-Exit";
        cout << "Enter choice \n";

        cin >> choice;
        string static name;
        if (choice==1)
        {
           name = a.printName();
           cout<< name <<endl;
        }
        else if(choice==2)
        {
            a.print(name);
        }
        else if (choice==3)
        {
            int i,j;
            cout <<"Enter i and j \n";
            cin >>i >> j;
            a.Replace(name,i,j);
        }
        else if (choice==4)
        {
            break;
        }
    }
    while(choice!=4);




    return 0;
}
