#pragma once

#include "dds_engine/Renderer/Buffer.h"

namespace dds{

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        ~OpenGLVertexBuffer();

        void Bind() const override;
        void Unbind() const override;

        virtual const BufferLayout& GetLayout() const override {return m_Layout;}
        virtual void SetLayout(const BufferLayout& layout) override {m_Layout = layout;}

    private:
        BufferLayout m_Layout;
        uint32_t m_RendererID;

    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        ~OpenGLIndexBuffer();

        void Bind() const override;
        void Unbind() const override;
        inline uint32_t GetCount() const override {return m_Count;}

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}
