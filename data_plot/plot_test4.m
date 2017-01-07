clear;
clc;
A = importdata('data.txt');
x = A(:,1);
y = A(:,2);
z = A(:,3);
plot3(x,y,z,'.');