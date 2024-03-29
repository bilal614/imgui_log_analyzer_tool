#pragma once

#include <string_view>

namespace LogAnalyzerTool
{

enum class TextColor;

class ILogView
{
public:
    virtual ~ILogView() = default;
    virtual void drawLogLineText(std::string_view logText, const TextColor& color) = 0;
};

}