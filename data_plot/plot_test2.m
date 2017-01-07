len = 1000;
for i = 0:len/100:len
        line([i,i],[0,len]);
        line([0,len],[i,i]);
end
hold on;
clear;
clc;
A = importdata('data.txt');
x = A(:,1);
y = A(:,2);
plot(x,y,'.');
