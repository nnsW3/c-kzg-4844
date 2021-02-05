/*
 * Copyright 2021 Benjamin Edgington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h> // malloc, free
#include "c_kzg.h"
#include "blst_util.h"

typedef struct {
    blst_fr *coeffs; // coeffs[i] is the x^i term
    uint64_t length; // one more than the polynomial's degree
} poly;

void poly_init(poly *out, const uint64_t length);
void poly_free(poly p);
void poly_eval(blst_fr *out, const poly *p, const blst_fr *x);
uint64_t poly_quotient_length(const poly *dividend, const poly *divisor);
C_KZG_RET poly_long_div(poly *out, const poly *dividend, const poly *divisor);