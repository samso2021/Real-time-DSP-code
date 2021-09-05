%
% example4_7.m - Find zeros, poles, and gain of IIR filter
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

b = [0.5, 0, -0.18];     % Numerator
a = [1, 0.1, -0.72];     % Denominator
[z, p, c] = tf2zp(b, a)  % Display zeros, poles, and gain
