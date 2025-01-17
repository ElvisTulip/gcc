/* OpenACC Runtime Library: CUDA support glue.

   Copyright (C) 2014-2015 Free Software Foundation, Inc.

   Contributed by Mentor Embedded.

   This file is part of the GNU Offloading and Multi Processing Library
   (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include "openacc.h"
#include "config.h"
#include "libgomp.h"
#include "oacc-int.h"

void *
acc_get_current_cuda_device (void)
{
  void *p = NULL;

  if (base_dev && base_dev->openacc.cuda.get_current_device_func)
    p = base_dev->openacc.cuda.get_current_device_func ();

  return p;
}

void *
acc_get_current_cuda_context (void)
{
  void *p = NULL;

  if (base_dev && base_dev->openacc.cuda.get_current_context_func)
    p = base_dev->openacc.cuda.get_current_context_func ();

  return p;
}

void *
acc_get_cuda_stream (int async)
{
  void *p = NULL;

  if (async < 0)
    return p;

  if (base_dev && base_dev->openacc.cuda.get_stream_func)
    p = base_dev->openacc.cuda.get_stream_func (async);

  return p;
}

int
acc_set_cuda_stream (int async, void *stream)
{
  int s = -1;

  if (async < 0 || stream == NULL)
    return 0;

  goacc_lazy_initialize ();

  if (base_dev && base_dev->openacc.cuda.set_stream_func)
    s = base_dev->openacc.cuda.set_stream_func (async, stream);

  return s;
}
