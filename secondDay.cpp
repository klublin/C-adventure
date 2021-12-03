#include <iostream>
#include <fstream>
#include<vector>

int solveDay2()
{
    std::ifstream input ("input");
    std::string command;
    int step;
    int horizontal=0;
    int depth=0;
    while(input>>command>>step){
        if(command=="forward")
        {
            horizontal+=step;
        }
        else if(command=="down")
        {
            depth+=step;
        }
        else
            depth=depth-step;
    }
    return depth*horizontal;
}
int solveDay2b()
{
    std::ifstream input("input");
    std::string command;
    int step;
    int horizontal=0;
    int depth=0;
    int aim=0;
    while(input>>command>>step)
    {
        if(command=="forward")
        {
            horizontal+=step;
            depth+=aim*step;
        }
        else if(command=="down")
        {
            aim+=step;
        }
        else
            aim=aim-step;
    }
    return depth*horizontal;
}
int main(){
    std::cout<<solveDay2b()<<"\n";
    return 0;
    
    
}