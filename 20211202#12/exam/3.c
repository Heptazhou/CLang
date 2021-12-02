#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define trim(s) (s[strcspn(s, "\n")] = 0)

typedef struct {
	int year;
	int mouth;
	int day;
} date_t;

typedef struct student_record {
	char                   name[50];
	date_t                 birth;
	double                 marks;
	struct student_record *next;
} student_record_t;

int main()
{
	student_record_t *init(int);
	void              print(student_record_t *);

	student_record_t *list = init(12);
	print(list);
}

void student_i(student_record_t *s)
{
	printf("Input name: "), fgets(s->name, sizeof(s->name), stdin), trim(s->name);
	printf("Input birthday: "), scanf("%d %d %d", &s->birth.year, &s->birth.mouth, &s->birth.day);
	printf("Input marks: "), scanf("%le", &s->marks);
}

void student_o(student_record_t *s)
{
	printf("Name    : %s\n", s->name);
	printf("Birthday: %d-%d-%d\n", s->birth.year, s->birth.mouth, s->birth.day);
	printf("Marks   : %g\n", s->marks);
}

student_record_t *init(int n)
{
	student_record_t *head = NULL, *node, *next = NULL;
	for (int i = 0; i < n; i++, next = node)
		node = (student_record_t *) malloc(sizeof(student_record_t)),
		student_i(node), node->next = next, head = node;
	return head;
}

void print(student_record_t *s)
{
	if (s) student_o(s), print(s->next);
}
