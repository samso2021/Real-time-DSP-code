% 
%  Example 10.6 - MATLAB script for Shelf Filter Design
%  File name: ShelfFilter.m 
%
%  Description: Shelf Filter function
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

function [az,bz]= ShelfFilter(Fc, Gain, Slope, Fs, SfType)
format long

Wc = (2*pi*Fc)/Fs; % Angle from frequency
Wc = tan(Wc/2.0);
Wc2 = Wc*Wc;
% Normalized Gain
K = 10^(Gain/40);
K_ = sqrt(K);
K2= K*K;
Q = Slope;

% Coefficient Calculation
if SfType == 'L'
b0 = 1.0 + Wc*K_/Q + K*Wc2;
a0 = 1.0 + Wc/(K_*Q) + Wc2/K;
b1 = 2*(K*Wc2-1.0);
a1 = 2*(Wc2/K-1.0);
b2 = 1.0 - Wc*K_/Q + K*Wc2;
a2 = 1.0 - Wc/(K_*Q) + Wc2/K;
else
a0 = 1.0 + Wc*K_/Q + K*Wc2;
b0 = K2 + Wc*K*K_/Q + K*Wc2;
a1 = 2*(K*Wc2-1.0);
b1 = 2*(K*Wc2-K2);
a2 = 1.0 - Wc*K_/Q + K*Wc2;
b2 = K2 - Wc*K*K_/Q + K*Wc2;
end

az=[a0 a1 a2]/a0;
bz=[b0 b1 b2]/a0;

