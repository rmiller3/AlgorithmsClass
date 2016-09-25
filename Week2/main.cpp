#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

int ConfigurePivot(std::vector<int> v, int startIdx, int endIdx)
{
    return startIdx;
}

void DumpArray(std::vector<int>& v, std::string strLog = "")
{
    cout<<strLog<<":";
    for (int i=0; i<v.size();i++)
    {
        cout<<v[i] << " ";
    }
}

void Swap(std::vector<int>& v, int start, int end)
{
    int tmp = v[start];
    v[start] = v[end];
    v[end] = tmp;
}

void QuickSort(std::vector<int>& v, int start, int end)
{
 //   sleep(4);
//    cout<<"\nStart: "<<start<<" End: "<<end<<" ";
    
    if (end-start <= 1)
    {
        if (v[end] < v[start] && end-start > 0)
        {
            Swap(v, start, end);
//            DumpArray(v, "Swap!");
        }
        return;
    }

    int pivotIdx = ConfigurePivot(v, start, end);
//    cout<<"Pivot: "<<pivotIdx<<":"<<v[pivotIdx]<<" ";
    int overUnderIdx = pivotIdx+1;
//    cout<<"OUIdx: "<<overUnderIdx<<" ";
    for (int i=start + 1; i<=end; i++)
    {
//        cout<<"checking..."<<v[i]<<" ";
        if(v[i] < v[pivotIdx])
        {
//            cout<<"Swap "<<v[overUnderIdx]<<" "<<v[i]<<" ";
            Swap(v, overUnderIdx, i);
//            DumpArray(v, "After Swap");
            overUnderIdx++;
//            cout<<"OUIdx: "<<overUnderIdx<<" ";
        }
//        else
//            cout<<"No swap "<<v[i]<<" ";
    }
    
    if (v[pivotIdx] > v[overUnderIdx-1])
    {
//        cout<<"SwapPivot "<<v[pivotIdx]<<" "<<v[overUnderIdx-1]<<" ";
        Swap(v, pivotIdx, overUnderIdx-1);
    }
    else
    {
//        cout<<"NoSwap "<<v[pivotIdx]<<" OU "<<v[overUnderIdx-1]<<" ";
        start++;
    }
//    DumpArray(v, "After Loop");
    
    QuickSort(v, start, overUnderIdx-1);
//    cout<<"\nRight";
    QuickSort(v, overUnderIdx, end);
}

void GetInputSupport(std::vector<int>& input)
{
    ifstream inData;
    inData.open("Support.txt");
    while (!inData.eof())
    {
        int x = 0;
        inData >> x;
        input.push_back(x);
    }
    inData.close();
}

void GetInputSmall(std::vector<int>& input)
{
    //input = {4,2,3,1};
    input = {1,3,4,6,2,5,10,8,9,7}; 
}


int main()
{
    std::vector<int> v;
    GetInputSupport(v);
    //GetInputSmall(v);
//    DumpArray(v, "Start");
 
    QuickSort(v, 0, v.size()-1);
    sleep(4);
    DumpArray(v, "\nFinal");
    
    for (int i=1; i<v.size(); i++)
    {
        if (v[i] < v[i-1])
            cout<<"ERROR!";
    }
   
   return 0;
}
