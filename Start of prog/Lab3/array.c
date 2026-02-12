#include <stdlib.h>
#include <stdio.h>
#include "array.h"
void mymemcpy(void *to, void *from, uint64_t len)
{har *destination = (char *)to;
char *origin = (char *)from;

for (uint8_t i = 0; i < len; i++)
{
destination[i] = origin[i];
}
}

void arr_init(array *arr_data)
{
void *ptr = calloc(arr_data->len, arr_data->type);
if (ptr != NULL)
{
arr_data->inited = 1;
}
arr_data->arr = ptr;
}
void arr_print(array arr)
{
for (uint64_t i = 0; i < arr.len; i++)
{
if (arr.type == int32)
{
printf(”%d ”, ((int32_t *)(arr.arr))[i]);
}
else
{
printf(”%lf ”, ((double *)(arr.arr))[i]);
}
}
printf(”\n”);
}
void arr_free(array* arr)
{
if (!arr->inited)
return;
free(arr->arr);
arr->len = 0;
arr->inited = 0;
arr->arr = NULL;
}

void arr_insert(array *arr, insert ins)
{
void *tmp = arr->arr;
arr->len++;
arr->arr = calloc(arr->len, arr->type);
mymemcpy(arr->arr, tmp, ins.index * arr->type);
//printf(”%ld %ld %d\n”,ins.index,arr->len,arr->type);
if (arr->type == int32)
{

int32_t val;
mymemcpy(&val, ins.value, 4);
((int32_t *)arr->arr)[ins.index] = val;
}
else
{
double val;
mymemcpy(&val, ins.value, 8);
((double *)arr->arr)[ins.index] = val;

}
mymemcpy(arr->arr + (ins.index + 1) * arr->type, tmp + ins.index * arr->type,
(arr->len - ins.index - 1) * arr->type);
free(tmp);
}

void arr_remove(array *arr, insert ins)
{
void *tmp = arr->arr;
arr->len--;
arr->arr = calloc(arr->len, arr->type);
mymemcpy(arr->arr, tmp, ins.index * arr->type);
mymemcpy(arr->arr + (ins.index) * arr->type, tmp + (ins.index+1) * arr->type,
(arr->len - ins.index) * arr->type);
free(tmp);
}
insert encodeInsert(uint64_t index,pass_value val){
insert ins;
ins.index=index;
mymemcpy(ins.value,&val,8);
88 return ins;
89 }
90 pass_value encodeInt32(int32_t val)
91 {
92 pass_value a;
93 mymemcpy(&a, &val, 4);
94 return a;
95 }
96 pass_value encodeDbl(double val)
97 {
98 pass_value a;
99 mymemcpy(&a, &val, 8);
100 return a;
101 }
102 int32_t decodeInt32(pass_value val)
103 {
104 int32_t a;
105 mymemcpy(&a, &val, 4);
106 return a;
107 }
108 double decodeDbl(pass_value val)
109 {
110 double a;
111 mymemcpy(&a, &val, 8);
112 return a;
113 }
114 insert encodeRemove(uint64_t index)
115 {
116 insert a;
117 a.index = index;
18
118 return a;
119 }
120 uint64_t arr_count(array *arr, pass_value val)
121 {
122 uint64_t counter = 0;
123 if (arr->type == int32)
124 {
125 int32_t value;
126 mymemcpy(&value, &val, 4);
127
128 for (uint64_t i = 0; i < arr->len; i++)
129 {
130 if (((int32_t *)(arr->arr))[i] == value)
131 {
132 counter++;
133 }
134 }
135 }
136 else if (arr->type == dbl)
137 {
138 double value;
139 mymemcpy(&value, &val, 8);
140
141 for (uint64_t i = 0; i < arr->len; i++)
142 {
143 if (((double *)(arr->arr))[i] == value)
144 {
145 counter++;
146 }
147 }
148 }
149 return counter;
150 }
151 void arr_clear(array *arr)
152 {
153 array tmp;
154 tmp.type = arr->type;
155 tmp.len = 0;
156 arr_init(&tmp);
157 arr_free(arr);
158 mymemcpy(arr, &tmp, sizeof(array));
159 }
160
161 void arr_pub(array *arr, pass_value val)
162 {
163 arr_insert(arr,encodeInsert(arr->len,val));
164 }