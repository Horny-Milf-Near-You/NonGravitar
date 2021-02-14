#include "Core.hpp"

class WelcomeScene : public Scene
{
public:
    const std::string titleMsg = "NonGravitar 2.0 by its-hmny";
    const std::string subtitleMsg = "\nMade with olcPixelGameEngine by OneLoneCoder";
    const uint8_t titleScale = 5;
    const uint8_t subtitleScale = 2;

    virtual std::pair<NextScene, std::optional<Scene>> Render(olc::PixelGameEngine &engine, float fElapsedTime) override
    {
        // Calculate offset to center the title message and apply
        const olc::vf2d titleOffset = (engine.GetWindowSize() - engine.GetTextSize(titleMsg) * titleScale) / 2;
        engine.DrawString(titleOffset, titleMsg, olc::WHITE, titleScale);

        // Calculate the offset to center the subtitle message, the \n in the subtitle assure a bigger offset on the y axis
        olc::vf2d subtitleOffset = (engine.GetWindowSize() - engine.GetTextSize(subtitleMsg) * subtitleScale) / 2;
        engine.DrawString(subtitleOffset + olc::vf2d(0, titleOffset.y), subtitleMsg, olc::WHITE, subtitleScale);

        return std::make_pair(KeepCurrent, std::make_optional<Scene>());
    };
};

class PauseScene : public Scene
{
    //public:
    //std::pair<NextScene, std::optional<Scene>> Render(olc::PixelGameEngine &engine, float fElapsedTime) override{};
};
