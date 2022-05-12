//
// Created by PC_volt on 11/05/2022.
//

#include "DrawUtils.h"
#include <cmath>

namespace MeltyLib {
    namespace DrawUtils {
        DxMeltyColor::DxMeltyColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept :
                r(r),
                g(g),
                b(b),
                a(a)
        {
        }

        DxMeltyColor::DxMeltyColor(unsigned int color) noexcept :
                color(color)
        {
        }

        DxMeltyColor::operator unsigned() const
        {
            return this->color;
        }

        DxMeltyColor &DxMeltyColor::operator=(unsigned int color)
        {
            this->color = color;
            return *this;
        }

        DxMeltyColor DxMeltyColor::operator+(const DxMeltyColor &other) const
        {
            DxMeltyColor result = *this;

            result += other;
            return result;
        }

        DxMeltyColor &DxMeltyColor::operator+=(const DxMeltyColor &other)
        {
            this->a = std::ceil((other.a + this->a) / 2.);
            this->r = std::ceil((other.r + this->r) / 2.);
            this->g = std::ceil((other.g + this->g) / 2.);
            this->b = std::ceil((other.b + this->b) / 2.);
            return *this;
        }

        DxMeltyColor DxMeltyColor::operator*(const DxMeltyColor &other) const
        {
            DxMeltyColor result = *this;

            result *= other;
            return result;
        }

        DxMeltyColor &DxMeltyColor::operator*=(const DxMeltyColor &other)
        {
            this->a = std::ceil((other.a * this->a) / 255.f);
            this->r = std::ceil((other.r * this->r) / 255.f);
            this->g = std::ceil((other.g * this->g) / 255.f);
            this->b = std::ceil((other.b * this->b) / 255.f);
            return *this;
        }

        const DxMeltyColor DxMeltyColor::White      {0xFF, 0xFF, 0xFF, 0xFF};
        const DxMeltyColor DxMeltyColor::Red        {0xFF, 0x00, 0x00, 0xFF};
        const DxMeltyColor DxMeltyColor::Blue       {0x00, 0x00, 0xFF, 0xFF};
        const DxMeltyColor DxMeltyColor::Green      {0x00, 0xFF, 0x00, 0xFF};
        const DxMeltyColor DxMeltyColor::Yellow     {0xFF, 0xFF, 0x00, 0xFF};
        const DxMeltyColor DxMeltyColor::Magenta    {0xFF, 0x00, 0xFF, 0xFF};
        const DxMeltyColor DxMeltyColor::Cyan       {0x00, 0xFF, 0xFF, 0xFF};
        const DxMeltyColor DxMeltyColor::Black      {0x00, 0x00, 0x00, 0xFF};
        const DxMeltyColor DxMeltyColor::Transparent{0x00, 0x00, 0x00, 0x00};

        Texture::Texture(int handle, const Vector2<unsigned> &size) noexcept : _handle(handle), _loaded(true), _size(size)
        {
        }
    }
}