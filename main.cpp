#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

using namespace std;

int matrix = 222222222, userInp, compInp;
bool isGameOver = false, validInput = false;
vector<int> ans;
vector<int> Matrix;
vector<int> moves;

int randNum(int range)
{
    int r = 0;
    srand(time(0));
    r = rand() % range;
    return r;
}

void display()
{
    int dmatrix;
    dmatrix = matrix;
    for(int i = 0; i < 9; i++)
    {
        if(i%3==0)
            cout<<"\n |";
        cout<<" "<<dmatrix % 10<<" | ";
        dmatrix = dmatrix / 10;
    }
}

int getNumPos(int pos)
{
    int n;
    n = matrix;
    for(int i = 0; i < pos-1; i++)
    {
        n /= 10;
    }
    return(n%10);
}

void resetOptions(int num)
{
    int pos = 0;
    for(int i = 0; i < int(ans.size()); i++)
    {
        if(ans[i]==num)
            pos = i;
    }

    vector<int>::iterator it = ans.begin() + (pos);
    ans.erase(it);
}

void learn()
{

}

void userInput()
{
    while(!validInput)
    {
        cout<<"\n\nYour Turn-\nEnter the position to place your move(1-9):"<<endl;
        cin>>userInp;
        validInput = true;
        if(userInp > 9 || getNumPos(userInp)==0 || getNumPos(userInp)==1)
        {
           cout<<"Invalid Input!"<<endl;
           validInput = false;
        }
    }
    validInput = false;
}

void modifyMatrix(int pos,int value)
{
    for(int i = 0; i < pos-1; i++)
    {
        value *= 10;
    }
    matrix = matrix - value;
}

void computerInput()
{
    cout<<"\nComputer's Turn -\nComputer's move :"<<endl;
    compInp = ans[randNum(ans.size())];
    cout<<compInp<<endl;
    cout<<"\n";
}

void check()
{
    int p[9];

    for(int i = 0; i < 9; i++)
    {
        p[i] = getNumPos(i+1);
    }

    if( ( (p[0]==p[1]&&p[1]==p[2]) && (p[0]==1||p[0]==0) ) ||
        ( (p[3]==p[4]&&p[4]==p[5]) && (p[3]==1||p[3]==0) ) ||
        ( (p[6]==p[7]&&p[7]==p[8]) && (p[6]==1||p[6]==0) ) ||
        ( (p[0]==p[3]&&p[3]==p[6]) && (p[0]==1||p[0]==0) ) ||
        ( (p[1]==p[4]&&p[4]==p[7]) && (p[1]==1||p[1]==0) ) ||
        ( (p[2]==p[5]&&p[5]==p[8]) && (p[2]==1||p[2]==0) ) ||
        ( (p[0]==p[4]&&p[4]==p[8]) && (p[0]==1||p[0]==0) ) ||
        ( (p[2]==p[4]&&p[4]==p[6]) && (p[2]==1||p[2]==0) ) )
    {
        if(p[0]==1 || p[3]==1 || p[6]==1 || p[1]==1 || p[2]==1)
        {
            cout<<"You won\n\n\n";
            isGameOver = true;
            learn();
        }
        else
        {
            cout<<"Comp wins\n\n\n";
            isGameOver = true;
        }
    }
    else
        isGameOver = false;
}

int main()
{
    for(int k = 1; k < 10; k++)
    {
        ans.push_back(k);
    }

    while(!isGameOver)
    {
        system("cls");
        cout<<"\n\n";
        display();

        //user
        userInput();
        resetOptions(userInp);
        modifyMatrix(userInp,1);

        //computer
        computerInput();
        resetOptions(compInp);
        modifyMatrix(compInp,2);
        display();

        check();
        if(isGameOver)
        {
            getch();
            break;
        }

        cout<<"\n\nPress any key for next move"<<endl;
        getch();
    }

    return 0;
}
