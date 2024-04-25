#pragma once

#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <cstdint>
#include <string>
#include <format>

struct hex_color
{
private:
    template <typename I>
    std::string n2hexstr(I w, size_t hex_len = sizeof(I) << 1)
    {
        static const char *digits = "0123456789ABCDEF";
        std::string rc(hex_len, '0');
        for (size_t i = 0, j = (hex_len - 1) * 4; i < hex_len; ++i, j -= 4)
            rc[i] = digits[(w >> j) & 0x0f];
        return rc;
    }

public:
    hex_color(uint8_t Red, uint8_t Green, uint8_t Blue)
    {
        this->R = Red;
        this->G = Green;
        this->B = Blue;
    }

    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;

    operator std::string() { return ("#" + n2hexstr(R) + n2hexstr(G) + n2hexstr(B)); };
};
#endif