% close all;
plot(t, dot_del_v.signals.values(:,2) ,'DisplayName','simout.signals.values');figure(gcf)
grid on;
xlabel('Time(s)');
ylabel('Rate-of-change of error in velocity(m/s^2)');

XData=get(get(gca,'children'),'XData');
YData=get(get(gca,'children'),'YData');
% Get y value for x=3.33 - NOT a data point.
y0 = interp1(XData,YData,4.99,'spline');
y1 = interp1(XData,YData,25.01,'spline');
y2 = interp1(XData,YData,29.99,'spline');
y3 = interp1(XData,YData,50.01,'spline');
S1_b1=y1-y0;
S1_b2=y3-y2;
gSF_x=(S1_b2+S1_b1)/(-2*pi*9.8*3.28)
aB_y=(S1_b2-S1_b1)/4
