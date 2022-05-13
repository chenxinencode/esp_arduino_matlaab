N=8;
% a=[45;70*pi/180;2*pi/(N-1);10];
a=[45;70*pi/180;2*pi/(N-1);0];
aaa=[];
for i=1:length(a)
    aa=strcat(num2str(a(i)),',')
    aaa=[aaa,aa];
end
aaaa=strcat(aaa,';')
fwrite(t_client,aaaa)