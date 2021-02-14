#pragma once

#include <olcPixelGameEngine.h>

// Just a shorter name for reference counted pointers
template <typename T>
using Ref = std::shared_ptr<T>;

// A simple Logger class for  debuggind pourposes
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

// Generic space object that does things in the game
class SpaceEntity
{
public:
    virtual void Update(float fElapsedTime) = 0;
    virtual void Show(olc::PixelGameEngine &engine) = 0;
};

// Generic scene object to group SpaceEntity and make them work together
class Scene
{
public:
    enum NextScene
    {
        DiscardCurrent = -1,
        KeepCurrent = 0,
        AddNext = 1,
        Error = 2,
    };

protected:
    std::list<Ref<SpaceEntity>> mEntityList;

public:
    Scene()
        : mEntityList() {}

    virtual std::pair<NextScene, std::optional<Scene>> Render(olc::PixelGameEngine &engine, float fElapsedTime)
    {
        for (auto entity : mEntityList)
        {
            entity->Update(fElapsedTime);
            entity->Show(engine);
        }
        return (std::make_pair(KeepCurrent, std::make_optional<Scene>()));
    }
};
