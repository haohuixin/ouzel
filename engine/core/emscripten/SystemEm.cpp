// Copyright 2015-2020 Elviss Strazdins. All rights reserved.

#include <cstdlib>
#include "SystemEm.hpp"
#include "EngineEm.hpp"
#include "../../utils/Log.hpp"

int main(int argc, char* argv[])
{
    try
    {
        ouzel::core::emscripten::Engine engine(argc, argv);
        engine.run();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        ouzel::logger.log(ouzel::Log::Level::error) << e.what();
        return EXIT_FAILURE;
    }
}

namespace ouzel::core::emscripten
{
}
