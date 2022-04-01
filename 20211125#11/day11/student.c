#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define flush(stream)    ((stream)->_IO_read_ptr = (stream)->_IO_read_end)
#define trimcrlf(string) ((string)[strcspn((string), "\r\n")] = 0)

typedef struct {
	int year;
	int mouth;
	int day;
} date_t;

typedef struct student {
	int             id;
	char            name[50];
	date_t          birth;
	double          score;
	struct student *next;
} student_t;

int main(int argc, const char *argv[])
{
	void       student_info_i(student_t *);
	void       student_info_o(student_t *);
	student_t *student_list_init(int);
	void       student_list_print(student_t *);

#if 0
	student_t example_student;
	student_info_i(&example_student);
	student_info_o(&example_student);
#else
	student_t *list = student_list_init(1);
	student_list_print(list);
	puts("");
#endif
}

void student_info_i(student_t *s)
{
	printf("Input ID: "), scanf("%d", &s->id), flush(stdin);
	printf("Input name: "), fgets(s->name, sizeof(s->name), stdin), trimcrlf(s->name), flush(stdin);
	printf("Input birthday (yyyy-mm-dd): "), scanf("%d %d %d", &s->birth.year, &s->birth.mouth, &s->birth.day),
		s->birth.mouth = abs(s->birth.mouth), s->birth.day = abs(s->birth.day), flush(stdin);
	printf("Input score: "), scanf("%le", &s->score), flush(stdin);
}

void student_info_o(student_t *s)
{
	printf("ID      : %d\n", s->id);
	printf("Name    : %s\n", s->name);
	printf("Birthday: %04d-%02d-%02d\n", s->birth.year, s->birth.mouth, s->birth.day);
	printf("Score   : %g\n", s->score);
}

student_t *student_list_init(int n)
{
	student_t *head = NULL, *node = NULL, *next = NULL;
	for (int i = 0; i < n; i++, next = node)
		node = (student_t *) malloc(sizeof(student_t)),
		student_info_i(node), puts(""),
		node->next = next, head = node;
	return head;
}

void student_list_print(student_t *s)
{
	if (s) puts("--------------------"),
		   student_info_o(s),
		   student_list_print(s->next);
}
