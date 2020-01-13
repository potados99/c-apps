/////////////////////////////////////////////////////////////////////////////////////////
// This code contains NVIDIA Confidential Information and is disclosed
// under the Mutual Non-Disclosure Agreement.
//
// Notice
// ALL NVIDIA DESIGN SPECIFICATIONS AND CODE ("MATERIALS") ARE PROVIDED "AS IS" NVIDIA MAKES
// NO REPRESENTATIONS, WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ANY IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
//
// NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. No third party distribution is allowed unless
// expressly authorized by NVIDIA.  Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2015-2016 NVIDIA Corporation. All rights reserved.
//
// NVIDIA Corporation and its licensors retain all intellectual property and proprietary
// rights in and to this software and related documentation and any modifications thereto.
// Any use, reproduction, disclosure or distribution of this software and related
// documentation without an express license agreement from NVIDIA Corporation is
// strictly prohibited.
//
/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file
 * <b>NVIDIA DriveWorks API: Core Exports</b>
 *
 * @b Description: This file defines DW core exports.
 */

/**
 * @defgroup core_exports_group Core Exports
 * @ingroup core_group
 *
 * Defines DW core exports.
 * @{
 */

#ifndef DW_CORE_EXPORTS_H__
#define DW_CORE_EXPORTS_H__

#include <dw/core/Config.h>

// clang-format off
#ifdef DW_STATIC
  #define DW_API_PUBLIC
  #define DW_API_LOCAL
#else
  #if defined _WIN32 || defined __CYGWIN__
    #ifdef DW_EXPORTS
      #ifdef __GNUC__
        #define DW_API_PUBLIC __attribute__ ((dllexport))
      #else
        #define DW_API_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
      #endif
    #else
      #ifdef __GNUC__
        #define DW_API_PUBLIC __attribute__ ((dllimport))
      #else
        #define DW_API_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
      #endif
    #endif
    #define DW_API_LOCAL
  #else
    #if __GNUC__ >= 4
      #define DW_API_PUBLIC __attribute__ ((visibility ("default")))
      #define DW_API_LOCAL  __attribute__ ((visibility ("hidden")))
    #else
      #define DW_API_PUBLIC
      #define DW_API_LOCAL
    #endif
  #endif
#endif

#ifdef __GNUC__
    #define DW_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
    #define DW_DEPRECATED __declspec(deprecated)
#else
    #pragma message("WARNING: DW_DEPRECATED not available for this compiler")
    #define DW_DEPRECATED
#endif

// clang-format on
/** @} */
#endif // DW_CORE_EXPORTS_H__
