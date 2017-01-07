clear;
clc;
A = importdata('output5.txt');
x = A(:,1);
y = A(:,2);
label = A(:,3);
color = {'.b';'.g';'.r';'.c';'.m';'.y';'.k'};
for i=1:1:size(x)
    plot(x(i),y(i),char(color(mod(label(i),7)+1)));
    hold on;
end
axis([0 300 0 200]);