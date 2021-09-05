%
% example4_9.m - Design and analysis of a butterworth filter
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

Wp = [100  200]/500;    % Passband frequencies
Ws = [50  250]/500;     % Stopband frequencies
Rp = 3;                 % Passband ripple
Rs = 30;                % Stopband attenuation
[N, Wn] = buttord(Wp, Ws, Rp, Rs); % Estimate filter order
[b, a] = butter(N, Wn);	% Design a Butterworth filter
fvtool(b, a);			% Analyze the designed IIR filter

