#include<stdio.h>
#include<cs50.h>

void space(int p)
{
for(int k=0;k<p;k++)
printf(" ");
}

int main(void)
{
int height;
do {
printf("Height : ");
scanf("%d",&height);
}while((height<1)||(height>8));

int j; 


for(int i=0;i<height;i++)
{
space(n-i-1);

for(j=0;j<=i;j++)
{
printf("#");
}

space(2);

for(j=0;j<=i;j++)
{
printf("#");
}

printf("\n");

}
}
