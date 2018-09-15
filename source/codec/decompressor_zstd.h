//
// Aspia Project
// Copyright (C) 2018 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef ASPIA_CODEC__DECOMPRESSOR_ZSTD_H_
#define ASPIA_CODEC__DECOMPRESSOR_ZSTD_H_

#include <zstd.h>

#include "base/macros_magic.h"
#include "codec/decompressor.h"

namespace aspia {

class DecompressorZstd : public Decompressor
{
public:
    DecompressorZstd();
    ~DecompressorZstd();

    void reset() override;

    // Decompressor implementations.
    bool process(const uint8_t* input_data,
                 size_t input_size,
                 uint8_t* output_data,
                 size_t output_size,
                 size_t* consumed,
                 size_t* written) override;

private:
    ZSTD_DStream* stream_;

    DISALLOW_COPY_AND_ASSIGN(DecompressorZstd);
};

} // namespace aspia

#endif // ASPIA_CODEC__DECOMPRESSOR_ZSTD_H_