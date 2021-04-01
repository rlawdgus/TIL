#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
int h;

scanf("%d", &h);

for (int i = 0; i < h; i++) {
for (int j = 0; j < h; j++) {
if (i > j)
printf(" ");

else
printf("*");
}

printf("\n");
}

return 0;
}

/*int main() {
int h;

scanf("%d", &h);

for (int i = 0; i < h; i++) {
for (int j = 0; j < h; j++) {
if (i + j < h - 1)
printf(" ");

else
printf("*");
}

printf("\n");
}

return 0;
}*/

/*int main() {
int h;

scanf("%d", &h);

for (int i = 0; i < h; i++) {
for (int j = 0; j < h; j++) {
if (i >= j)
printf("*");
}

printf("\n");
}

return 0;
}*/

/*int main() {
int h;

scanf("%d", &h);

for (int i = 0; i < h; i++) {
for (int j = 0; j < h; j++) {
if (i <= j)
printf("*");
}

printf("\n");
}

return 0;
}*/