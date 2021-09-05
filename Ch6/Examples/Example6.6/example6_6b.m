%
% example6_6b.m - Plot the error contours of MSE given in Example 6.6
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

clear;
[w0 w1]=meshgrid(-30:2:30,-24:2:24); % Define w0 and w1 arrays 
                                     %   for 3-D plots
error=0.34-0.6.*w0-w1+w0.*w0+w1.*w1; 
contour(w0(1,:),w1(:,1),error,15);   % Contour plot
axis('equal');
title('Error Contours'); 
xlabel('w0'); 
ylabel('w1');