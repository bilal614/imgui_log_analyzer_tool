#pragma once

#include <filesystem>
#include <utility>

struct ImVec2;

namespace LogAnalyzerTool
{

class IFolderSelectionPopup
{
public:
    virtual ~IFolderSelectionPopup() = default;
    virtual void drawFolderSelectionModalPopup(ImVec2 popupPosition, ImVec2 popupSize) = 0;
    virtual std::pair<bool, std::filesystem::path> getSelectedFolder() = 0;
    virtual bool popupOpen() = 0;

};

}