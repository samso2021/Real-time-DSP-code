% 
%  example10_5.m - MATLAB script for Peak Filter
%
%  Description: calculate Peak Filter coefficients and display magnitude
%  response
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

% function PeakFilter(Fc, Gain, Q,  Fs)
% Hz------------------^     ^   ^   ^
% dB------------------------|   |   |
% numerical---------------------|   |
% Hz--------------------------------|

[az1,bz1] = PeakFilter(4000,10,2,16000);
[az2,bz2] = PeakFilter(4000,5,2,16000);
[az3,bz3] = PeakFilter(4000,-5,2,16000);
[az4,bz4] = PeakFilter(4000,-10,2,16000);

fvtool(bz1,az1,bz2,az2,bz3,az3,bz4,az4);
title('Peak/Notch Filter (Fc=4/16, Q=2, Gain(dB)=10,5,-5,-10, Fs=16000)');
