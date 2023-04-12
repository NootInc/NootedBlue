//  Copyright © 2022-2023 ChefKiss Inc. Licensed under the Thou Shalt Not Profit License version 1.0. See LICENSE for
//  details.

#ifndef kern_patches_hpp
#define kern_patches_hpp
#include <Headers/kern_util.hpp>

/**
 * `Haswell Patch Set for macOS Sierra`
 *  TODO: Port them for later verions
 */

static const uint8_t kHSWProbeSierra1Original[] = {0x83, 0xF8, 0x04, 0x74, 0x12, 0x83, 0xF8, 0x02, 0x75, 0x3D};
static const uint8_t kHSWProbeSierra1Patched[] = {0x83, 0xF8, 0x04, 0x90, 0x90, 0x83, 0xF8, 0x02, 0x90, 0x90};
/** Patch 2's hex does not line up with any bytes in Catalina */
static const uint8_t kHSWProbeSierra2Original[] = {0x3D, 0x86, 0x80, 0x26, 0x0D, 0x74, 0x20};
static const uint8_t kHSWProbeSierra2Patched[] = {0x3D, 0x86, 0x80, 0x26, 0x0D, 0xEB, 0x20};

static const uint8_t kHSWProbeSierra3Original[] = {0x75, 0x59, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0xB8, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kHSWProbeSierra3Patched[] = {0x90, 0x90, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00};

static const uint8_t kHSWProbeSierra4Original[] = {0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0xB8, 0x01, 0x00, 0x00, 0x00};
static const uint8_t kHSWProbeSierra4Patched[] = {0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xB8, 0x00, 0x00, 0x00, 0x00};

/**
 * `Haswell Patch Set for Catalina (EXPERIMENTAL)`
 *  Since these are based off of the original Sierra patches, these may be incorrect, hence the experimental
 * designation.
 */

static const uint8_t kHSWProbeCatalina1Original[] = {0x66, 0x83, 0xF8, 0x02, 0x74, 0x0B, 0x66, 0x83, 0xF8, 0x04, 0x75,
    0x7F};
static const uint8_t kHSWProbeCatalina1Patched[] = {0x66, 0x83, 0xF8, 0x02, 0x90, 0x90, 0x66, 0x83, 0xF8, 0x02, 0x90,
    0x90};

static const uint8_t kHSWProbeCatalina2Original[] = {0x75, 0x59, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0xB8, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kHSWProbeCatalina2Patched[] = {0x90, 0x90, 0x41, 0xC7, 0x86, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00};

/** Patch obsolete? Investigation required.*/
// static const uint8_t kHSWProbeCatalina3Original[] = {0x41, 0xC7, 0x86, 0xBC, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00,
// 0x00, 0xB8, 0x01, 0x00, 0x00, 0x00}; static const uint8_t kHSWProbeCatalina3Patched[] = {0x41, 0xC7, 0x86, 0xBC,
// 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE9, 0x29, 0xFF, 0xFF, 0xFF};

static const uint8_t kHSWProbeCatalina4Original[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0x81, 0xFE, 0x86, 0x80, 0x12, 0x04,
    0x74};
static const uint8_t kHSWProbeCatalina4Patched[] = {0xB8, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFE, 0x86, 0x80, 0x12, 0x04,
    0x74};
/** Due to changes in the kext, Patch 4 had to be split up into two patches in order to avoid it being too long */

static const char kHSWMTLDriverPath[] = "/System/Library/Extensions/AppleIntelHD5000GraphicsMTLDriver.bundle/Contents/"
                                        "MacOS/AppleIntelHD5000GraphicsMTLDriver";
static const char kHSWVADriverPath[] = "/System/Library/Extensions/AppleIntelHD5000GraphicsVADriver.bundle/Contents/"
                                       "MacOS/AppleIntelHD5000GraphicsVADriver";

static_assert(arrsize(kHSWProbeCatalina1Original) == arrsize(kHSWProbeCatalina1Patched));
static_assert(arrsize(kHSWProbeCatalina2Original) == arrsize(kHSWProbeCatalina2Patched));
// static_assert(arrsize(kHSWProbeCatalina3Original) == arrsize(kHSWProbeCatalina3Patched));
static_assert(arrsize(kHSWProbeCatalina4Original) == arrsize(kHSWProbeCatalina4Patched));

/** Driver Bundle patches will be worked on eventually */
#endif /* kern_patches_hpp */