#pragma once

class Logger
{
public:
    static inline void Verified(const std::string_view &message) { PrettyPrint(SuccessCode, message); };
    static inline void Warning(const std::string_view &message) { PrettyPrint(WarningCode, message); };
    static inline void Error(const std::string_view &message) { PrettyPrint(ErrorCode, message); };
    static inline void Info(const std::string_view &message) { PrettyPrint(InfoCode, message); };

private:
    enum Codes
    {
        ErrorCode,
        SuccessCode,
        WarningCode,
        InfoCode,
    };

    static constexpr std::string_view mEncoding[4] = {"\033[31m", "\033[32m", "\033[33m", ""};
    static constexpr std::string_view mResetCode = "\033[0m";

    static inline void PrettyPrint(Codes msgType, const std::string_view &message)
    {
        std::cout << mEncoding[msgType] << message << mResetCode << std::endl;
    }
};