#pragma once

#include <filesystem>
#include <string>

namespace LogScpWrapper
{

struct RemoteHost;

enum class PromptType {
    None,
    HostAuthenticity,
    UserAuthentication,
    KeyFileAuthentication
};


struct AuthenticationRequest {
    PromptType prompt;
    std::string data;
};

class IAuthenticationWorkFlow
{
public:
    virtual ~IAuthenticationWorkFlow() = default;
    virtual void addRemoteHost(const RemoteHost& host) = 0;
    virtual void addKeyFile(const std::filesystem::path& filePath) = 0;
    virtual AuthenticationRequest validatePrompt(const std::string& prompt) = 0; 
};

}