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

std::map vertexRemap; // when vertices get mapped, this shows where they are mapped to.

void RemoveInnerLoops(std::vector<int>& adjacencyList, int vertex)
{
    for(int i=0; i<adjacencyList.size();i++)
    {
        if ()
    }
}


void MergeVertices(const std::vector<std::vector<int>> input)
{
    std::vector<std::vector<int>> working = input;
    
    int vertex1 = rand() % working.size();
    int vertex2 = rand() % working[vertex1].size(); //get the index
    vertex2 = working[vertex1][vertex2];  //index to v2.
    
    for (int i=0; i<working[vertex2].size(); i++)
    {
        working[vertex1].push_back(working[vertex2][i]);  // copy the edge from v2 to v1, since v2 will be deleted.
        working.erase[vertex2];
        vertexRemap.insert(std::pair(vertex2, vertex1));
    }
    
    RemoveInnerLoops(vertex1);
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
