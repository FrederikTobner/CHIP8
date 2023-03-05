/****************************************************************************
 * Copyright (C) 2023 by Frederik Tobner                                    *
 *                                                                          *
 * This file is part of CHIP-8.                                             *
 *                                                                          *
 * Permission to use, copy, modify, and distribute this software and its    *
 * documentation under the terms of the GNU General Public License is       *
 * hereby granted.                                                          *
 * No representations are made about the suitability of this software for   *
 * any purpose.                                                             *
 * It is provided "as is" without express or implied warranty.              *
 * See the <https://www.gnu.org/licenses/gpl-3.0.html/>GNU General Public   *
 * License for more details.                                                *
 ****************************************************************************/

/**
 * @file fnv1a.h
 * @brief Definitions regarding the fowler-noll-vo hashing function
 */

#include "fnv1a.h"

#ifdef HASH_32_BIT
#define OFFSET_BASIS 0x811c9dc5u
#define PRIME 0x01000193u
uint32_t 
#else
#define OFFSET_BASIS 0xcbf29ce484222325 
#define PRIME 0x00000100000001B3
uint64_t 
#endif 
fnv1a_hash_data(uint8_t const * data, size_t length)
{
    #ifdef HASH_32_BIT
        uint32_t hash = OFFSET_BASIS;
    #else
        uint64_t hash = OFFSET_BASIS;
    #endif
    for (size_t i = 0; i < length; i++)
    {
        hash ^= data[i];
        hash *= PRIME;
    }
    return hash;
}