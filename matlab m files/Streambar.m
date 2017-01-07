y=[0.903 0.91;0.91 0.89; 0.976 0.954; 0.987 0.968;0.999 0.946];
b=bar(y);
grid on;
ch = get(b,'children');
set(gca,'XTickLabel',{'100','150','200','250','300'})
%set(ch,'FaceVertexCData',[1 0 1;0 0 0;])
legend('GC-Stream','D-STream');
xlabel('Stream(in time units) ');
ylabel('Precision');