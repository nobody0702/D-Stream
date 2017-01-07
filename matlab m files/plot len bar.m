y=[0.999 0.97;0.98 0.93; 0.95 0.896; 0.92 0.732];
b=bar(y);
grid on;
ch = get(b,'children');
set(gca,'XTickLabel',{'0.01','0.04','0.06','0.1'})
%set(ch,'FaceVertexCData',[1 0 1;0 0 0;])
legend('GC-Stream','D-Stream');
xlabel('len');
ylabel('precision');