

// l'entrée est un fichier à explorer avec lseek

/* exemple de compilation :
.name "zork"
.comment "just a basic living prog"
l2: sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
# Executable compile:
#
# 0x0b,0x68,0x01,0x00,0x0f,0x00,0x01
# 0x06,0x64,0x01,0x00,0x00,0x00,0x00,0x01
# 0x01,0x00,0x00,0x00,0x01
# 0x09,0xff,0xfb
*/
int		parse(int fd)
{
	// off_t lseek(int fd, off_t offset, int whence);
	// chaque ligne/instruction est composée d'un label, d'un opcode et des paramètres
	// attention aux commentaires
	off_t	lsk;
	off_t	offset;

	lsk = NULL;
	offset = 1;
	while((lsk = lseek(fd, offset, SEEK_SET) > 0))
	{
		;
	}
	if (lsk == -1)
		ft_exit("lseek bug -1");
}
