/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:02:53 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:11:00 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include <fcntl.h>
# define DOT_COR 778268530
# define OCT 8
# define SIZE_INT 4

typedef struct			s_reg
{
	long				val: REG_SIZE * 8;
}						t_reg;

typedef struct			s_free
{
	size_t				address;
	struct s_free		*next;
}						t_free;

typedef struct			s_process
{
	unsigned int		pc;
	unsigned long		nbr_live;
	unsigned long		end_op;
	t_reg				registre[REG_NUMBER + 1];
	int					carry;
	struct s_process	*next;
	int					flag;
	unsigned long		id;
}						t_process;

typedef struct			s_champion
{
	int					nbr;
	unsigned long		nb_live;
	unsigned int		num_proc;
	unsigned int		size;
	t_process			*lst_process;
	t_header			header;
}						t_champion;
/*
typedef struct			s_op
{
	char				*name;
	int					val_1;
	int					param[3];
	int					val_2;
	unsigned long		cycle;
	char				*comment;
	int					val_4;
	int					val_5;
}						t_op;
*/
typedef struct			s_var
{
	unsigned char		*vm;
	t_champion			tab_champion[MAX_PLAYERS];
	unsigned long		cycle;
	unsigned long		check_cycle;
	unsigned long		check_cycle_delta;
	unsigned long		check_max_check;
	unsigned int		nb_live;
	unsigned int		nb_champion;
	unsigned long		stop_corewar;
	unsigned long		dump_value;
	size_t				padding;
	unsigned int		pos_player;
	unsigned int		op_tab[17];
	unsigned int		last_live;
	t_free				*lst_free;
	unsigned int		t_params[2][3];
	unsigned int 		p_p;
	unsigned int		op_size;
	long				v;
	unsigned int		id_proc;
}						t_var;

int						create_vm(t_var *data, unsigned char **virtual_machine,
							size_t size_vm);
int						create_champion(t_var *data, unsigned int nbr,
							unsigned char *cor, unsigned int size);
int						cycle_management(t_var *data, unsigned long nb_dump);
int						cycle_to_die(t_var *data);
int						stop_corewar(t_var *data);
int						exec_program(t_var *data);

int		    		    print_dump(t_var *data);
void					ft_count_nbr_champs(int ac, char **av, t_var *data);
void					ft_check_arg(int ac, char **av, t_var *data);
void					ft_control_player(t_var *data, long player_nbr);
void					ft_read_dot_cor(char *av, long player_nbr, t_var *data,
							int pos);
void					*my_memalloc(t_free **lst_free, size_t size);
void					my_free(t_free **lst_free, size_t address);
void					my_auto_free(t_free **lst_free);
int						my_exit(t_free **lst_free, char *file, char *func,
							int line);

int						tab_opcode(t_var *data, t_process *p_process, int i);

int						opcode_add(t_var *data, t_process *p_process);
int						opcode_aff(t_var *data, t_process *p_process);
int						opcode_and(t_var *data, t_process *p_process);
int						opcode_fork(t_var *data, t_process *p_process, int i);
int						opcode_ld(t_var *data, t_process *p_process);
int						opcode_ldi(t_var *data, t_process *p_process);
int						opcode_lld(t_var *data, t_process *p_process);
int						opcode_lldi(t_var *data, t_process *p_process);
int						opcode_lfork(t_var *data, t_process *p_process, int i);
int						opcode_live(t_var *data, t_process *p_process);
int						opcode_or(t_var *data, t_process *p_process);
int						opcode_st(t_var *data, t_process *p_process);
int						opcode_sti(t_var *data, t_process *p_process);
int						opcode_sub(t_var *data, t_process *p_process);
int						opcode_xor(t_var *data, t_process *p_process);
int						opcode_zjmp(t_var *data, t_process *p_process);

int						t_process_create(t_var *data, t_process *p_process,
							int i, int idx);

int         			ft_params_opcode(t_var *data, t_process *pc,
							int dir_oct, int idx);
/*
**DEBUG START
*/
void		print_t_params(t_var *data);
/*
**DEBUG END
*/

#endif
