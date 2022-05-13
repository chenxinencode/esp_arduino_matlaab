function [pos] = degree_to_dxl(value)
    max_pos = 1024;
    max_deg = 300;
    value=value*180/pi;%如果是弧度则需要
    pos = (round((max_pos - 1) * ((max_deg/2 + double(value))/max_deg), 0));
%     pos=(value+150)*1023/300;
    pos = min(max(pos, 0), 1023);
end