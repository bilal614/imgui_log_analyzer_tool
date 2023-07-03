#include "presenters/FileListPresenter.h"
#include "presenters/ILogFileTabsPresenter.h"
#include "views/IFileListView.h"
#include <memory>

//REMOVE LATER
#include <iostream>

namespace LogAnalyzerTool
{

struct FileListPresenter::Impl
{

    Impl(ILogFileTabsPresenter& fileTabsPresenter, IFileListView& fileListView);
    ~Impl() = default;

    IFileListView& fileListView;
    std::filesystem::path folderPath;

    std::unordered_map<std::string, std::filesystem::path> logFiles;
    ILogFileTabsPresenter& fileTabsPresenter;
};

FileListPresenter::Impl::Impl(ILogFileTabsPresenter& fileTabsPresenter, IFileListView& fileListView) :
    fileListView{fileListView},
    folderPath{},
    fileTabsPresenter{fileTabsPresenter}
{
    fileListView.fileListCallback = [&](const std::string& name){
        fileTabsPresenter.getTabsOpenedEvent()(name);
    };
}

FileListPresenter::FileListPresenter(ILogFileTabsPresenter& fileTabsPresenter, IFileListView& fileListView) :
    p{std::make_unique<Impl>(fileTabsPresenter, fileListView)}
{
}

FileListPresenter::~FileListPresenter() = default;

void FileListPresenter::update(const std::filesystem::path& folderPath)
{
    bool folderPathChanged = false;
    if(p->folderPath != folderPath)
    {
        folderPathChanged = true;
        p->folderPath = folderPath;
        
        for (const auto& entry : std::filesystem::directory_iterator(p->folderPath))
        {
            if(entry.is_regular_file())
            {
                auto tabName = entry.path().stem();
                p->logFiles.insert({tabName, entry.path()});
            }
        }
    }
    std::vector<std::string> logFiles;
    std::transform(p->logFiles.cbegin(), p->logFiles.cend(), std::back_inserter(logFiles), 
        [&](const auto& logFile){
            return logFile.first;
        });
    p->fileListView.draw(logFiles);
}

std::vector<std::filesystem::path> FileListPresenter::getSelectedFiles()
{
    std::vector<std::filesystem::path> selectedFiles;
    for(const auto& logFile : p->logFiles)
    {
        selectedFiles.push_back(logFile.second);
    }
    return selectedFiles;
}

}