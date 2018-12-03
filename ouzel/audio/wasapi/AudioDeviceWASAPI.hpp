// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#ifndef OUZEL_AUDIO_AUDIODEVICEWASAPI_HPP
#define OUZEL_AUDIO_AUDIODEVICEWASAPI_HPP

#include "audio/AudioDevice.hpp"

namespace ouzel
{
    namespace audio
    {
        class AudioDeviceWASAPI final: public AudioDevice
        {
        public:
            explicit AudioDeviceWASAPI(Mixer& initMixer);
        };
    } // namespace audio
} // namespace ouzel

#endif // OUZEL_AUDIO_AUDIODEVICEWASAPI_HPP