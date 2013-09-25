/*
** my_putchar.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:52:58 2013 raphael defreitas
** Last update Sat Jan 26 00:51:24 2013 raphael defreitas
*/

#include	"my.h"

int		my_putchar(int c)
{
  return (my_fputchar(STD_OUTPUT, c));
}
