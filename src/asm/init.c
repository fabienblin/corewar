#include "asm.h"

// init de l'env global
void intit(void)
{
	g_env.op_tab = g_op_tab; // pour appeler op_tab depuis l'env
	g_env.ast = NULL; // potentiellement un t_ntree (voir libft)
	g_env.name = NULL; // ligne 1
	g_env.comment = NULL; // ligne 2
}
