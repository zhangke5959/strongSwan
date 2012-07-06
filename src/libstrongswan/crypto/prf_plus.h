/*
 * Copyright (C) 2005-2006 Martin Willi
 * Copyright (C) 2005 Jan Hutter
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup prf_plus prf_plus
 * @{ @ingroup crypto
 */

#ifndef PRF_PLUS_H_
#define PRF_PLUS_H_

typedef struct prf_plus_t prf_plus_t;

#include <crypto/prfs/prf.h>

/**
 * Implementation of the prf+ function used in IKEv1/IKEv2 keymat extension.
 */
struct prf_plus_t {

	/**
	 * Get pseudo random bytes.
	 *
	 * @param length	number of bytes to get
	 * @param buffer	pointer where the generated bytes will be written
	 * @return			TRUE if bytes generated successfully
	 */
	__attribute__((warn_unused_result))
	bool (*get_bytes) (prf_plus_t *this, size_t length, u_int8_t *buffer);

	/**
	 * Allocate pseudo random bytes.
	 *
	 * @param length	number of bytes to get
	 * @param chunk		chunk which will hold generated bytes
	 * @return			TRUE if bytes allocated successfully
	 */
	__attribute__((warn_unused_result))
	bool (*allocate_bytes) (prf_plus_t *this, size_t length, chunk_t *chunk);

	/**
	 * Destroys a prf_plus_t object.
	 */
	void (*destroy) (prf_plus_t *this);
};

/**
 * Creates a new prf_plus_t object.
 *
 * @param prf				prf object to use, must be destroyd after prf+.
 * @param counter			use an appending counter byte (for IKEv2 variant)
 * @param seed				input seed for prf
 * @return					prf_plus_t object, NULL on failure
 */
prf_plus_t *prf_plus_create(prf_t *prf, bool counter, chunk_t seed);

#endif /** PRF_PLUS_H_ @}*/
