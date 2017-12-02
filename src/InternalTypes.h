/***************************************************************************************************

  Zyan Disassembler Library (Zydis)

  Original Author : Florian Bernd

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef ZYDIS_INTERNALTYPES_H
#define ZYDIS_INTERNALTYPES_H

#include <Zydis/CommonTypes.h>
#include <Zydis/Defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================================== */
/* Generated Strings                                                                              */
/* ============================================================================================== */

/* ---------------------------------------------------------------------------------------------- */
/* Enums and types                                                                                */
/* ---------------------------------------------------------------------------------------------- */

#pragma pack(push, 1)

/**
 * @brief   Defines the `ZydisGeneratedString` struct. 
 */
typedef struct ZydisGeneratedString_
{
    /**
     * @brief   Contains the actual string.
    */
    char* buffer;
    /**
     * @brief   The length of the string (without 0-termination).
    */
    ZydisU8 length;
} ZydisGeneratedString;

#pragma pack(pop)

/* ---------------------------------------------------------------------------------------------- */
/* Helper macros                                                                                  */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Creates a `ZydisGeneratedString` from a static C-string.
 */
#define ZYDIS_MAKE_GENERATED_STRING(string) \
    { string, sizeof(string) - 1 }

/* ---------------------------------------------------------------------------------------------- */
/* Helper functions                                                                               */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Initializes a `ZydisString` struct with the values from a `ZydisGeneratedString`.
 * 
 * @param   target  A pointer to the target string.
 * @param   source  A pointer to the source string.
 */
ZYDIS_NO_EXPORT ZYDIS_INLINE void ZydisStringInitWithGeneratedString(ZydisString* target, 
    const ZydisGeneratedString* source)
{
    ZYDIS_ASSERT(target);
    ZYDIS_ASSERT(source);

    target->buffer   = source->buffer;
    target->length   = source->length;
    target->capacity = source->length;
}

/* ---------------------------------------------------------------------------------------------- */

/* ============================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ZYDIS_INTERNALTYPES_H */
