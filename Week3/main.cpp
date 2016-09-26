#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

//#define LOG

static int minCut = 0;

void Log(const char* str)
{
#ifdef LOG
    cout<<str;
#endif
}

void GetInputSupport(std::vector<std::vector<int>>& input)
{
    ifstream inData;
    inData.open("Support.txt");
    std::string line;
    
    while (std::getline(inData, line))
    {
        std::istringstream iss(line);
        int i;

        { // scope innerV so it's not accidentally used later, a copy is stored in input vector
            std::vector<int> innerV;
            input.push_back(innerV);
        }
        
        bool ignore = true; //ignore first character, it's the line number.
        while (iss >> i)
        {
            if (!ignore)
            {
                input[input.size()-1].push_back(i);
            }
                
            ignore = false;
        }
    }
    
    for (int i=0; i<input.size();i++)
    {
        for (int j=0; j<input[i].size();j++)
            cout<<input[i][j]<<" ";
        sleep(1);
        cout<<"\n";
    }
}

void GetInputSmall(std::vector<std::vector<int>>& input)
{
    input = {
        {3},
        {2,3},
        {1,3},
        {0,1,2},
        }; 
}

void Run(int i)
{
    std::vector<std::vector<int>> vertexConnections;
    GetInputSupport(vertexConnections);
//    GetInputSmall(v);
    
    cout<<"\nMincut: "<< minCut<<"\n";
}

int main()
{
    for (int i=0; i<1; i++)
       Run(i);

   return 0;
}