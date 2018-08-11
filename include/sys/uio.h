/****************************************************************************
 * include/sys/uio.h
 *
 *   Copyright (C) 2017 Grefory Nutt. All rights reserved.
 *   Copyright (C) 2015 Stavros Polymenis. All rights reserved.
 *   Author: Stavros Polymenis <sp@orbitalfox.com>
 *           Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __INCLUDE_SYS_UIO_H
#define __INCLUDE_SYS_UIO_H

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct iovec
{
  FAR void *iov_base;
  size_t    iov_len;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: readv()
 *
 * Description:
 *   The readv() function is equivalent to read(), except as described below.
 *   The readv() function places the input data into the iovcnt buffers
 *   specified by the members of the iov array: iov[0], iov[1], ...,
 *   iov[iovcnt-1].  The iovcnt argument is valid if greater than 0 and less
 *   than or equal to IOV_MAX as defined in limits.h.
 *
 *   Each iovec entry specifies the base address and length of an area in
 *   memory where data should be placed.  The readv() function will always
 *   fill an area completely before proceeding to the next.
 *
 *   Upon successful completion, readv() will mark for update the st_atime
 *   field of the file.
 *
 * Input Parameters:
 *   filedes - The open file descriptor for the file to be read
 *   iov     - Array of read buffer descriptors
 *   iovcnt  - Number of elements in iov[]
 *
 * Returned Value:
 *   Upon successful completion, readv() will return a non-negative integer
 *   indicating the number of bytes actually read.  Otherwise, the functions
 *   will return -1 and set errno to indicate the error.  See read().
 *
 ****************************************************************************/

ssize_t readv(int fildes, FAR const struct iovec *iov, int iovcnt);

/****************************************************************************
 * Name: writev()
 *
 * Description:
 *   The writev() function is equivalent to write(), except as described
 *   below. The writev() function will gather output data from the iovcnt
 *   buffers specified by the members of the iov array: iov[0], iov[1], ...,
 *   iov[iovcnt-1]. The iovcnt argument is valid if greater than 0 and less
 *   than or equal to IOV_MAX, as defined in limits.h.
 *
 *   Each iovec entry specifies the base address and length of an area in
 *   memory from which data should be written. The writev() function always
 *   writes a complete area before proceeding to the next.
 *
 *   If fildes refers to a regular file and all of the iov_len members in
 *   the array pointed to by iov are 0, writev() will return 0 and have no
 *   other effect. For other file types, the behavior is unspecified.
 *
 *   If the sum of the iov_len values is greater than SSIZE_MAX, the
 *   operation will fail and no data will be transferred.
 *
 * Input Parameters:
 *   filedes - The open file descriptor for the file to be read
 *   iov     - Array of read buffer descriptors
 *   iovcnt  - Number of elements in iov[]
 *
 * Returned Value:
 *   Upon successful completion, writev() shall return the number of bytes
 *   actually written. Otherwise, it shall return a value of -1, the file-
 *   pointer shall remain unchanged, and errno shall be set to indicate an
 *   error.
 *
 ****************************************************************************/

ssize_t writev(int fildes, FAR const struct iovec *iov, int iovcnt);

#endif /* __INCLUDE_SYS_UIO_H */
