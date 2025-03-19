/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:55:01 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/18 21:16:14 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdarg.h>
// #include <ctype.h>
// #include <stdlib.h>
// #include <memory.h>

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t				i;
// 	unsigned char		*ptr;

// 	i = 0;
// 	ptr = (unsigned char *)b;
// 	while (i < len)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }

// // Pass the pointer + the size :

// void Init_With_0(int n, ...)
// {
//     va_list args;
//     va_start(args, n);
//     int index;
    
//     index = 0;
//     while (index < n)
//     {
//         void *ptr = va_arg(args, void*);
//         size_t size = va_arg(args, size_t);
//         ft_memset(ptr, 0, size);
//         index++;
//     }
//     va_end(args);
// }

// int main()
// {
//     int arr[3][4];
    
//     printf("%d\n", sizeof(arr));
//     Init_With_0(1, arr, sizeof(arr));
//     for (int i = 0; i < 3; ++i)
//         for (int j = 0; j < 4; ++j)
//             printf("%d\n", arr[i][j]);
//     return 0;
// }