function imu_data=read_data_from_esp(raw_imu_data)

    c_imu_data=char(raw_imu_data);
    str_imu_data='';
        for i=1:length(c_imu_data)
            str_imu_data=append(str_imu_data,c_imu_data(i));
        end
        str_imu_data
    como_pos=strfind(str_imu_data,',');
    fir=str2num(str_imu_data(1:como_pos(1)-1));
    sec=str2num(str_imu_data(como_pos(1)+1:como_pos(2)-1));
    thi=str2num(str_imu_data(como_pos(2)+1:como_pos(3)-1));
%     fou=str2num(str_imu_data(como_pos(3)+1:como_pos(4)-1));
%     imu_data=[fir;sec;thi;fou];
    imu_data=[fir;sec;thi];
end