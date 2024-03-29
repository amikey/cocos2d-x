#include "VertexLayout.h"
#include "base/ccMacros.h"
#include <cassert>

CC_BACKEND_BEGIN

void VertexLayout::setAttribute(const std::string &name, unsigned int index, VertexFormat format, unsigned int offset, bool needToBeNormallized)
{
    if (_attributes.find(name) != _attributes.end())
    {
        //CCLOG("warning: vertex attribute '%s' already set", name.c_str());
    }
    _attributes[name] = { name, index, format, offset, needToBeNormallized };
}

void VertexLayout::setLayout(unsigned int stride, VertexStepMode stepMode)
{
    _stride = stride;
    _stepMode = stepMode;
}

CC_BACKEND_END
