len = 1000;
for i = 0:len/100:len
        line([i,i],[0,len]);
        line([0,len],[i,i]);
end
hold on;
t = linspace(0,2*pi,1000);
x = 300+130*cos(t);
y = 500+200*sin(t);
plot(x,y);
hold on;
t = linspace(0,2*pi,1000);
x = 700+130*cos(t);
y = 500+200*sin(t);
plot(x,y);
hold on;
t = linspace(0,2*pi,1000);
x = 500+330*cos(t);
y = 500+280*sin(t);
plot(x,y);
hold on;