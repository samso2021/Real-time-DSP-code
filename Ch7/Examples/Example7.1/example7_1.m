%
% example7_1.m - MATLAB code for generation of 200 Hz 
%                sinewave with sampling rate 4 kHz 
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

close all; 
clear all
fs = 4000;              % Sampling rate is 4 kHz
f = 200;                % Frequency of sinewave
n = 0:1:fs/f-1;         % Time index n
xn = sin(2*pi*f*n/fs);  % Generate sinewave
plot(n,xn,'-o');grid on;% Plot with mark on samples
xlabel('Time index, n');
ylabel('Amplitude');