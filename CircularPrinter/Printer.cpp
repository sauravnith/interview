#include<iostream>
#include <string>
#include<atomic>
#include<vector>
#include<thread>
#include<sched.h>

struct Options
{
    std::string mData;
    int mCharCount;
    int mThreadCount;
    int mPrintCount;
};

void getOptions(int argc, char* argv[], Options& arOptions)
{
    if(argc != 5)
    {
        throw std::runtime_error("Invalid arguments");
    }

    arOptions.mData = argv[1];
    arOptions.mCharCount = atoi(argv[2]);
    arOptions.mThreadCount = atoi(argv[3]);
    arOptions.mPrintCount = atoi(argv[4]);

    std::cout<<"ThreadCount "<< arOptions.mThreadCount<<std::endl;
}

int printChars(const std::string& arData, int arStartIndex, int arCharCount)
{
    const auto lSize = arData.size();

    std::cout<<"Thread "<<std::this_thread::get_id()<< ":";

    for(auto idx=0; idx<arCharCount; ++idx)
    {
        std::cout<<arData[arStartIndex];

        arStartIndex = (arStartIndex + 1) % lSize;
    }

    std::cout<<std::endl;

    return arStartIndex ;
}

void print(std::string& arData, int arCharCount, int arPrintCount , std::atomic<int>& arPrintIndex, int arStartIndex)
{
    std::cout<<"Thread "<<std::this_thread::get_id()<< ":" <<"StartIndex:"<<arStartIndex<<std::endl;

    while(arPrintCount)
    {
        while(arStartIndex  != arPrintIndex.load())
        {
            sched_yield();
        }

       arStartIndex = printChars(arData, arStartIndex, arCharCount);

       //update shared variable
       arPrintIndex.store(arStartIndex );

       //need to print last character again
       --arStartIndex;
       --arPrintCount;
    }
}

int main(int argc, char* argv[])
{
    Options lOptions;

    getOptions(argc,argv,lOptions);

    std::atomic<int> mPrintIndex{0};

    std::vector<std::thread> mThreadVctr;

    for(int idx = 0; idx< lOptions.mThreadCount; ++idx)
    {
        std::thread lThread(print, std::ref(lOptions.mData), lOptions.mCharCount,
                            lOptions.mPrintCount,std::ref(mPrintIndex), lOptions.mCharCount*idx );

        mThreadVctr.emplace_back(std::move(lThread));
    }

    for(auto& lThread : mThreadVctr)
    {
        lThread.join();
    }

}



