//
// Created by anton on 2021-05-23.
//
// This file defines the constexpr user-defined literal
// operator""_sid and functions for its execution.
// This user-defined literal makes it possible to hash
// strings in compile-time so that comparisons and the
// like is less performance heavy.
//
// Usage example:
// "This is a string!"_sid
//
// Will be hashed into a unique* 64-bit integer, for
// that combination of characters, at compile time.
//
// *Has a very high probability of being unique.
//

#ifndef USIDE_STRING_HASH_CRC64_H
#define USIDE_STRING_HASH_CRC64_H

inline namespace string_hash_crc64 {
    namespace string_hash_crc64_helper {
        /** Crc64 algorithm initial hash value constant. 0xFFFFFFFFFFFFFFFF is the
             *  initial value to follow the CRC64_GO_ISO version specifically.*/
        constexpr std::uint64_t gcInitialValue = 0xFFFFFFFFFFFFFFFFULL;

        /** Lookup table used by the crc64 algorithm. It contains all possible
         *  remainders when dividing a byte with the polynomial
         *  0x000000000000001B, which is the polynomial value to follow the
         *  CRC64_GO_ISO. The table is used as a speed optimization, as the
         *  algorithm basically consists of remainder and XOR operations. */
        constexpr std::array<std::uint64_t, 256> gcCrc64LookupTable = {
                0x0000000000000000ULL, 0x000000000000001BULL, 0x0000000000000036ULL, 0x000000000000002DULL,
                0x000000000000006CULL, 0x0000000000000077ULL, 0x000000000000005AULL, 0x0000000000000041ULL,
                0x00000000000000D8ULL, 0x00000000000000C3ULL, 0x00000000000000EEULL, 0x00000000000000F5ULL,
                0x00000000000000B4ULL, 0x00000000000000AFULL, 0x0000000000000082ULL, 0x0000000000000099ULL,
                0x00000000000001B0ULL, 0x00000000000001ABULL, 0x0000000000000186ULL, 0x000000000000019DULL,
                0x00000000000001DCULL, 0x00000000000001C7ULL, 0x00000000000001EAULL, 0x00000000000001F1ULL,
                0x0000000000000168ULL, 0x0000000000000173ULL, 0x000000000000015EULL, 0x0000000000000145ULL,
                0x0000000000000104ULL, 0x000000000000011FULL, 0x0000000000000132ULL, 0x0000000000000129ULL,
                0x0000000000000360ULL, 0x000000000000037BULL, 0x0000000000000356ULL, 0x000000000000034DULL,
                0x000000000000030CULL, 0x0000000000000317ULL, 0x000000000000033AULL, 0x0000000000000321ULL,
                0x00000000000003B8ULL, 0x00000000000003A3ULL, 0x000000000000038EULL, 0x0000000000000395ULL,
                0x00000000000003D4ULL, 0x00000000000003CFULL, 0x00000000000003E2ULL, 0x00000000000003F9ULL,
                0x00000000000002D0ULL, 0x00000000000002CBULL, 0x00000000000002E6ULL, 0x00000000000002FDULL,
                0x00000000000002BCULL, 0x00000000000002A7ULL, 0x000000000000028AULL, 0x0000000000000291ULL,
                0x0000000000000208ULL, 0x0000000000000213ULL, 0x000000000000023EULL, 0x0000000000000225ULL,
                0x0000000000000264ULL, 0x000000000000027FULL, 0x0000000000000252ULL, 0x0000000000000249ULL,
                0x00000000000006C0ULL, 0x00000000000006DBULL, 0x00000000000006F6ULL, 0x00000000000006EDULL,
                0x00000000000006ACULL, 0x00000000000006B7ULL, 0x000000000000069AULL, 0x0000000000000681ULL,
                0x0000000000000618ULL, 0x0000000000000603ULL, 0x000000000000062EULL, 0x0000000000000635ULL,
                0x0000000000000674ULL, 0x000000000000066FULL, 0x0000000000000642ULL, 0x0000000000000659ULL,
                0x0000000000000770ULL, 0x000000000000076BULL, 0x0000000000000746ULL, 0x000000000000075DULL,
                0x000000000000071CULL, 0x0000000000000707ULL, 0x000000000000072AULL, 0x0000000000000731ULL,
                0x00000000000007A8ULL, 0x00000000000007B3ULL, 0x000000000000079EULL, 0x0000000000000785ULL,
                0x00000000000007C4ULL, 0x00000000000007DFULL, 0x00000000000007F2ULL, 0x00000000000007E9ULL,
                0x00000000000005A0ULL, 0x00000000000005BBULL, 0x0000000000000596ULL, 0x000000000000058DULL,
                0x00000000000005CCULL, 0x00000000000005D7ULL, 0x00000000000005FAULL, 0x00000000000005E1ULL,
                0x0000000000000578ULL, 0x0000000000000563ULL, 0x000000000000054EULL, 0x0000000000000555ULL,
                0x0000000000000514ULL, 0x000000000000050FULL, 0x0000000000000522ULL, 0x0000000000000539ULL,
                0x0000000000000410ULL, 0x000000000000040BULL, 0x0000000000000426ULL, 0x000000000000043DULL,
                0x000000000000047CULL, 0x0000000000000467ULL, 0x000000000000044AULL, 0x0000000000000451ULL,
                0x00000000000004C8ULL, 0x00000000000004D3ULL, 0x00000000000004FEULL, 0x00000000000004E5ULL,
                0x00000000000004A4ULL, 0x00000000000004BFULL, 0x0000000000000492ULL, 0x0000000000000489ULL,
                0x0000000000000D80ULL, 0x0000000000000D9BULL, 0x0000000000000DB6ULL, 0x0000000000000DADULL,
                0x0000000000000DECULL, 0x0000000000000DF7ULL, 0x0000000000000DDAULL, 0x0000000000000DC1ULL,
                0x0000000000000D58ULL, 0x0000000000000D43ULL, 0x0000000000000D6EULL, 0x0000000000000D75ULL,
                0x0000000000000D34ULL, 0x0000000000000D2FULL, 0x0000000000000D02ULL, 0x0000000000000D19ULL,
                0x0000000000000C30ULL, 0x0000000000000C2BULL, 0x0000000000000C06ULL, 0x0000000000000C1DULL,
                0x0000000000000C5CULL, 0x0000000000000C47ULL, 0x0000000000000C6AULL, 0x0000000000000C71ULL,
                0x0000000000000CE8ULL, 0x0000000000000CF3ULL, 0x0000000000000CDEULL, 0x0000000000000CC5ULL,
                0x0000000000000C84ULL, 0x0000000000000C9FULL, 0x0000000000000CB2ULL, 0x0000000000000CA9ULL,
                0x0000000000000EE0ULL, 0x0000000000000EFBULL, 0x0000000000000ED6ULL, 0x0000000000000ECDULL,
                0x0000000000000E8CULL, 0x0000000000000E97ULL, 0x0000000000000EBAULL, 0x0000000000000EA1ULL,
                0x0000000000000E38ULL, 0x0000000000000E23ULL, 0x0000000000000E0EULL, 0x0000000000000E15ULL,
                0x0000000000000E54ULL, 0x0000000000000E4FULL, 0x0000000000000E62ULL, 0x0000000000000E79ULL,
                0x0000000000000F50ULL, 0x0000000000000F4BULL, 0x0000000000000F66ULL, 0x0000000000000F7DULL,
                0x0000000000000F3CULL, 0x0000000000000F27ULL, 0x0000000000000F0AULL, 0x0000000000000F11ULL,
                0x0000000000000F88ULL, 0x0000000000000F93ULL, 0x0000000000000FBEULL, 0x0000000000000FA5ULL,
                0x0000000000000FE4ULL, 0x0000000000000FFFULL, 0x0000000000000FD2ULL, 0x0000000000000FC9ULL,
                0x0000000000000B40ULL, 0x0000000000000B5BULL, 0x0000000000000B76ULL, 0x0000000000000B6DULL,
                0x0000000000000B2CULL, 0x0000000000000B37ULL, 0x0000000000000B1AULL, 0x0000000000000B01ULL,
                0x0000000000000B98ULL, 0x0000000000000B83ULL, 0x0000000000000BAEULL, 0x0000000000000BB5ULL,
                0x0000000000000BF4ULL, 0x0000000000000BEFULL, 0x0000000000000BC2ULL, 0x0000000000000BD9ULL,
                0x0000000000000AF0ULL, 0x0000000000000AEBULL, 0x0000000000000AC6ULL, 0x0000000000000ADDULL,
                0x0000000000000A9CULL, 0x0000000000000A87ULL, 0x0000000000000AAAULL, 0x0000000000000AB1ULL,
                0x0000000000000A28ULL, 0x0000000000000A33ULL, 0x0000000000000A1EULL, 0x0000000000000A05ULL,
                0x0000000000000A44ULL, 0x0000000000000A5FULL, 0x0000000000000A72ULL, 0x0000000000000A69ULL,
                0x0000000000000820ULL, 0x000000000000083BULL, 0x0000000000000816ULL, 0x000000000000080DULL,
                0x000000000000084CULL, 0x0000000000000857ULL, 0x000000000000087AULL, 0x0000000000000861ULL,
                0x00000000000008F8ULL, 0x00000000000008E3ULL, 0x00000000000008CEULL, 0x00000000000008D5ULL,
                0x0000000000000894ULL, 0x000000000000088FULL, 0x00000000000008A2ULL, 0x00000000000008B9ULL,
                0x0000000000000990ULL, 0x000000000000098BULL, 0x00000000000009A6ULL, 0x00000000000009BDULL,
                0x00000000000009FCULL, 0x00000000000009E7ULL, 0x00000000000009CAULL, 0x00000000000009D1ULL,
                0x0000000000000948ULL, 0x0000000000000953ULL, 0x000000000000097EULL, 0x0000000000000965ULL,
                0x0000000000000924ULL, 0x000000000000093FULL, 0x0000000000000912ULL, 0x0000000000000909ULL
        };

        /** Lookup table used by the reverseBits8 and reverseBits64 functions as a quick way to find the
         * reversed (or reflected) bit order of a byte (given as the index). */
        constexpr std::array<unsigned char, 256> gcBitReverseTable256 = {
                0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0, 0x10, 0x90, 0x50, 0xD0, 0x30, 0xB0, 0x70, 0xF0,
                0x08, 0x88, 0x48, 0xC8, 0x28, 0xA8, 0x68, 0xE8, 0x18, 0x98, 0x58, 0xD8, 0x38, 0xB8, 0x78, 0xF8,
                0x04, 0x84, 0x44, 0xC4, 0x24, 0xA4, 0x64, 0xE4, 0x14, 0x94, 0x54, 0xD4, 0x34, 0xB4, 0x74, 0xF4,
                0x0C, 0x8C, 0x4C, 0xCC, 0x2C, 0xAC, 0x6C, 0xEC, 0x1C, 0x9C, 0x5C, 0xDC, 0x3C, 0xBC, 0x7C, 0xFC,
                0x02, 0x82, 0x42, 0xC2, 0x22, 0xA2, 0x62, 0xE2, 0x12, 0x92, 0x52, 0xD2, 0x32, 0xB2, 0x72, 0xF2,
                0x0A, 0x8A, 0x4A, 0xCA, 0x2A, 0xAA, 0x6A, 0xEA, 0x1A, 0x9A, 0x5A, 0xDA, 0x3A, 0xBA, 0x7A, 0xFA,
                0x06, 0x86, 0x46, 0xC6, 0x26, 0xA6, 0x66, 0xE6, 0x16, 0x96, 0x56, 0xD6, 0x36, 0xB6, 0x76, 0xF6,
                0x0E, 0x8E, 0x4E, 0xCE, 0x2E, 0xAE, 0x6E, 0xEE, 0x1E, 0x9E, 0x5E, 0xDE, 0x3E, 0xBE, 0x7E, 0xFE,
                0x01, 0x81, 0x41, 0xC1, 0x21, 0xA1, 0x61, 0xE1, 0x11, 0x91, 0x51, 0xD1, 0x31, 0xB1, 0x71, 0xF1,
                0x09, 0x89, 0x49, 0xC9, 0x29, 0xA9, 0x69, 0xE9, 0x19, 0x99, 0x59, 0xD9, 0x39, 0xB9, 0x79, 0xF9,
                0x05, 0x85, 0x45, 0xC5, 0x25, 0xA5, 0x65, 0xE5, 0x15, 0x95, 0x55, 0xD5, 0x35, 0xB5, 0x75, 0xF5,
                0x0D, 0x8D, 0x4D, 0xCD, 0x2D, 0xAD, 0x6D, 0xED, 0x1D, 0x9D, 0x5D, 0xDD, 0x3D, 0xBD, 0x7D, 0xFD,
                0x03, 0x83, 0x43, 0xC3, 0x23, 0xA3, 0x63, 0xE3, 0x13, 0x93, 0x53, 0xD3, 0x33, 0xB3, 0x73, 0xF3,
                0x0B, 0x8B, 0x4B, 0xCB, 0x2B, 0xAB, 0x6B, 0xEB, 0x1B, 0x9B, 0x5B, 0xDB, 0x3B, 0xBB, 0x7B, 0xFB,
                0x07, 0x87, 0x47, 0xC7, 0x27, 0xA7, 0x67, 0xE7, 0x17, 0x97, 0x57, 0xD7, 0x37, 0xB7, 0x77, 0xF7,
                0x0F, 0x8F, 0x4F, 0xCF, 0x2F, 0xAF, 0x6F, 0xEF, 0x1F, 0x9F, 0x5F, 0xDF, 0x3F, 0xBF, 0x7F, 0xFF
        };

        /**
         * Calculates the reverse (or reflected) bit order of an 8 bit number.
         * @param bits - The 8 bit number to calculate the reverse for.
         * @return An 8 bit number whom's bits are ordered in reverse from <code>bits</code>.
         */
        constexpr unsigned char reverseBits8(unsigned char bits) {
            return gcBitReverseTable256[bits];  // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            // Implicit bounds check due to an unsigned char being 0-255
            // and gcBitReverseTable256 having 256 elements (which is its
            // whole purpose).
        }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-bounds-constant-array-index" // Indices guaranteed to always be 0-255 due to bit-wise operators (which is the bounds of the lookup table)
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-magic-numbers"             // Magic numbers, are directly correlated to real-life "hard" numbers for byte sizes, and are meaningful for
                                                                                   // the execution of this function specifically.
        /**
         * Calculates the reverse (or reflected) bit order of a 64 bit number.
         * @param bits - The 64 bit number to calculate the reverse for.
         * @return A 64 bit number whom's bits are ordered in reverse from <code>bits</code>.
         */
        constexpr std::uint64_t reverseBits64(std::uint64_t bits) {
            return (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 0ull) & 0xFFull]) << 56ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 8ull) & 0xFFull]) << 48ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 16ull) & 0xFFull]) << 40ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 24ull) & 0xFFull]) << 32ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 32ull) & 0xFFull]) << 24ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 40ull) & 0xFFull]) << 16ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 48ull) & 0xFFull]) << 8ull) |
                   (static_cast<std::uint64_t>(gcBitReverseTable256[(bits >> 56ull) & 0xFFull]) << 0ull);
        }

#pragma clang diagnostic pop
    }

    /** Crc64 algorithm value to be XOR with the final hash before return.
        *  0xFFFFFFFFFFFFFFFF is the final XOR value to follow the
        *  CRC64_GO_ISO version specifically. */
    constexpr std::uint64_t gcFinalXorValue = 0xFFFFFFFFFFFFFFFFULL;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-bounds-pointer-arithmetic" // Special case pointer arithmetic.
#pragma ide diagnostic ignored "cppcoreguidelines-pro-bounds-constant-array-index" // Index guaranteed to always be 0-255 due to bit-wise operators (which is the bounds of the lookup table)

    /**
    * Hashes a string str into a 64 bit integer according to the crc64 algorithm (version CRC64_GO_ISO).
    * OBS! Important! This function is recursive and excludes the final XOR between the hash and gcFinalXorValue.
    * For correct results according to the CRC64_GO_ISO version, this XOR operation should be done on the returned
    * hash value.
    * @param str   - The string to be hashed.
    * @param size  - The size of the string excluding the '\0' character.
    * @param crc   - The initial hash value (gcInitialValue to follow the CRC64_GO_ISO version).
    * @return A 64 bit unsigned integer (that should be XOR with a value equivalent to gcFinalXorValue) with a high probability of being unique for the specific string character combination.
    */
    constexpr std::uint64_t recursiveHashOperation(const char *str, const std::size_t size, const std::uint64_t crc) {
        constexpr std::uint64_t cNumBitsInByte = 8ULL;
        constexpr std::uint64_t cNumBitsToLastByteIn64BitType = 56ULL;
        return size == 0 ?
               string_hash_crc64_helper::reverseBits64(crc) :
               recursiveHashOperation(&str[1],
                                      size - 1,
                                      (crc << cNumBitsInByte) ^
                                      string_hash_crc64_helper::gcCrc64LookupTable[(crc ^
                                      (static_cast<std::uint64_t>(string_hash_crc64_helper::reverseBits8(static_cast<unsigned char>(str[0]))) <<
                                      cNumBitsToLastByteIn64BitType)) >> cNumBitsToLastByteIn64BitType]);
    }

#pragma clang diagnostic pop

    /**
    * User defined literal:
    *      \code"{SOME STRING}"_sid\endcode
    * Which is used to compile-time hash strings so that they can be treated as unsigned integers (64 bit)
    * for faster comparisons and argument passing. The hashing algorithm used is crc64
    * (with settings set to follow the CRC64_GO_ISO version), which is performed through a call to
    * Core::StringHashCrc64::recursiveHashOperation(const char*,const std::size_t,const std::uint64_t).
    * @param str   - The string to be hashed.
    * @param size  - The size of the string excluding the '\0' character.
    * @return A 64 bit unsigned integer with a high probability of being unique for the specific string character combination.
    */
    constexpr std::uint64_t operator ""_sid(const char *str, const std::size_t size) {
        return recursiveHashOperation(str, size, string_hash_crc64_helper::gcInitialValue) ^ gcFinalXorValue;
    }

    /** Exact execution as ""_sid operator. */
    constexpr std::uint64_t hash(const char* str, const std::size_t size){
        return recursiveHashOperation(str, size, string_hash_crc64_helper::gcInitialValue) ^ gcFinalXorValue;
    }
}
#endif //USIDE_STRING_HASH_CRC64_H
