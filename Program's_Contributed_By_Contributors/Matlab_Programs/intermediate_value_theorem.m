clc;
f=@(x) (x^2-2);
a=input('Enter value of a=');
b=input('Enter value of b=');
N=input('Enter value of N=');

h=(b-a)/N;
for i=1:N
    pr=f(a+(i-1)*h)*f(a+i*h);         
    if pr<0
        fprintf('Interval is %f %f \n',a+(i-1)*h,a+i*h);
    end
end
