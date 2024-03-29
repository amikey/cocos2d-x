#pragma once

#include "../Buffer.h"
#include "platform/CCGL.h"
#include "base/CCEventListenerCustom.h"

#include <vector>

CC_BACKEND_BEGIN

class BufferGL : public Buffer
{
public:
    BufferGL(unsigned int size, BufferType type, BufferUsage usage);
    ~BufferGL();
    
    virtual void updateData(void* data, unsigned int size) override;
    virtual void updateSubData(void* data, unsigned int offset, unsigned int size) override;
    virtual void usingDefaultStoredData(bool needDefaultStoredData) override ;

    inline GLuint getHandler() const { return _buffer; }

private:
#if CC_ENABLE_CACHE_TEXTURE_DATA
    void reloadBuffer();
    void fillBuffer(void* data, unsigned int offset, unsigned int size);

    bool _bufferAlreadyFilled = false;
    EventListenerCustom* _backToForegroundListener = nullptr;
#endif

    GLuint _buffer = 0;
    unsigned int _bufferAllocated = 0;
    char* _data = nullptr;
    bool _needDefaultStoredData = true;
};

CC_BACKEND_END
