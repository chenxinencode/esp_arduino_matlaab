%% 连接部分
t_client=tcpip('172.20.10.2',8888,'NetworkRole','client');%与本地主机建立连接，端口号为8888。手机热点
% t_client=tcpip('192.168.1.101',8888,'NetworkRole','client');%路由器
t_client.OutputBuffersize=100000;%设置最大缓冲区
fopen(t_client);%与一个服务器建立连接，直到建立完成返回，否则报错。
pause(1);%等待连接稳定，随意设置。


%% 期望角度

A = 60;              % Degree Amplitude
T = 2;               % Period of Motion
w = 2*pi / T;        % Angular Frequency

stepsize = 0.1;     % stepsize for motion
t = 0:stepsize:5*T;  % sampling motion

th  = A*sin(w*t);  % Servo Position
dth = diff(th) ./ stepsize;  % Servo Angular Velocity



%% 写期望角度到arduino
%%主程序
for ind = 1:length(t)-1
    %t1 = tic;  % starting time
    t1=clock;
    dest_pos = degree_to_dxl(th(ind));  % 期望角度
    
    fprintf(t_client,dest_pos);
    fread(t_client, [1,t_client.BytesAvailable])
       
    
    
    
    %t2 = toc;  % ending time
    elapsed=etime(clock,t1);
    pause(stepsize - (elapsed - t1))
end
%% 
% fclose(t_client);clc;clear