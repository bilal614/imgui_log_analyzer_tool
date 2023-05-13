#pragma once

struct ImVec2;

namespace LogAnalyzerTool
{
class IMainViewPort  
{
public:
    virtual ~IMainViewPort() = default;
    virtual ImVec2 getAreaSize() const = 0;
    virtual ImVec2 getWorkAreaSize() const = 0;
    virtual ImVec2 getViewportPosition() const = 0;
    virtual ImVec2 getViewportCenter() const  = 0;
};

}