#include "libft.h"

void ft_free_double_ptr(char** double_ptr)
{
    int i = 0;
    while (double_ptr[i])
    {
        free(double_ptr[i]);
        i++;
    }
    free(double_ptr);
}