#include "libft.h"

int ft_tab_of_str_len(char** tab)
{
    int i = 0;

    while (tab[i])
        i++;

    return (i);
}