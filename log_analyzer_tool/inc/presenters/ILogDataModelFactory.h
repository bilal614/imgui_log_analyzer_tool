#pragma once

#include <memory>
#include <string>

namespace LogAnalyzerTool
{

class ILogDataModel;

class ILogDataModelFactory
{
public:
    virtual ~ILogDataModelFactory() = default;
    virtual std::unique_ptr<ILogDataModel> createLogDataModel(const std::string& source) = 0;
};

}