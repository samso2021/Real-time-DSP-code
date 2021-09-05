% 
%  Example 10.5 - MATLAB script for Peak Filter Design
%  File name: peakfilter.m 
%
%  Description: Peak Filter function
%  response
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

function [az,bz]= PeakFilter(Fc, Gain, Q, Fs)
% Hz-------------------------^     ^   ^   ^
% dB-------------------------------|   |   |
% numerical----------------------------|   |
% Hz---------------------------------------|
format long

Wc = (2*pi*Fc)/Fs; % Angle from frequency
Wc = tan(Wc/2.0);
Wc2 = Wc*Wc;

% Normalized Gain
K = 10^(Gain/40);

% Calculate H(z) coefficient
b0 = 1.0 + Wc*K/Q + Wc2;
a0 = 1.0 + Wc/(K*Q) + Wc2;
b1 = 2*Wc2-2.0;
a1 = b1;
b2 = 1.0 - Wc*K/Q + Wc2;
a2 = 1.0 - Wc/(K*Q) + Wc2;

% H(z) coefficient matrix
az=[a0 a1 a2]/a0;
bz=[b0 b1 b2]/a0;
