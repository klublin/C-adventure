#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>



void print(const std::vector<std::string>& vec)
{
    std::cout<<"[";
    for(const std::string& s:vec)
    {
        std::cout<<s<<",";
    }
    std::cout<<"]"<<"\n";
}
int solveDay3a()
{
    int contains[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    std::string value;
    std::ifstream input("input");
    int gamma=0;
    int epislon=0;
    while(input>>value)
    {
        for(int i=0;i<value.length();i++)
        {
            if(value[i]=='1')
                contains[i]++;
        }
    }
    for(int i=0;i<value.length();i++)
    {
        gamma=2*gamma;
        epislon=2*epislon;
        if(contains[i]>=500)
            gamma+=1;
        else
            epislon+=1;
    }
    std::cout<<gamma<<"\n";
    std::cout<<epislon<<"\n";
    return gamma*epislon;
}
int solveDay3b(){
    std::string value;
    std::ifstream input("input");
    std::vector<std::string>carbon;
    std::vector<std::string>oxygen;
    while(input>>value)
    {
        carbon.push_back(value);
        oxygen.push_back(value);
    }
    //find carbon
    int index=0;
    int max=0;
    while(index<oxygen[0].size()&&carbon.size()!=1)
    {
        //std::cout<<"this is carbon size "<<carbon.size()<<"\n";
        for(int j=0;j<carbon.size();j++)
        {
            if(carbon[j][index]=='1')
                max++;
        }
        std::cout<<max<<" "<<(carbon.size()/2)<<"\n";
        if(max>=carbon.size()-max)
            carbon.erase(std::remove_if(carbon.begin(),carbon.end(),[index](const std::string& a) {
                return a[index]=='0';
             }),carbon.end());
        else 
            carbon.erase(std::remove_if(carbon.begin(),carbon.end(),[index](const std::string& a) {
                return a[index]=='1';
             }),carbon.end());
        print(carbon);
        max=0;
        index++;
    }
    std::cout<<"THIS IS CARBON SIZE "<<carbon.size()<<"\n";
    max=0;
    index=0;
    while(index<oxygen[0].size()&&oxygen.size()!=1)
    {
        for(int j=0;j<oxygen.size();j++)
        {
            if(oxygen[j][index]=='1')
                max++;
        }

        if(max>=oxygen.size()-max)
            oxygen.erase(std::remove_if(oxygen.begin(),oxygen.end(),[index](const std::string& a) {
                return a[index]=='1';
             }),oxygen.end());
        else 
            oxygen.erase(std::remove_if(oxygen.begin(),oxygen.end(),[index](const std::string& a) {
                return a[index]=='0';
             }),oxygen.end());
        max=0;
        index++;
        print(oxygen);
    } 
    std::cout<<"THIS IS oxygen SIZE "<<oxygen.size()<<"\n";
    int scrubber=0;
    int generator=0;
    std::cout<<carbon[0]<<"\n";
    for(int i=0;i<oxygen[0].size();i++)
    {
        scrubber*=2;
        generator*=2;
        if(oxygen[0][i]=='1')
            generator++;
        if(carbon[0][i]=='1')
            scrubber++;   
    }
    std::cout<<scrubber<<"\n";
    std::cout<<generator<<"\n";
    return scrubber*generator;
}
int main(){
    std::cout<<solveDay3b()<<"\n";
    return 0;
}