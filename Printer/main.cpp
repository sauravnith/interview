#include<iostream>
#include<thread>
#include<atomic>
#include<stdlib.h>


void printZero(const std::string& arInput, std::atomic<int>& arReadIdx)
{
    auto lId{std::this_thread::get_id()};

    while(true)
    {
        auto lIdx = arReadIdx.load();

        if(lIdx >= arInput.size())
        {
            break;
        }

        auto lNum = arInput[lIdx] - '0';

        if(lNum == 0)
        {
            std::cout<<lId<<": "<<lNum<<std::endl;

            arReadIdx.store(lIdx +1);
        }
    }
    return;
}

void printEven(const std::string& arInput, std::atomic<int>& arReadIdx)
{
    auto lId{std::this_thread::get_id()};

    while(true)
    {
        auto lIdx = arReadIdx.load();

        if(lIdx >= arInput.size())
        {
            break;
        }

        auto lNum = arInput[lIdx] - '0';

        if(lNum!=0 && lNum % 2 == 0)
        {
            std::cout<<lId<<": "<<lNum<<std::endl;

            arReadIdx.store(lIdx +1);
        }
    }
}

void printOdd(const std::string& arInput, std::atomic<int>& arReadIdx)
{
    auto lId{std::this_thread::get_id()};

    while(true)
    {
        auto lIdx = arReadIdx.load();

        if(lIdx >= arInput.size())
        {
            break;
        }

        auto lNum = arInput[lIdx] - '0';

        if(lNum%2 != 0)
        {
            std::cout<<lId<<": "<<lNum<<std::endl;

            arReadIdx.store(lIdx +1);
        }
    }
}

int main()
{
    std::string lInput("01023040506");
    std::atomic<int> lReadIndex{0};

    std::thread lthread1(printZero, std::ref(lInput),std::ref(lReadIndex));
    std::thread lthread2(printEven, std::ref(lInput),std::ref(lReadIndex));
    std::thread lthread3(printOdd, std::ref(lInput),std::ref(lReadIndex));

    lthread1.join();
    lthread2.join();
    lthread3.join();
}


