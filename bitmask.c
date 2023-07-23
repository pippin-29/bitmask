/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:29:33 by dhadding          #+#    #+#             */
/*   Updated: 2023/07/23 10:11:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

typedef unsigned int u32;

#define INLINE static inline

// Define Mask Macro
#define mask(...) ((u32)bitsetter(0, __VA_ARGS__, -1))

INLINE u32 bitsetter(u32 result, ...) {
    va_list args;
    va_start(args, result);

    u32 bit;
    while ((bit = va_arg(args, u32)) != (u32)-1) {
        result |= (1 << (bit));
    }

    va_end(args);
    return result;
}


// Example usage of the mask macro
#define TM_FREQ_64      mask(0)      // 0th bit set
#define TM_FREQ_1024    mask(1, 0)   // 0th and 1st bits set

int main() {
    // Testing the mask values
    printf("TM_FREQ_64 = %u\n", TM_FREQ_64);       // Output: TM_FREQ_64 = 1
    printf("TM_FREQ_1024 = %u\n", TM_FREQ_1024);   // Output: TM_FREQ_1024 = 3

    return 0;
}