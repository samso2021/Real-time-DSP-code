%
% example4_18.m - Design and analysis of a parametric equalizer
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

Fs = 10000;             % Sampling rate
f0 = 1500;              % Frequency in Hz
w0 = 2*pi*f0/Fs;
rz=0.8; rp=0.9;         % Define parameters
b=[1, -2*rz*cos(w0), rz*rz]; % Define numerator coefficints
a=[1, -2*rp*cos(w0), rp*rp]; % Define denominator coefficients
fvtool(b,a);            % Analyze the filter