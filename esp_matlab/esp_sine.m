%% 连接部分
t_client=tcpip('172.20.10.2',8888,'NetworkRole','client');%与本地主机建立连接，端口号为8888。手机热点
% t_client=tcpip('192.168.1.101',8888,'NetworkRole','client');%路由器
t_client.OutputBuffersize=100000;%设置最大缓冲区
fopen(t_client);%与一个服务器建立连接，直到建立完成返回，否则报错。
pause(1);%等待连接稳定，随意设置。
% 写入3个数 A w delta
N=8;
cmdn1=[45,70*pi/180,2*pi/(N-1),0];
cmd1=[];
for i=1:length(cmdn1)

    cmds1=strcat(num2str(cmdn1(i)),',');
    cmd1=[cmd1,cmds1]
end
fwrite(t_client,cmd1)%同时写20组数据 
% fprintf(t_client,'l');
% fprintf(t_client,'t');
% fprintf(t_client,'v');
% fprintf(t_client,'s');

%  fclose(t_client); clc;clear
