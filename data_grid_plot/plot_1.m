clear;
clc;
A = importdata('output.txt');
xx = A(:,1);
x = xx*3+1.5;
yy = A(:,2);
y = yy*3+1.5;
d = A(:,3);
plot(x,y,'.');
len = 300;
for i = 0:len/100:len
        line([i,i],[0,len]);
        line([0,len],[i,i]);
end