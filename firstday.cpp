#include <iostream>
#include <fstream>
#include<vector>

int solveDay1(){
    std::ifstream input ("input");
    int value;
    int sum=0;
    int count=0;
    int prev;
    std::vector<int>inhale; 
    std::vector<int>temp;
    while (input >> value) {
        inhale.push_back(value);
    }
    for(int i=0;i<inhale.size();i++)
    {
        if((i+1)%3)
        {
            if(sum>prev)
                count++;
                prev=sum;
            temp.erase(temp.begin());
        }
        temp.push_back(inhale[i]);

            
    }
    return count;
}
int main(){
    std::cout<<solveDay1()<<"\n";
    return 0;

}