%% 连接部分
t_client=tcpip('172.20.10.2',8888,'NetworkRole','client');%与本地主机建立连接，端口号为8888。手机热点
%  t_client=tcpip('192.168.124.12',8888,'NetworkRole','client');%路由器 由esp的串口得知
t_client.OutputBuffersize=100000;%设置最大缓冲区
fopen(t_client);%与一个服务器建立连接，直到建立完成返回，否则报错。
pause(1);%等待连接稳定，随意设置。
t_client.BytesAvailable
%% 

dt=0.1;%s
load('ff_smc_stra');
% ff=ff_pd;
servo=degree_to_dxl(ff(1:7,:));
% plot(servo7)
for i=1:size(servo,2)
   CMD=[];
   for j=1:size(servo,1)
       strr=strcat(num2str(servo(j,i)),',');
       CMD=[CMD strr];
   end
%    aaa=num2str(i);
%    CMD1=strcat(aaa,CMD);
   CMD2=strcat(CMD,';');
   cmdd(i,:)=CMD2;
end
dt=0.05;

%% 
tic
for i=1:100%size(servo,2)
    if i==size(servo,2)
        break;
    end
   fwrite(t_client,cmdd(i,:))

 pause(0.1)
%    pause(0.1)%matlab同步时间
end
toc

%  fclose(t_client); clc;clear
