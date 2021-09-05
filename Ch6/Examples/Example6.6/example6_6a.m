%
% example6_6a.m - Compute and plot the three-dimensional 
%                 error surface for L=2
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

clear;
[w0 w1]=meshgrid(-24:2:24,-24:2:24); % Define w0 and w1 arrays 
                                     %   for 3-D plots
error=0.34-0.6.*w0-w1+w0.*w0+w1.*w1; 
mesh(w0,w1,error);                   % Plot the mesh using where color
                                     %   is proportional to mesh height
grid on;                             % Add major grid lines
title('Error surface'); 
xlabel('w0'); 
ylabel('w1'); 
zlabel('MSE');