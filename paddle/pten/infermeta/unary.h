/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

// See Note [ Why still include the fluid headers? ]
#include "paddle/pten/core/tensor_meta.h"

namespace pten {

// Common InferShape Functions for unary operators, The format like:
//
//   1. DenseTensorMeta [OpName]InferShape(const DenseTensorMeta& x_meta, ...)
//   {}
//   2. std::pair<DenseTensorMeta, DenseTensorMeta> [OpName]InferShape(const
//   DenseTensorMeta&
//   x_meta, ...) {}
//   3. std::tuple<DenseTensorMeta, DenseTensorMeta, DenseTensorMeta>
//   [OpName]InferShape(const
//   DenseTensorMeta& x_meta, ...)
//  NOTE: The name "InferShape" may be not appropriate. "InferMeta" may be good.
//  Because functions in this file
//  not only can infer shape, but alse need infer lod or other useful data.

DenseTensorMeta UnchangedInferShape(const DenseTensorMeta& x_meta);

DenseTensorMeta ReductionInferShape(const DenseTensorMeta& x_meta);

DenseTensorMeta FlattenInferShape(const DenseTensorMeta& x_meta,
                                  int start_axis,
                                  int stop_axis);
DenseTensorMeta CastInferMeta(const DenseTensorMeta& x_meta,
                              const DataType out_dtype);

DenseTensorMeta FullLikeInferShape(const DenseTensorMeta& x_meta,
                                   DataType dtype,
                                   DataLayout layout);

DenseTensorMeta InferShapeFromVecValue(const DenseTensorMeta& x_meta,
                                       const std::vector<int64_t>& shape);
}  // namespace pten
