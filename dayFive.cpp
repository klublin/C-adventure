#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include<string.h>


void maker(const std::string& line,std::vector<int>&bingo)
{
    int i=0;
    while(i<line.size())
    {
        int temp=0;
        bool yes=false;
        while(line[i]<=57&&48<=line[i]&&i<line.size())
        {
            yes=true;
            temp*=10;
            temp+=std::stoi(line.substr(i,1));
            i++;
        }
        if(yes)
        {
            yes=false;
            bingo.push_back(temp);
        }   
        i++;
        
    }
}
int value(int num,const std::vector<bool>&check,const std::vector<int>&card)
{
    int sum=0;
    for(int i=0;i<check.size();i++)
    {
        if(!check[i])
            sum+=card[i];
    }
    return num*sum;
}
bool bingo(const std::vector<bool>&vec)
{
    for(int i=0;i<5;i++)
    {
        int counter=0;
        for(int j=0;j<5;j++)
        {
            if(vec[i*5+j]==true)
                counter++;
            else
                counter=0;
        }
        if(counter==5)
            return true;
    }
    for(int i=0;i<5;i++)
    {
        int counter=0;
        for(int j=0;j<5;j++)
        {
            if(vec[i+j*5]==true)
                counter++;
            else
                counter=0;
        }
        if(counter==5)
            return true;
    }
    return false;
}
std::pair<int,int> check(const std::vector<int>&card,const std::vector<int>&bingoNum)
{
    int counter=0;
    std::vector<bool>check;
    for(int i=0;i<card.size();i++)
    {
        check.push_back(false);
    }
    for(int num:bingoNum)
    {
        auto it=std::find(card.begin(),card.end(),num);
        if(it!=card.end())
        {
            int index=it-card.begin();
            check[index]=true;
            if(bingo(check))
                return {counter,value(num,check,card)};
        }
        counter++;
    }
    return {-1,0};
}
void foura()
{
    std::ifstream myfile ("input");
    std::string line;
    std::vector<int>bingoNum;
    std::vector<int>bingoCard;
    std::getline(myfile,line);
    std::pair<int,int> pairy{-1,0};
    maker(line,bingoNum);
    int counter=0;
    while(myfile)
    {
        std::getline(myfile,line);
        if(line.empty())
            continue;
        else
        {   
            maker(line,bingoCard);
            counter++;
        }
        if(counter==5)
        {
            std::pair<int,int>temp=check(bingoCard,bingoNum);
            if(pairy.first<temp.first)
                pairy=temp;
            bingoCard.clear();
            counter=0;
        }
    }
    std::cout<<pairy.second<<"\n";
}
int main()
{
    foura();
    return 0;
}