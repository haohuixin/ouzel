// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <vector>
#include "SharedPtr.h"
#include "Noncopyable.h"
#include "ReferenceCounted.h"

namespace ouzel
{
    class Layer;
    
    class Scene: public Noncopyable, public ReferenceCounted
    {
    public:
        Scene();
        virtual ~Scene();
        
        virtual void update(float delta);
        virtual void draw();
        
        void addLayer(Layer* layer);
        void removeLayer(Layer* layer);
        bool hasLayer(Layer* layer) const;
        const std::vector<SharedPtr<Layer>>& getLayers() const { return _layers; }
        
        virtual void recalculateProjection();
        
        virtual void reorderLayers();
        
    protected:
        std::vector<SharedPtr<Layer>> _layers;
        bool _reorderLayers = false;
    };
}
