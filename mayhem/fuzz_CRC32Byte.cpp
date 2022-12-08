#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>
#include "CRC32.hpp"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);

    uint8_t ch = provider.ConsumeIntegral<uint8_t>();
    uint32_t accumulator = provider.ConsumeIntegral<uint32_t>();
    ancient::internal::CRC32Byte(ch, accumulator);

    return 0;
}