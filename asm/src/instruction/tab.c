/*
** tab.c for corewar in /home/lefebv_z//projet/corewar/asm/src
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri Feb  1 12:09:16 2013 marie lefebvre
** Last update Mon Feb  4 13:13:40 2013 marie lefebvre
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
