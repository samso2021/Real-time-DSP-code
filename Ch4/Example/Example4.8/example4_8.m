%
% example4_8.m - MATLAB script for example 4.8
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

Wp = 800/4000;  % Passband frequency
Ws= 1600/4000;  % Stopband frequency
Rp = 1.0;       % Passband ripple
Rs = 20.0;      % Stopband attenuation

[N, Wn] = buttord(Wp, Ws, Rp, Rs); % First step
[b, a] = butter(N, Wn);            % Second step
freqz(b, a, 512, 8000);            % Display frequency response
