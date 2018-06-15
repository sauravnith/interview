#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class FormatStyle
{
public:
    enum class Style
    {
        INDIAN
    };

    FormatStyle(Style arStyle)
        :mStyle(arStyle)
    {}

    void addDelimPosition(int arPosition)
    {
        mDelimPosVctr.emplace_back(arPosition);
    }

    bool isDelimRequired(int arPos)
    {
        return std::find(mDelimPosVctr.begin(), mDelimPosVctr.end(),arPos) == mDelimPosVctr.end() ? false : true ;
    }
private:
    Style mStyle;
    std::vector<int> mDelimPosVctr;
};

std::string formatNum(FormatStyle arStyle , int arNum)
{
    std::string lResult;
    auto lIdx{1};

    while(arNum)
    {
        auto lLastDigit = arNum % 10;

        arNum = arNum/10;

        if(arStyle.isDelimRequired(lIdx))
        {
            lResult = "," + lResult;
        }
        lResult = std::to_string(lLastDigit) + lResult;
        ++lIdx;
    }

    return lResult;
}


int main()
{
    FormatStyle lFormatStyle(FormatStyle::Style::INDIAN);

    lFormatStyle.addDelimPosition(4);//thousands
    lFormatStyle.addDelimPosition(6);//lakhs

    int lInput(4123);

    std::cout<<formatNum(lFormatStyle,lInput);
}


