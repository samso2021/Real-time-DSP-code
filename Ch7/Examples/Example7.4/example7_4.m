%
% example7_4.m - MATLAB code to generate square wave 
%                corrupted by white Gaussian noise (WGN)
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

t = 0:.1:20;
x = square(t);             % Create square signal
y = awgn(x,10,'measured'); % Add white Gaussian noise
plot(t,x,t,y)              % Plot both signals
legend('Original signal','Signal with AWGN');
