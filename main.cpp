#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

//#define LOG

static int operationCount = 0;
static int PivotPicker =0;

void Log(const char* str)
{
#ifdef LOG
    cout<<str;
#endif
}

void Swap(std::vector<int>& v, int start, int end)
{
    int tmp = v[start];
    v[start] = v[end];
    v[end] = tmp;
}

int ConfigurePivotStart(std::vector<int>& v, int startIdx, int endIdx)
{
    return startIdx;
}

int ConfigurePivotEnd(std::vector<int>& v, int startIdx, int endIdx)
{
    Swap(v, startIdx, endIdx);
    return startIdx;
}

int ConfigurePivotMedian(std::vector<int>& v, int startIdx, int endIdx)
{
    Swap(v, (endIdx-startIdx)/2+startIdx, startIdx);
    return startIdx;
}

void DumpArray(std::vector<int>& v, std::string strLog = "")
{
    std::ostringstream ss;
    ss<<strLog<<":";
    for (int i=0; i<v.size();i++)
    {
        ss<<v[i]<<" ";
    }
    Log(ss.str().c_str());
}

void QuickSort(std::vector<int>& v, int start, int end)
{
#ifdef LOG
    sleep(4);
#endif
    std::ostringstream ss;
    ss << "\nStart: " << start << " End: " << end <<" ";
    Log(ss.str().c_str());
    
    if (end-start <= 1)
    {
        if (v[end] < v[start] && end-start > 0)
        {
            Swap(v, start, end);
//            DumpArray(v, "Swap!");
        }
        return;
    }
    
    int pivotIdx =0;

    switch (PivotPicker)
    {
        case 0:
            pivotIdx = ConfigurePivotStart(v, start, end);
            break;
        case 1:
            pivotIdx = ConfigurePivotEnd(v, start, end);
            break;    
        case 2:
            pivotIdx = ConfigurePivotMedian(v, start, end);
            break;
    }
    ss.str("");
    ss.clear(); // Clear state flags.
    ss<<"Pivot: "<<pivotIdx<<":"<<v[pivotIdx]<<" ";
    Log(ss.str().c_str());
    int overUnderIdx = pivotIdx+1;
    ss.str("");
    ss.clear(); // Clear state flags.
    DumpArray(v, "\nAfterPivotSwap");
    ss<<"OUIdx: "<<overUnderIdx<<" ";
    Log(ss.str().c_str());
    ss.str("");
    ss.clear(); // Clear state flags.
    
    for (int i=start + 1; i<=end; i++)
    {
        ss<<"checking..."<<v[i]<<" ";
        Log(ss.str().c_str());
        ss.str("");
        ss.clear(); // Clear state flags.
    
        if(v[i] < v[pivotIdx])
        {
            ss<<"Swap "<<v[overUnderIdx]<<" "<<v[i]<<" ";
            Swap(v, overUnderIdx, i);
            Log(ss.str().c_str());
            ss.str("");
            ss.clear(); // Clear state flags.
    
            
            DumpArray(v, "After Swap");
            overUnderIdx++;
            
            ss.str("");
            ss.clear(); // Clear state flags.
    
            ss<<"OUIdx: "<<overUnderIdx<<" ";
            Log(ss.str().c_str());
        }
        else
        {
            ss.str("");
            ss.clear(); // Clear state flags.
            ss << "No swap "<<v[i]<<" ";
            Log(ss.str().c_str());
        }
    }
    
    if (v[pivotIdx] > v[overUnderIdx-1])
    {
        ss.str("");
        ss.clear(); // Clear state flags.
        ss<<"SwapPivot "<<v[pivotIdx]<<" "<<v[overUnderIdx-1]<<" ";
        Log(ss.str().c_str());
        Swap(v, pivotIdx, overUnderIdx-1);
    }
    else
    {
        ss.str("");
        ss.clear(); // Clear state flags.
        ss<<"NoSwap "<<v[pivotIdx]<<" OU "<<v[overUnderIdx-1]<<" ";
        Log(ss.str().c_str());
        start++;
    }
    DumpArray(v, "After Loop");
    
    operationCount += overUnderIdx-2-start;
    QuickSort(v, start, overUnderIdx-2);
    Log("\nRight");
    operationCount += end-overUnderIdx-1;
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

void Run(int i)
{
    operationCount=0;
    PivotPicker = i;
    std::vector<int> v;
  GetInputSupport(v);
//    GetInputSmall(v);
    DumpArray(v, "Start");
    QuickSort(v, 0, v.size()-1);
    DumpArray(v, "\nFinal");
    
    for (int i=0; i<v.size()-1; i++)
    {
        if (v[i] >= v[i+1])
        {
            cout<<"\nERROR\n";
            break;
        }
    }
    cout<<"\nOpCount: "<< operationCount<<"\n";
}

int main()
{
//    for (int i=0; i<3; i++)
  //      Run(i);

    Run(2);
   
   return 0;
}