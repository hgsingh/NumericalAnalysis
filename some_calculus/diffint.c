#include <stdio.h>
#include <math.h>

#define h 1e-5
#define xmax 7
#define xmin 0
#define xstep 0.01

int main(void){
void differentiation(double (*f) (double));
void integration(double (*f) (double));
return 0;  
}

double f(double x){
 return cos(x); 
}

void differentiation(double (*f)(double)){
 double result, x;
 FILE *output;
 output = fopen("derivative.dat","w");
 for(x = xmin; x <=xmax; x =x+xstep){  
  fprintf(output, "%f\t", x);
  result = ((*f)(x+h)-(*f)(x))/h; //forward differentiation
  fprintf(output,"%.10f\t", result);
  result = ((*f)(x+h/2)-(*f)(x-h/2))/h; //central differentiation
  fprintf(output,"%.10f\t", result);
  }
}

void integration(double (*f)(double)){
  double result, x;
  FILE *output;
  output = fopen("integral.dat", "w");
  for(x=xmin; x<=xmax;x =x+xstep){
  fprintf(output, "%f\t", x);
  result = (*f)((x+h)/2)*(x+(x+h)); //rectangle rule
  fprintf(output,"%.10f\t", result);
  result = h*((*f)(x)+(*f)(x+h))/2; //midpoint
  fprintf(output,"%.10f\t", result);
  result = (h/2)*((*f)(x)+(*f)(x+h)+4*((*f)((2*x+h)/2))); //simpson
  fprintf(output,"%.10f\t", result);
 }
}