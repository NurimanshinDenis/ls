#pragma once

#include <stdint.h>
#include <stddef.h>
#include <memory>

typedef uint8_t byte;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;


union Word{ 
    u64 _u64;
    i64 _i64;
    
    u32 _u32[2];
    i32 _i32[2];
    
    u16 _u16[4];
    i16 _i16[4];

    u8 _u8[8];
    i8 _i8[8];

    f64 _f64;
    f32 _f32[2];
};











