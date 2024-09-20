#include "../Game/GameManager.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
int main(int argc, char *argv[])
{
    Input::initialize();
    Renderer::initialize();
    GameManager::Start();
    Renderer::destroy();
    return 0;
}

