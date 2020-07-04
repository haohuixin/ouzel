// Copyright 2015-2020 Elviss Strazdins. All rights reserved.

#include "RenderTarget.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

namespace ouzel::graphics
{
    RenderTarget::RenderTarget(Renderer& initRenderer,
                               const std::vector<Texture*>& initColorTextures,
                               Texture* initDepthTexture):
        resource(initRenderer.getDevice()->createResource()),
        colorTextures(initColorTextures),
        depthTexture(initDepthTexture)
    {
        std::set<std::uintmax_t> colorTextureIds;

        for (const auto& colorTexture : colorTextures)
            colorTextureIds.insert(colorTexture ? colorTexture->getResource() : 0);

        initRenderer.addCommand(std::make_unique<InitRenderTargetCommand>(resource,
                                                                          colorTextureIds,
                                                                          depthTexture ? depthTexture->getResource() : std::uintmax_t(0)));
    }
}
