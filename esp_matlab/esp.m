%% 连接部分
t_client=tcpip('172.20.10.2',8888,'NetworkRole','client');%与本地主机建立连接，端口号为8888。手机热点
% t_client=tcpip('192.168.1.101',8888,'NetworkRole','client');%路由器
t_client.OutputBuffersize=100000;%设置最大缓冲区
fopen(t_client);%与一个服务器建立连接，直到建立完成返回，否则报错。
pause(1);%等待连接稳定，随意设置。

%% 写入与读取部分 速度慢是因为网络速度慢
tic
i=1;j=1;
% time=clock;
% while etime(clock,time)<10
while i<10
    %开始读的标志
    fprintf(t_client,"5.7,150");
    while(t_client.BytesAvailable==0)%没有可读数据时等待
        t_client.BytesAvailable;
        j=j+1;
    end
    %读数据，并将读到的ascii码转为数字
    raw_imu_data=fread(t_client,t_client.BytesAvailable);
    imu_data=read_data_from_esp(raw_imu_data);
    imu(:,i)=imu_data;
	i=i+1

end
toc
%% 
% fclose(t_client);clc;clear