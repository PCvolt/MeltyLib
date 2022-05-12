//
// Created by PC_volt on 11/05/2022.
//

#ifndef MELTYLIB_DRAWUTILS_H
#define MELTYLIB_DRAWUTILS_H

#include <type_traits>
#include <utility>
#include <vector>
#include "Vector2.h"
#include "Font.h"

namespace MeltyLib {
    namespace DrawUtils {
        struct DxMeltyColor {
            union {
                struct {
                    unsigned char r;
                    unsigned char g;
                    unsigned char b;
                    unsigned char a;
                };
                unsigned color;
            };

            DxMeltyColor() = default;
            DxMeltyColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xFF) noexcept;
            DxMeltyColor(unsigned color) noexcept;

            DxMeltyColor &operator=(unsigned color);
            DxMeltyColor operator+(const DxMeltyColor &other) const;
            DxMeltyColor &operator+=(const DxMeltyColor &other);
            DxMeltyColor operator*(const DxMeltyColor &other) const;
            DxMeltyColor &operator*=(const DxMeltyColor &other);

            template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
            DxMeltyColor operator*(T alpha) const
            {
                DxMeltyColor result = *this;

                result *= alpha;
                return result;
            }

            template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
            DxMeltyColor &operator*=(T alpha)
            {
                this->a = std::min<unsigned char>(this->a * alpha, 255);
                return *this;
            }

            operator unsigned() const;

            static const DxMeltyColor White;
            static const DxMeltyColor Yellow;
            static const DxMeltyColor Red;
            static const DxMeltyColor Blue;
            static const DxMeltyColor Green;
            static const DxMeltyColor Magenta;
            static const DxMeltyColor Cyan;
            static const DxMeltyColor Black;
            static const DxMeltyColor Transparent;
        };

        class Texture {
        private:
            int _handle;
            bool _loaded = false;
            Vector2u _size;

        public:
            Texture() noexcept = default;
            Texture(int handle, const Vector2u &size) noexcept;
            Texture(Texture &) = delete;
            Texture(Texture &&) = delete;
            Texture &operator=(Texture &) = delete;
            Texture &operator=(Texture &&) = delete;
            ~Texture() noexcept;

            bool hasTexture() const noexcept;
            void activate(int stage = 0) const noexcept;
            Vector2u getSize() const;

            void setHandle(int handle, const Vector2u &size);
            void swap(Texture &other);
            void destroy();
            int releaseHandle();

            bool loadFromFile(const char *path);
            bool loadFromGame(const char *path);
            bool loadFromResource(HMODULE srcModule, LPCTSTR srcResource);
            bool createFromText(const char *str, MeltyFont &font, Vector2u size, Vector2i *realSize = nullptr);
        };



        template<typename T>
        struct Rect {
            T x1;
            T y1;
            T x2;
            T y2;
        };
        typedef Rect<float> FloatRect;
    }
}
// Bravo Bold
// DejaVu Sans Condensed
// NewCesannePro

/*
DirectX draw frame advantage and gaps
disable fps counter drawTexture
toggle normal -> black -> green screen background
it crashes when changing select items wtf
*/

#endif //MELTYLIB_DRAWUTILS_H
