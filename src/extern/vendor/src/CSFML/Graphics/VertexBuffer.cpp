////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/VertexBuffer.h>
#include <CSFML/Graphics/VertexBufferStruct.hpp>


////////////////////////////////////////////////////////////
sfVertexBuffer* sfVertexBuffer_create(unsigned int vertexCount, sfPrimitiveType type, sfVertexBufferUsage usage)
{
    sf::VertexBuffer buffer;
    if (!buffer.create(vertexCount))
        return nullptr;

    buffer.setPrimitiveType(static_cast<sf::PrimitiveType>(type));
    buffer.setUsage(static_cast<sf::VertexBuffer::Usage>(usage));

    return new sfVertexBuffer{std::move(buffer)};
}


////////////////////////////////////////////////////////////
sfVertexBuffer* sfVertexBuffer_copy(const sfVertexBuffer* vertexBuffer)
{
    auto* buffer = new sfVertexBuffer;
    buffer->This = sf::VertexBuffer(vertexBuffer->This);
    return buffer;
}


////////////////////////////////////////////////////////////
void sfVertexBuffer_destroy(const sfVertexBuffer* vertexBuffer)
{
    delete vertexBuffer;
}


////////////////////////////////////////////////////////////
size_t sfVertexBuffer_getVertexCount(const sfVertexBuffer* vertexBuffer)
{
    assert(vertexBuffer);
    return vertexBuffer->This.getVertexCount();
}


////////////////////////////////////////////////////////////
bool sfVertexBuffer_update(sfVertexBuffer* vertexBuffer, const sfVertex* vertices, unsigned int vertexCount, unsigned int offset)
{
    // the cast is safe, sfVertex has to be binary compatible with sf::Vertex
    assert(vertexBuffer);
    return vertexBuffer->This.update(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount, offset);
}


////////////////////////////////////////////////////////////
bool sfVertexBuffer_updateFromVertexBuffer(sfVertexBuffer* vertexBuffer, const sfVertexBuffer* other)
{
    assert(vertexBuffer);
    return vertexBuffer->This.update(other->This);
}


///////////////////////////////////////////////////////////
void sfVertexBuffer_swap(sfVertexBuffer* left, sfVertexBuffer* right)
{
    assert(left);
    assert(right);
    left->This.swap(right->This);
}


////////////////////////////////////////////////////////////
unsigned int sfVertexBuffer_getNativeHandle(sfVertexBuffer* vertexBuffer)
{
    assert(vertexBuffer);
    return vertexBuffer->This.getNativeHandle();
}


////////////////////////////////////////////////////////////
void sfVertexBuffer_setPrimitiveType(sfVertexBuffer* vertexBuffer, sfPrimitiveType type)
{
    assert(vertexBuffer);
    vertexBuffer->This.setPrimitiveType(static_cast<sf::PrimitiveType>(type));
}


////////////////////////////////////////////////////////////
sfPrimitiveType sfVertexBuffer_getPrimitiveType(const sfVertexBuffer* vertexBuffer)
{
    assert(vertexBuffer);
    return static_cast<sfPrimitiveType>(vertexBuffer->This.getPrimitiveType());
}


////////////////////////////////////////////////////////////
void sfVertexBuffer_setUsage(sfVertexBuffer* vertexBuffer, sfVertexBufferUsage usage)
{
    assert(vertexBuffer);
    vertexBuffer->This.setUsage(static_cast<sf::VertexBuffer::Usage>(usage));
}


////////////////////////////////////////////////////////////
sfVertexBufferUsage sfVertexBuffer_getUsage(const sfVertexBuffer* vertexBuffer)
{
    assert(vertexBuffer);
    return static_cast<sfVertexBufferUsage>(vertexBuffer->This.getUsage());
}


////////////////////////////////////////////////////////////
void sfVertexBuffer_bind(const sfVertexBuffer* vertexBuffer)
{
    sf::VertexBuffer::bind(&vertexBuffer->This);
}


////////////////////////////////////////////////////////////
bool sfVertexBuffer_isAvailable()
{
    return sf::VertexBuffer::isAvailable();
}
