#pragma once

typedef union {
    uint32_t raw;
    struct {
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
    };
} user_config_t; // used for persistent memory of settings (only 16 bytes avail on AVR?)

user_config_t user_config;