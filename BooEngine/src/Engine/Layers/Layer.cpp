#include "booPCH.h"
#include "Layer.h"

namespace boo
{
    Layer::Layer(const std::string& debugName)
        : m_DebugName(debugName)
    {
    }

    Layer::~Layer()
    {
    }
}